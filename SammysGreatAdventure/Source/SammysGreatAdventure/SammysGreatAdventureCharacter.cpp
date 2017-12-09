// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SammysGreatAdventureCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// ASammysGreatAdventureCharacter

ASammysGreatAdventureCharacter::ASammysGreatAdventureCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Attacking variables
	Attacking = false;
	AttackTimer = 0.0f;

	// Set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Not sprinting by default.
	Sprinting = false;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASammysGreatAdventureCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Punch", IE_Pressed, this, &ASammysGreatAdventureCharacter::Attack);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASammysGreatAdventureCharacter::SprintOn);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ASammysGreatAdventureCharacter::SprintOff);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASammysGreatAdventureCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASammysGreatAdventureCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASammysGreatAdventureCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASammysGreatAdventureCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASammysGreatAdventureCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASammysGreatAdventureCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ASammysGreatAdventureCharacter::OnResetVR);
}

void ASammysGreatAdventureCharacter::Attack()
{
	if (!Attacking && GetCharacterMovement()->MovementMode != EMovementMode::MOVE_Falling)
	{
		Attacking = true;
		AttackTimer = 2.5f;
		if (Sprinting)
		{
			AttackTimer = 3.f;
			GetCharacterMovement()->Velocity.Z = 200.f;
			GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);
		}
	}
}

void ASammysGreatAdventureCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AttackTimer > 0)
	{
		AttackTimer -= 10 * DeltaTime;
		Attacking = true;
	}
	else
		Attacking = false;
}

void ASammysGreatAdventureCharacter::SprintOn()
{
	Sprinting = true;
}

void ASammysGreatAdventureCharacter::SprintOff()
{
	Sprinting = false;
}

void ASammysGreatAdventureCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ASammysGreatAdventureCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ASammysGreatAdventureCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ASammysGreatAdventureCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	if (!Attacking)
		AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASammysGreatAdventureCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASammysGreatAdventureCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f) && (!Attacking))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value * (Sprinting ? 1.0f : 0.75f));
	}
}

void ASammysGreatAdventureCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) && (!Attacking))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value * (Sprinting ? 1.0f : 0.75f));
	}
}
