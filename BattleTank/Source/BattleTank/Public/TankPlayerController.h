// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intercepts the world
	void AimTowardsCrosshair();

private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	const FHitResult GetFirstPhysicsBodyInReach();

	FVector GetReachLineEnd();
};

