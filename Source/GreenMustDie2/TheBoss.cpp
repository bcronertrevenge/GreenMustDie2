// Fill out your copyright notice in the Description page of Project Settings.

#include "GreenMustDie2.h"
#include "TheBoss.h"


ATheBoss::ATheBoss(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP), currentObject(nullptr)
{
}

void ATheBoss::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	ACharacter::SetupPlayerInputComponent(InputComponent);
	check(InputComponent);
	InputComponent->BindKey(EKeys::T, IE_Pressed, this, &ATheBoss::Interact);
	InputComponent->BindAxis("MoveForward", this, &ATheBoss::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATheBoss::MoveRight);
	InputComponent->BindAxis("Turn", this, &ATheBoss::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &ATheBoss::AddControllerPitchInput);
}

void ATheBoss::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (CharacterMovement->IsMovingOnGround() || CharacterMovement->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ATheBoss::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
void ATheBoss::Interact()
{
	if (currentObject != nullptr)
	{
		currentObject->Interact();
	}
}
