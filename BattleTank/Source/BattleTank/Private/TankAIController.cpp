// BattleTank by Mdelacruzmelo

#include "BattleTank.h"
#include "Engine/World.h"
#include "Public/TankAIController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ControlledTank && PlayerTank) {

		// Move towards the player
		MoveToActor(PlayerTank,AcceptanceRadius);

		// Aim toaerds the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire(); // TODO: Limit firing rate

	}

}