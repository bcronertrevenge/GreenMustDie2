// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "TheBoss.generated.h"

/**
*
*/
class Interactive
{
public:
	virtual void Interact() = 0;
};
/**
*
*/

UCLASS()
class GREENMUSTDIE2_API ATheBoss : public ACharacter
{
	GENERATED_UCLASS_BODY()
		Interactive * currentObject;
	void SetCurrentObject(Interactive * pObject) { currentObject = pObject; };
	Interactive * GetCurrentObject() { return currentObject; };

	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void Interact();
	void MoveForward(float Value);
	void MoveRight(float Value);
};
