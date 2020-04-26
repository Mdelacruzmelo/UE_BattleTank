// BattleTank by Mdelacruzmelo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:
	// Called by the engine when actor damage is dealt
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInsigator,
		AActor* DamageCauser
	);

	// Sets default values for this pawn's properties
	ATank();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingtHealth = 100;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
		int32 CurrentHealth = StartingtHealth;

};
