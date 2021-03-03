// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MugPawn.generated.h"

UCLASS()
class COMPULSORY2_2021_API AMugPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMugPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	FVector MovementDirection;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MovementSpeed = 150.f;

	void MoveForward(float Value);
	void MoveRight(float Value);
};
