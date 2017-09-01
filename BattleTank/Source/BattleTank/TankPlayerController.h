// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTank/Public/Tank.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	
	ATankPlayerController();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
	ATank* GetControlledTank() const;

	//start the tank moving the barrel so that a shot would hit 
	//whe the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector & OUTHitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.333;


};
