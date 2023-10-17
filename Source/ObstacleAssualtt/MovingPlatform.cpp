// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include "Logging/StructuredLog.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	Initialise();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float deltaTime)
{
	if (!ShouldMove(deltaTime))
		return;
	location = GetActorLocation();
	if (playerPawn == nullptr)
		return;

	const FVector deltaPos = playerPawn->GetActorForwardVector() * platformSpeed * deltaTime + playerPawn->
		GetActorUpVector()
		* .1f * deltaTime;
	location += deltaPos;
	SetActorLocation(location);
}

bool AMovingPlatform::ShouldMove(float deltaTime)
{
	time += deltaTime;

	return time > initialDelay;
}

void AMovingPlatform::Initialise()
{
	time = 0.0f;
	playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	 FVector deltaPos=
		 static_cast<UE::Math::TVector4<double>>(200.0f *playerPawn->GetActorForwardVector().Normalize());
	deltaPos.Z=0.0f;
	const auto posToPutPlatformAt =
		playerPawn->GetActorLocation() +deltaPos;
	SetActorLocation(posToPutPlatformAt);
}
