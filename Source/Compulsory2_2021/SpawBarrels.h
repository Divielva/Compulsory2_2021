// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "Engine/TriggerVolume.h"
#include "SpawBarrels.generated.h"



UCLASS()
class COMPULSORY2_2021_API ASpawBarrels : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawBarrels();

	void BarrelsDestroyed();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemies")
	int32 NumberOfBarrels{ 0 };

	UFUNCTION(BlueprintImplementableEvent)
	void PlayerWon();
	UFUNCTION(BlueprintImplementableEvent)
	void PlayerLost();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta = (AllowPrivateAccess = "True"))
		TSubclassOf<class ABarrelActor> EnemyToSpawn;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Settings", meta = (AllowPrivateAccess = "True"))
	ATriggerVolume* LoseTrigger;

	void SpawnEnemies();

	UFUNCTION()
	void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	
};
