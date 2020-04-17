// BattleTank by Mdelacruzmelo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Public/Proyectile.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"
#include "Tank.generated.h" // Put new includes above

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProyectile> ProyectileBlueprint;

	

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3.f;

	// Local barrel reference for spawning proyectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;

};
