// BattleTank by Mdelacruzmelo


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	if (!RelativeSpeed) { return; }

	//UE_LOG(LogTemp, Warning, TEXT("Barrel throws an Elevate speed of %f"), RelativeSpeed);

	// Given a max elevation speed and the frame time


}