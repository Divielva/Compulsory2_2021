// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Camera/CameraActor.h"

#include "Engine/CollisionProfile.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "MyBrewBullet.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	//Makes the collision actually work ingame
	CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	RootComponent = CollisionComponent;


	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("PawnMovementComponent"));
	MovementComponent->UpdatedComponent = CollisionComponent;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetViewTarget(TopDownCamera);
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);*/

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPawn::Shoot);
}

void AMyPawn::MoveForward(float Value) {

	AddMovementInput(FVector::ForwardVector, Value * GetWorld()->GetDeltaSeconds() * MoveSpeed);

	/*CurrentVelocity.X = value * MoveSpeed;*/
}

void AMyPawn::MoveRight(float Value) {

	AddMovementInput(FVector::RightVector, Value * GetWorld()->GetDeltaSeconds() * MoveSpeed);

	/*CurrentVelocity.y = value * MoveSpeed;*/
}

void AMyPawn::Shoot() {

	UE_LOG(LogTemp, Warning, TEXT("Bang!"))

	//Gets pointer to the gameworld
	UWorld* World = GetWorld();

	if (World) 
	{
		//spawns Bullet at player Location + spawnpoint
		World->SpawnActor<AMyBrewBullet>(BulletBlueprint, GetActorLocation() + SpawnPoint, GetActorRotation());
	}
}