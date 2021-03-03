// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawBarrels.h"

#include "BarrelActor.h"

// Sets default values
ASpawBarrels::ASpawBarrels()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawBarrels::BarrelsDestroyed()
{
	NumberOfBarrels--;
	if (NumberOfBarrels == 0)
	{
		PlayerWon();
	}
}


// Called when the game starts or when spawned
void ASpawBarrels::BeginPlay()
{
	Super::BeginPlay();

	if (LoseTrigger)
	{
		LoseTrigger->OnActorBeginOverlap.AddDynamic(this, &ASpawBarrels::BeginOverlap);
	}

	SpawnEnemies();

}

void ASpawBarrels::SpawnEnemies()
{
	FVector SpawnLocation{ GetActorLocation() };

	for (int i = 0; i < 5; i++)
	{
		SpawnLocation.X = GetActorLocation().X;
		for (int j = 0; j < 5; j++)
		{
			ABarrelActor* TempEnemy = GetWorld()->SpawnActor<ABarrelActor>(EnemyToSpawn, SpawnLocation, GetActorRotation());
			TempEnemy->SetOwner(this);

			//add 200 to spawnlocation
			SpawnLocation.X += 400.f;
			NumberOfBarrels++;
		}
		SpawnLocation.Y += 500;
	}
}

void ASpawBarrels::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(ABarrelActor::StaticClass())) 
	{
		PlayerLost();
		UE_LOG(LogTemp, Warning, TEXT("OOga booga you lost"));
	}
	
}

