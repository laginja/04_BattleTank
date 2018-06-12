// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 max downward speed and +1 max upward speed
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecons = 20;		
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;		

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;
};
