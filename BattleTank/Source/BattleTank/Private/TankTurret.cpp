// BattleTank by Mdelacruzmelo

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	if (!RelativeSpeed) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Barrel throws an Elevate speed of %f"), RelativeSpeed);

	// Move the barrel the right amount this frame
	// Given a max elevation speed and the frame time

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));

}