// Sebastian R Sletten

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class COMPULSORY2_2021_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//The mesh which is assigner inside the Unreal Editor
	UPROPERTY(VisibleAnywhere, Category = "Setup");
	USceneComponent* OurVisibleComponent{ nullptr };

	//speed, can be changed inside the editor, needed for movement
	UPROPERTY(EditAnywhere, Category = "Setup");
	float MoveSpeed{ 150.f };

	//static Camera
	UPROPERTY(EditAnywhere, Category = "Setup");
	class ACameraActor* TopDownCamera{ nullptr };

    UPROPERTY(VisibleAnywhere);
	UPawnMovementComponent* MovementComponent{ nullptr };

	//My bullet 
	UPROPERTY(EditAnywhere, Category = "Setup");
	TSubclassOf<class AMyBrewBullet> BulletBlueprint;


	//Collision for our the object, its a box
	UPROPERTY(VisibleAnywhere);
	class UBoxComponent* CollisionComponent;

	//SpawnPoint of my actor
	UPROPERTY(EditAnywhere, Category = "Setup");
	FVector SpawnPoint{ 100.f, 0.f, 100.f };

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Functions for movement and shooting
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Shoot();

	// The movement that will be applied to the next tick
	FVector CurrentVelocity{ 0.f };

};
