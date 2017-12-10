// Fill out your copyright notice in the Description page of Project Settings.

#include "BadSquare_AIController.h"
#include "BadSquare.h"



ABadSquare_AIController::ABadSquare_AIController()
{
	// Initialize sensing component
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);
}


void ABadSquare_AIController::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ABadSquare_AIController::OnSeePlayer);
	}
}

// Bad square saw the player.
void ABadSquare_AIController::OnSeePlayer(APawn* Pawn)
{
	Cast<ABadSquare>(GetPawn())->Chasing = Pawn;
}