// BattleTank by Mdelacruzmelo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
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

	void LaunchProyectile(float Speed);

private:

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float DestroyDelay = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ProjectileDamage = 20.f;

	UProjectileMovementComponent* ProyectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URadialForceComponent* ExplosionForce = nullptr;

};
