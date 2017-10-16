// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealMathUtility.h"
#include "BadSquare.generated.h"


UCLASS(config=Game)
class SAMMYSGREATADVENTURE_API ABadSquare : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABadSquare();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Timer for different states
	int stateTimer;

	// Speed variables for movement input.
	float maxSpeed;
	float speed;

	// Turn direction for StateWalkForwardTurning.
	float turn;

public:	

	// Wait for stateTimer to run out without moving.
	void StateWait();

	// Walk forward, picking up speed.
	void StateWalkForward();

	// Walk and turn.
	void StateWalkForwardTurning();

	// Randomly set the next state.
	void SetNextState();


	// Enemy state
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BadSquare")
	int enemyState;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BadSquare")
	float BaseTurnRate;

	/** Move the Bad Square forward or backward. */
	void MoveForward(float Value, float Turn);
	
};
