// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSUALTT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnywhere)
	float initialDelay{1.0f};
	UPROPERTY(EditAnywhere)
	FVector Amplitude{};
	UPROPERTY(EditAnywhere)
	FVector initOffset{};
	UPROPERTY(EditAnywhere)
	float period;
	APawn* playerPawn{nullptr};
	FVector location{};
	FVector initPos{};
	float time;
	bool ShouldMove(float deltaTime);
	void Initialise();
	void MovePlatform(float deltaTime);
	
};
