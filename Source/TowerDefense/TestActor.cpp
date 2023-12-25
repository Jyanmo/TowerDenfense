// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->SetUpdatedComponent(RootComponent);
	
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FlyToTarget();

}

void ATestActor::FlyToTarget()
{
	
	if (TargetActor)
	{
		FVector Direction;
		Direction = ((TargetActor->GetActorLocation() - GetActorLocation()));
		
		if (GEngine)GEngine->AddOnScreenDebugMessage(1, -1, FColor::Blue, FString::Printf(TEXT("Direction .Length():%f"), Direction.Length()));
		if (Direction .Length()<10.0f)
		{
			this->Destroy();
		}
		Direction.Normalize();
		ProjectileMovement->SetVelocityInLocalSpace(Direction*Speed);
	}
	else 
	{
		this->Destroy();

	}

	
}

