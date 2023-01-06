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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MovementSpeed = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MovementInterpSpeed = 6.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RotationStep = 90.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RotationInterpSpeed = 6.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CameraZoomSpeed = 30.0f;

public:
	UFUNCTION(BlueprintCallable)
	void CHEAT_SetMovementSpeed(float InValue) { MovementSpeed = InValue; }

	UFUNCTION(BlueprintCallable)
	void CHEAT_SetMovementInterpSpeed(float InValue) { MovementInterpSpeed = InValue; }

	UFUNCTION(BlueprintCallable)
	void CHEAT_SetRotationStep(float InValue) { RotationStep = InValue; }

	UFUNCTION(BlueprintCallable)
	void CHEAT_SetRotationInterpSpeed(float InValue) { RotationInterpSpeed = InValue; }

	UFUNCTION(BlueprintCallable)
	void CHEAT_SetCameraZoomSpeed(float InValue) { CameraZoomSpeed = InValue; }

	UFUNCTION(BlueprintCallable)
	void CHEAT_SetCameraZoomInterpSpeed(float InValue);

	UFUNCTION(BlueprintCallable)
	void CHEAT_SetCameraMinZoom(float InValue);

	UFUNCTION(BlueprintCallable)
	void CHEAT_SetCameraMaxZoom(float InValue);
};
