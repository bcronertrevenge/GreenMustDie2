// Fill out your copyright notice in the Description page of Project Settings.

#include "GreenMustDie2.h"
#include "TurretCreator.h"


ATurretCreator::ATurretCreator(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}



void ATurretCreator::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("turret creator"));
	}
}

void ATurretCreator::displayMessage()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("displayMessage"));
}

void ATurretCreator::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Fire"));

}

void ATurretCreator::ReceiveActorBeginOverlap(AActor* OtherActor)
{
	Super::ReceiveActorBeginOverlap(OtherActor);
	if (OtherActor->GetName() == "")
	{
	}
	auto text = OtherActor->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, OtherActor->GetName());
	ATheBoss * theBoss = (ATheBoss*)OtherActor;
	theBoss->SetCurrentObject(this);
}

void ATurretCreator::ReceiveActorEndOverlap(AActor* OtherActor)
{
	Super::ReceiveActorEndOverlap(OtherActor);
	if (OtherActor->GetName() == "")
	{
	}
	ATheBoss * theBoss = (ATheBoss*)OtherActor;
	if (theBoss->GetWorld() == nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "theBoss->GetWorld() is null");
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "theBoss->GetWorld() is NOT null");
	theBoss->SetCurrentObject(nullptr);
	UE_LOG(LogTemp, Warning, TEXT("toto"));
}

void ATurretCreator::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "Interact");
	if (instanciatedTower == nullptr)
	{
		auto tempLoc = GetActorLocation();
		auto tempRot = GetActorRotation();
		auto world = GetWorld();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "Turret Creation");
		instanciatedTower = world->SpawnActor<ATower>(MyTower, tempLoc, tempRot);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "Turret has already been created");
	}
}