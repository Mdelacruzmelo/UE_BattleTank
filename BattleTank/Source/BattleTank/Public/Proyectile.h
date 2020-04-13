// BattleTank by Mdelacruzmelo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectile.generated.h"

UCLASS()
class BATTLETANK_API AProyectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
