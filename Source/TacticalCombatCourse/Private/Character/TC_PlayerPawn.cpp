#include "Character/TC_PlayerPawn.h"

ATC_PlayerPawn::ATC_PlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATC_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATC_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATC_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

