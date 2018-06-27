// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))	// ovako mozemo dodati komponentu na tank_BP recimo
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Max force per track in N
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000;		// we assume a 40 tonne tank with 1g acceleration (40t * 9.81)
};
