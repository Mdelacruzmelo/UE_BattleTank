// BattleTank by Mdelacruzmelo


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the right amount this frame
	if (!DegreesPerSecond) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Barrel_Elevate"));

	// Given a max elevation speed and the frame time


}