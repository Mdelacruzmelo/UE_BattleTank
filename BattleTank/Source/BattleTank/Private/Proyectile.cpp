// BattleTank by Mdelacruzmelo


#include "Proyectile.h"

// Sets default values
AProyectile::AProyectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProyectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Proyectile Movement"));
	ProyectileMovement->bAutoActivate = false;
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

void AProyectile::LaunchProyectile(float Speed)
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f Projectile spawned!"), Time);
	ProyectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProyectileMovement->Activate();
}

