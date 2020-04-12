// BattleTank by Mdelacruzmelo

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank; // Forward declaration

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

};
