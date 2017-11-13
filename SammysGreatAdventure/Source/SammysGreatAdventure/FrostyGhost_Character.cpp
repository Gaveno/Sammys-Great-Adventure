// Fill out your copyright notice in the Description page of Project Settings.

#include "FrostyGhost_Character.h"


// Sets default values
AFrostyGhost_Character::AFrostyGhost_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Thinking = false;
	ThinkTimer = 0;
	Attacking = false;
}

// Called when the game starts or when spawned
void AFrostyGhost_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFrostyGhost_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFrostyGhost_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

