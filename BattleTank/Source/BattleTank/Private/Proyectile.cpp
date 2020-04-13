// BattleTank by Mdelacruzmelo


#include "Proyectile.h"

// Sets default values
AProyectile::AProyectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProyectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

