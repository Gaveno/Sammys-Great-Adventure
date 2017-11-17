// Fill out your copyright notice in the Description page of Project Settings.

#include "BadSquare.h"
#include "Components/CapsuleComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"

#define TURN_RATE	4.0f
#define TIME_WALK	200
#define TIME_WALKT	100
#define TIME_WAIT	300
#define TIME_VAR	100
#define WALK_SPEED	0.5f
#define WALKT_SPEED 0.3f

#define STATE_WAIT	0
#define STATE_WALK	1
#define STATE_WALKT	2

// Sets default values
ABadSquare::ABadSquare()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	stateTimer = 100;
	enemyState = 0; // wait
	turn = 10.0f;
	maxSpeed = 100.0f;
	speed = 0.0f;

	Dying = false;
	DeathTimer = 8.0f;
}

// Called when the game starts or when spawned
void ABadSquare::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABadSquare::SetNextState()
{
	int nextState = FMath::RandRange((int)STATE_WAIT, (int)STATE_WALKT);
	switch (nextState)
	{
	case STATE_WAIT:
		enemyState = STATE_WAIT;
		stateTimer = TIME_WAIT;
		break;
	case STATE_WALK:
		enemyState = STATE_WALK;
		stateTimer = TIME_WALK;
		break;
	case STATE_WALKT:
		turn = FMath::RandRange(-TURN_RATE, TURN_RATE);
		enemyState = STATE_WALKT;
		stateTimer = TIME_WALKT;
		break;
	default:
		enemyState = 0;
		break;
	}
	stateTimer += FMath::RandRange(0, TIME_VAR);
}

// Called every frame
void ABadSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	stateTimer -= 10.0f * DeltaTime;
	if (stateTimer > 0)
	{
		switch (enemyState)
		{
		case 0:
			StateWait(DeltaTime);
			break;
		case 1:
			StateWalkForward(DeltaTime);
			break;
		case 2:
			StateWalkForwardTurning(DeltaTime);
			break;
		default:
			break;
		}
	}
	else {
		SetNextState();
	}

	if (Dying)
		DeathTimer -= 10 * DeltaTime;
}


void ABadSquare::StateWait(float DeltaTime)
{
	if (speed > 0)
	{
		MoveForward(speed, 0);
		speed -= DeltaTime;
	}
}

void ABadSquare::StateWalkForward(float DeltaTime)
{
	if (speed < WALK_SPEED)
	{
		speed += DeltaTime;
	}
	MoveForward(speed, 0);
}

void ABadSquare::StateWalkForwardTurning(float DeltaTime)
{
	if (speed < WALKT_SPEED)
	{
		speed += 0.01;
	}
	MoveForward(speed, turn);
}

void ABadSquare::MoveForward(float Value, float Turn)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw + Turn, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}