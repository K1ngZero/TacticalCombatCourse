#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "TC_PlayerPawn.generated.h"

class UCameraComponent;
class USceneComponent;

class UTC_PlayerSpringArmComponent;

UCLASS()
class ATC_PlayerPawn : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	USceneComponent* BaseComponent = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	UTC_PlayerSpringArmComponent* SpringArmComponent = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	UCameraComponent* CameraComponent = nullptr;

public:
	ATC_PlayerPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void ZoomCamera(float InAxis);

	void MoveUp(float InAxis);
	void MoveRight(float InAxis);

	void TurnRight();
	void TurnLeft();

protected:
	UPROPERTY()
	FVector DesiredLocation = FVector::ZeroVector;

	UPROPERTY()
	FRotator DesiredRotation = FRotator::ZeroRotator;

	UPROPERTY(EditDefaultsOnly)
	float ZoomSpeed = 30.0f;
};
