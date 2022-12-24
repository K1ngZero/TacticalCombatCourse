#include "Player/Components/TC_PlayerSpringArmComponent.h"

void UTC_PlayerSpringArmComponent::BeginPlay()
{
	Super::BeginPlay();

	DesiredArmLength = TargetArmLength;
}

void UTC_PlayerSpringArmComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TargetArmLength = FMath::FInterpTo(TargetArmLength, DesiredArmLength, DeltaTime, SmoothArmLengthSpeed);
}

void UTC_PlayerSpringArmComponent::SetDesiredArmLength(float InNewLength)
{
	DesiredArmLength = FMath::Clamp(InNewLength, MinDesiredArmLength, MaxDesiredArmLength);
}

void UTC_PlayerSpringArmComponent::AddDesiredArmLength(float InLengthOffset)
{
	SetDesiredArmLength(DesiredArmLength + InLengthOffset);
}