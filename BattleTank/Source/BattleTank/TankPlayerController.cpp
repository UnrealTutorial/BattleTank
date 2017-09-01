// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATankPlayerController::ATankPlayerController() {
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possesing a tank!"))
	}else {

		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()))
	}

}

void ATankPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	//aim towards crosshair
	AimTowardsCrosshair();

}

ATank * ATankPlayerController::GetControlledTank() const{
	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank())
		return;

	FVector HitLocation(0.f,0.f,0.f);//out parameter
	if (GetSightRayHitLocation(HitLocation)) { // Has side effect, is going to line trace

		//UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString())
		
			//tell controlled tankto aim at this point
	}
}

//get world location of linetrace throught crosshair,true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & OUTHitLocation) const{
	OUTHitLocation = FVector(0.f,0.f,0.f);
	
	//find the crosshair display pos
	//de project the screen position of the croshair to a world direction
	//linetrace along that look direction, and see what we hit

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"),*(ScreenLocation.ToString()))
	return false;
}
