// Fill out your copyright notice in the Description page of Project Settings.


#include "MugPawn.h"

// Sets default values
AMugPawn::AMugPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMugPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMugPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMugPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis(TEXT("MoveForward"), this, &AMugPawn::MoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &AMugPawn::MoveRight);

}

void AMugPawn::MoveForward(float Value) 
{
	MovementDirection.X = FMath::Clamp(Value, -1.0f, 1.0f);
}

void AMugPawn::MoveRight(float Value) 
{
	MovementDirection.Y = FMath::Clamp(Value, -1.0f, 1.0f);
}
