// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include <vector>

#include "Evaluation/IMovieSceneEvaluationHook.h"
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
	location = initPos + FMath::Sin(time/period*2*PI) * Amplitude;
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
	initPos =
		playerPawn->GetActorLocation() + initOffset;
	SetActorLocation(initPos);
}
