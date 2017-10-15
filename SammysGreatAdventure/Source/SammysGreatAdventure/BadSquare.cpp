// Fill out your copyright notice in the Description page of Project Settings.

#include "BadSquare.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ABadSquare::ABadSquare()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	stateTimer = 1000;
	enemyState = 0; // wait
	direction = 1;
}

// Called when the game starts or when spawned
void ABadSquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABadSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (stateTimer > 0)
	{
		switch (enemyState)
		{
		case 0:
			StateWait();
			break;
		case 1:
			StateWalkForward();
			break;
		case 2:
			StateWalkForwardTurning();
			break;
		default:
			break;
		}
	}
	else {
		switch (enemyState)
		{
		case 0:
			enemyState = 1;
			stateTimer = 100;
			break;
		case 1:
			enemyState = 2;
			stateTimer = 100;
			break;
		case 2:
			enemyState = 0;
			stateTimer = 1000;
			break;
		default:
			enemyState = 0;
			break;
		}
	}
}


void ABadSquare::StateWait()
{
	stateTimer--;
}

void ABadSquare::StateWalkForward()
{
	stateTimer--;
	MoveForward(1);
}

void ABadSquare::StateWalkForwardTurning()
{
	stateTimer--;
	MoveForward(1);
	TurnAtRate(0.5 * direction);
}

void ABadSquare::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABadSquare::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}