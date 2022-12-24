#include "Character/TC_PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Player/Components/TC_PlayerSpringArmComponent.h"

ATC_PlayerPawn::ATC_PlayerPawn()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<UTC_PlayerSpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetRelativeRotation(FRotator(-40.0f, 0.0f, 0.0f));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
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

	PlayerInputComponent->BindAxis(FName("Zoom"), this, &ATC_PlayerPawn::ZoomCamera);

	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &ATC_PlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ATC_PlayerPawn::MoveRight);
}

void ATC_PlayerPawn::ZoomCamera(float InAxis)
{
	SpringArmComponent->AddDesiredArmLength(InAxis * ZoomSpeed);
}

void ATC_PlayerPawn::MoveUp(float InAxis)
{

}

void ATC_PlayerPawn::MoveRight(float InAxis)
{

}

