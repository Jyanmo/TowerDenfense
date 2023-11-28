 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


UENUM(BlueprintType)
enum class EDamageType :uint8
{
	None,
	Physical,
	Magical
};


UCLASS()
class TOWERDEFENSE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	
public:
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 Health;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 DamageMin;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 DamageMax;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 PhysicalArmor;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 MagicalArmor;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float AttackCoolDownTime;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 Speed;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EDamageType DamageType;



	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32 GetHealth();
};
