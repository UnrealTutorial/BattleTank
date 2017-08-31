// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATankPlayerController::ATankPlayerController() {

}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possesing a tank!"))
	}else {

		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()))
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play"))
}

ATank * ATankPlayerController::GetControlledTank() const{
	
	return Cast<ATank>(GetPawn());
}
