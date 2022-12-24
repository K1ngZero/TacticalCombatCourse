#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "TC_PlayerPawn.generated.h"

class UTC_PlayerSpringArmComponent;
class UCameraComponent;

UCLASS()
class ATC_PlayerPawn : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	UTC_PlayerSpringArmComponent* SpringArmComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	UCameraComponent* CameraComponent;

public:
	ATC_PlayerPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float ZoomSpeed = 30.0f;

public:	
	virtual void Tick(float DeltaTime) override;

	void ZoomCamera(float InAxis);

	void MoveUp(float InAxis);
	void MoveRight(float InAxis);
};
