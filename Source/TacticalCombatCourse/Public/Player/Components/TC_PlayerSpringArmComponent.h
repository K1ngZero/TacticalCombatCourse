#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"

#include "TC_PlayerSpringArmComponent.generated.h"

UCLASS()
class UTC_PlayerSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetDesiredArmLength(float InNewLength);

	UFUNCTION(BlueprintCallable)
	void AddDesiredArmLength(float InLengthOffset);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lag")
	float DesiredArmLength = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lag")
	float MinDesiredArmLength = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lag")
	float MaxDesiredArmLength = 2000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lag")
	float SmoothArmLengthSpeed = 0.0f;
};
