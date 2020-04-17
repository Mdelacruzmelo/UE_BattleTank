// BattleTank by Mdelacruzmelo

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Proyectile.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; //  TODO: should this tick?!
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (ensure(Barrel) || ensure(Turret)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);

		//UE_LOG(LogTemp, Warning, TEXT("AimSolution found"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("No AimSolution found"));
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
	// Work-out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("DeltaRotator: %s"), *DeltaRotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch); // TODO Remove magic number
	Turret->Rotate(DeltaRotator.Yaw); // TODO Remove magic number

}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel && ProyectileBlueprint)) { return; }
	bool isRealoaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isRealoaded)
	{
		// Spawn a prooyectile at the socket location
		auto Proyectile = GetWorld()->SpawnActor<AProyectile>(
			ProyectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Proyectile->LaunchProyectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}