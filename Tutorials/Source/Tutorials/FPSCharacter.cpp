// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacter.h"
//#include "Components/InputComponent.h"
//#include "Runtime/Engine/Classes/Engine/Engine.h"



// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCHARACTER"));
    }
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
    //PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

}

void AFPSCharacter::MoveForward(float Value)
{
    //furgle
}


