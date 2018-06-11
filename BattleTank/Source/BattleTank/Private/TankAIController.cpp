// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"		// MUST be included for GetWorld()->... to work properly. Otherwise: "pointer to incomplete class is not allowed"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found player: %s"), *PlayerTank->GetName());
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetPlayerTank()) { return; }

	// TODO Move towards the player

	// Aim towards the player
	GetPossessedTank()->AimAt(GetPlayerTank()->GetActorLocation());

	// Fire if ready
}

ATank* ATankAIController::GetPossessedTank()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();		// GetWorld() radi normalno

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}


