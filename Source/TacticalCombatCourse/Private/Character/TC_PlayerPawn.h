#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TC_PlayerPawn.generated.h"

UCLASS()
class ATC_PlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	ATC_PlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
