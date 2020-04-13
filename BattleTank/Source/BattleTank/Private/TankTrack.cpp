// BattleTank by Mdelacruzmelo


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%f throttle: %f "), *Name, Throttle);

	// TODO: clamp actual throttle value so player can't over-drive

}