// BattleTank by Mdelacruzmelo

#include "BattleTank.h"
#include "Engine/World.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerPawn = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Possessing %s"), *ControlledTank->GetName());
	}

	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find a PlayerTank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank is: %s"), *PlayerPawn->GetName());
	}

	//UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerPawn);
}