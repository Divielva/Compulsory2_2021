// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMug.h"

// Sets default values
AMyMug::AMyMug()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyMug::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyMug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyMug::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

