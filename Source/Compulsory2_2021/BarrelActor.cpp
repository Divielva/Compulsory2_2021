//Sebastian R Sletten i guess
//Though large parts of my code was made during class, and ive followed the guidelines

#include "BarrelActor.h"

#include "SpawBarrels.h"


// Sets default values
ABarrelActor::ABarrelActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

void ABarrelActor::HandleDestruction()
{
	Cast<ASpawBarrels>(GetOwner())->BarrelsDestroyed();
	Destroy();
}

// Called when the game starts or when spawned
void ABarrelActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FRotator CurrentRotation = GetActorRotation();
	//CurrentRotation.Yaw += RotateSpeed * DeltaTime;
	//SetActorRotation(CurrentRotation);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += GetActorForwardVector() * MoveSpeed * DeltaTime;
	SetActorLocation(CurrentLocation);

}

void ABarrelActor::ImHit() {

	UE_LOG(LogTemp, Warning, TEXT("I am actually hit!"))

		HandleDestruction();
    

	
}

