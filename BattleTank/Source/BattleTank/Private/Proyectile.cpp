// BattleTank by Mdelacruzmelo


#include "Proyectile.h"

// Sets default values
AProyectile::AProyectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(true);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProyectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Proyectile Movement"));
	ProyectileMovement->bAutoActivate = false;

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//ImpactBlast->bAutoActivate = false;
	ProyectileMovement->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProyectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProyectile::OnHit);
}

void AProyectile::LaunchProyectile(float Speed)
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f Projectile spawned!"), Time);
	ProyectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProyectileMovement->Activate();
}

void AProyectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	LaunchBlast->Deactivate();
}