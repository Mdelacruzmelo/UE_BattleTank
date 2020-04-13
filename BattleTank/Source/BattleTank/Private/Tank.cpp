// BattleTank by Mdelacruzmelo

#include "Public/Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Public/TankBarrel.h"
#include "Public/Proyectile.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protet points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!Barrel) { return; }

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
}