// Fill out your copyright notice in the Description page of Project Settings.

#include "MapGeneretor.h"
#include "PerlinNoiseGeneretor.h"
#include "Tree.h"
#include "Bush.h"

// Sets default values
AMapGeneretor::AMapGeneretor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapGeneretor::BeginPlay()
{
	Super::BeginPlay();
	
	int mapLenght = 128;

	auto noise = PerlinNoiseGeneretor::GetPerlinNoiseSquare(mapLenght, (FMath::SRand() + .1f) * 20 );
	
	for (int y = 0; y < mapLenght - 1; y++) {
		for (int x = 0; x < mapLenght - 1; x++)
		{
			SpawnObjectInRange<ATree>(.3f, .3025f, noise[y * mapLenght + x].X,
				FVector(x * 100 + 50, y * 100 + 50, 0), FRotator(0, noise[y * mapLenght + x].Y, 0));

			SpawnObjectInRange<ATree>(-.3025f, -.3f, noise[y * mapLenght + x].X,
				FVector(x * 100 + 50, y * 100 + 50, 0), FRotator(0, noise[y * mapLenght + x].Y, 0));

			SpawnObjectInRange<ABush>(-.8f, -.6f, noise[y * mapLenght + x].X,
				FVector(x * 100 + 50, y * 100 + 50, 0), FRotator(0, noise[y * mapLenght + x].Y, 0));

			SpawnObjectInRange<ABush>(-.3f, -.1f, noise[y * mapLenght + x].X,
				FVector(x * 100 + 50, y * 100 + 50, 0), FRotator(0, noise[y * mapLenght + x].Y, 0));

			SpawnObjectInRange<ABush>(.8f, 1.0f, noise[y * mapLenght + x].X,
				FVector(x * 100 + 50, y * 100 + 50, 0), FRotator(0, noise[y * mapLenght + x].Y, 0));

			SpawnObjectInRange<ABush>(.2f, .4f, noise[y * mapLenght + x].X,
				FVector(x * 100 + 50, y * 100 + 50, 0), FRotator(0, noise[y * mapLenght + x].Y, 0));
		}
	}
	
}

// Called every frame
void AMapGeneretor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


template<typename T>
void AMapGeneretor::SpawnObjectInRange(float minX, float maxX, float currX, FVector vector, FRotator rotator)
{
	if (minX < currX && currX < maxX) {
		GetWorld()->SpawnActor<T>(vector, rotator);
	}
}
