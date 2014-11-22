// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tower.h"
#include "GameFramework/Actor.h"
#include "TurretCreator.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, config = Game, BlueprintType)
class GREENMUSTDIE2_API ATurretCreator : public AActor, public Interactive
{
public:
	GENERATED_UCLASS_BODY()

		virtual	void ReceiveActorBeginOverlap(AActor* OtherActor) override;
	virtual void ReceiveActorEndOverlap(AActor* OtherActor) override;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Attachment)
		void displayMessage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		float health;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Fire();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Object")
		TSubclassOf < class ATower > MyTower;
	ATower * instanciatedTower;

	virtual void Interact();
};
