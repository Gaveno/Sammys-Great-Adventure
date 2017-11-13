// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FrostyGhost_Character.generated.h"

UCLASS()
class SAMMYSGREATADVENTURE_API AFrostyGhost_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFrostyGhost_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Whether or not the ghost is thinking
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FrostyGhost")
	bool Thinking;

	// Timer to wait thinking
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FrostyGhost")
	int32 ThinkTimer;

	// Whether or not the ghost is attacking
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FrostyGhost")
	bool Attacking;
	
};
