// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BadSquare_AIController.generated.h"

/**
 * 
 */
UCLASS()
class SAMMYSGREATADVENTURE_API ABadSquare_AIController : public AAIController
{
	GENERATED_BODY()

public:

	ABadSquare_AIController();

	// Sensing component to see player.
	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UPawnSensingComponent* PawnSensingComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called when the bad square sees the player.
	void OnSeePlayer(APawn* Pawn);
};
