#include "Character/TC_PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Player/Components/TC_PlayerSpringArmComponent.h"

ATC_PlayerPawn::ATC_PlayerPawn()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;

	BaseComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BaseComponent"));
	SetRootComponent(BaseComponent);

	SpringArmComponent = CreateDefaultSubobject<UTC_PlayerSpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(BaseComponent);
	SpringArmComponent->SetRelativeRotation(FRotator(-40.0f, 0.0f, 0.0f));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ATC_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	DesiredLocation = GetActorLocation();
	DesiredRotation = GetActorRotation();
}

void ATC_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(FMath::VInterpTo(GetActorLocation(), DesiredLocation, DeltaTime, MovementInterpSpeed));
	SetActorRotation(FMath::RInterpTo(GetActorRotation(), DesiredRotation, DeltaTime, RotationInterpSpeed));
}

void ATC_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("Zoom"), this, &ATC_PlayerPawn::ZoomCamera);

	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &ATC_PlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ATC_PlayerPawn::MoveRight);
	PlayerInputComponent->BindAction(FName("TurnRight"), IE_Pressed, this, &ATC_PlayerPawn::TurnRight);
	PlayerInputComponent->BindAction(FName("TurnLeft"), IE_Pressed, this, &ATC_PlayerPawn::TurnLeft);
}

void ATC_PlayerPawn::ZoomCamera(float InAxis)
{
	SpringArmComponent->AddDesiredArmLength(InAxis * CameraZoomSpeed);
}

void ATC_PlayerPawn::MoveUp(float InAxis)
{
	DesiredLocation += GetActorForwardVector() * InAxis * MovementSpeed;
}

void ATC_PlayerPawn::MoveRight(float InAxis)
{
	DesiredLocation += GetActorRightVector() * InAxis * MovementSpeed;
}

void ATC_PlayerPawn::TurnRight()
{
	DesiredRotation.Yaw += RotationStep;
}

void ATC_PlayerPawn::TurnLeft()
{
	DesiredRotation.Yaw -= RotationStep;
}

void ATC_PlayerPawn::CHEAT_SetCameraZoomInterpSpeed(float InValue)
{
	SpringArmComponent->SetSmoothArmLengthSpeed(InValue);
}

void ATC_PlayerPawn::CHEAT_SetCameraMinZoom(float InValue)
{
	SpringArmComponent->SetMinDesiredArmLength(InValue);
}

void ATC_PlayerPawn::CHEAT_SetCameraMaxZoom(float InValue)
{
	SpringArmComponent->SetMaxDesiredArmLength(InValue);
}