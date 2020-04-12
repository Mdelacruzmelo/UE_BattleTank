// BattleTank by Mdelacruzmelo

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward movement, and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0.f;

};
