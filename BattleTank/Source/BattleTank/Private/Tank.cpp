// BattleTank by Mdelacruzmelo

#include "Public/Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->Initialise(BarrelToSet, TurretToSet);
	Barrel = BarrelToSet;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(!TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isRealoaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (!ensure(Barrel)) { return; }

	if (isRealoaded)
	{
		auto SocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto SocketRotation = Barrel->GetSocketRotation(FName("Projectile"));
		FActorSpawnParameters SpawnInfo;

		// Spawn a prooyectile at the socket location
		auto Proyectile = GetWorld()->SpawnActor<AProyectile>(
			ProyectileBlueprint,
			SocketLocation,
			SocketRotation,
			SpawnInfo
			);

		Proyectile->LaunchProyectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();

	}
}