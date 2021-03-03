// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBrewBullet.h"
#include "Components/SphereComponent.h"
#include "BarrelActor.h"

// Sets default values
AMyBrewBullet::AMyBrewBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OurCollider = CreateDefaultSubobject<USphereComponent>(TEXT("MyCollider"));
	RootComponent = OurCollider;


	//Getting the visual mesh attached
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyBrewBullet::BeginPlay()
{
	Super::BeginPlay();
	
	Cast<USphereComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &AMyBrewBullet::OnOverlap);
	
}

// Called every frame
void AMyBrewBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeLived += DeltaTime;
	if (TimeLived > TimeBeforeDestroy) 
	{
		this->Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destroyed"))
	}

	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(NewLocation);

}

void AMyBrewBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult) 
{
	UE_LOG(LogTemp, Warning, TEXT("Bullet overlap %s"), *OtherActor->GetName())

		UE_LOG(LogTemp, Warning, TEXT("Bullet Hit Something"))
	
	
	
	if (OtherActor->IsA(ABarrelActor::StaticClass()))
	{
		
		Cast<ABarrelActor>(OtherActor)->ImHit();

		//Destroy Bullet
		Destroy();
	}
}

