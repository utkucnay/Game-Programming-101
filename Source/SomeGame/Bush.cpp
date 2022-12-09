// Fill out your copyright notice in the Description page of Project Settings.


#include "Bush.h"

// Sets default values
ABush::ABush()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto bush = ConstructorHelpers::FObjectFinder<UStaticMesh>(
		TEXT("StaticMesh'/Game/Assets/StarterContent/Props/SM_Bush.SM_Bush'"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	BushPtr = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("American Three"));
	BushPtr->SetStaticMesh(bush.Object);
	BushPtr->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABush::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABush::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

