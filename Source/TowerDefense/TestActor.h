// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TestActor.generated.h"




UCLASS()
class TOWERDEFENSE_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
    UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Movement)
	UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Movement)
	AActor* TargetActor;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Movement)
	float Speed;
public:
	UFUNCTION(BlueprintCallable)
	void FlyToTarget();

};
