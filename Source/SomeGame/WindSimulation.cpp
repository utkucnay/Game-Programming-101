// Fill out your copyright notice in the Description page of Project Settings.


#include "WindSimulation.h"

// Sets default values
AWindSimulation::AWindSimulation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

}

// Called when the game starts or when spawned
void AWindSimulation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWindSimulation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

