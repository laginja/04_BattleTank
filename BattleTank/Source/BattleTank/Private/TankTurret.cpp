// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// Givenn a max rotation speed and the frame time

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;		// izracunaj pomak turreta
	auto Rotation = RelativeRotation.Yaw + RotationChange;											// dodaj pomak trenutnoj rotaciji turret
	
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

