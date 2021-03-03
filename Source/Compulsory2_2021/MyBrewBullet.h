// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBrewBullet.generated.h"

UCLASS()
class COMPULSORY2_2021_API AMyBrewBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBrewBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//speed of the bullet
	UPROPERTY(EditAnywhere, Category = "Setup")
		float Speed{ 500.f };

	//We destroy the bullets after 5 seconds
	UPROPERTY(EditAnywhere, Category = "Setup")
		float TimeBeforeDestroy{ 6.f };
	
	float TimeLived{ 0 };


	//the Bullets collider which can be edited in the Editor
    UPROPERTY(EditAnywhere, Category = "Setup");
	class USphereComponent* OurCollider{ nullptr };

	//the Visual mesh of the actor
	UPROPERTY(EditAnywhere, Category = "Setup");
	class UStaticMeshComponent* OurVisibleComponent{ nullptr };


	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
