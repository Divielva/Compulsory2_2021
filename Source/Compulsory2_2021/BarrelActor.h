// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrelActor.generated.h"

UCLASS()
class COMPULSORY2_2021_API ABarrelActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrelActor();

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere);
	UStaticMeshComponent* OurVisibleComponent{ nullptr };

	//UPROPERTY(EditAnywhere, Category = "Speed")
	//	float RotateSpeed{ 50.f };
	UPROPERTY(EditAnywhere, Category = "Speed")
		float MoveSpeed{ 150.f };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ImHit();

};
