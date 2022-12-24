#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TC_PlayerController.generated.h"

UCLASS()
class ATC_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
