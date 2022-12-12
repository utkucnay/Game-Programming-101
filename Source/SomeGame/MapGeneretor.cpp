// Fill out your copyright notice in the Description page of Project Settings.

#include "MapGeneretor.h"
#include "PerlinNoiseGeneretor.h"

// Sets default values
AMapGeneretor::AMapGeneretor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	textureLenght = FVector2f(64,64);
}

// Called when the game starts or when spawned
void AMapGeneretor::BeginPlay()
{
	Super::BeginPlay();

	auto firstNoise = PerlinNoiseGeneretor::GetPerlinNoise(textureLenght, (FMath::SRand() + .1f) * 20 );

	float startPointX = groundLoc.X / cScaleValueMulti - groundScale.X / 2;
	float startPointY = groundLoc.Y / cScaleValueMulti - groundScale.Y / 2;

	FVector2f offset = groundScale * cScaleValueMulti / textureLenght;
	offset -= FVector2f(cScaleValueMulti);
	

	for (int i = 0; i < meshDatas.Num(); i++) 
	{
		meshDatas[i].ActorOfMesh = GetWorld()->SpawnActor<ABaseActor>(FVector(), FRotator());
		meshDatas[i].ISMC = meshDatas[i].ActorOfMesh->ISMC;
		meshDatas[i].ISMC->SetStaticMesh(meshDatas[i].mesh);
		meshDatas[i].divideRatio = 1.0f / meshDatas[i].distance;
		meshDatas[i].distanceRatio = FindRatio(meshDatas[i].density / 1000.0f, meshDatas[i].divideRatio);
	}

	for (int y = 0; y < textureLenght.Y; y++) {
		for (int x = 0; x < textureLenght.X; x++)
		{
			for(float f = 0; f < meshDatas.Num(); f++)
			{
				for (float i = 0; i < 1; i += meshDatas[f].divideRatio)
				{
					if (ObjectInRange(i, meshDatas[f].distanceRatio + i, firstNoise[textureLenght.Y * y + x].X))
					{
						SpawnObject(
							FVector((startPointX + x) * cScaleValueMulti + offset.X * x, (startPointY + y) * cScaleValueMulti + offset.Y * y, 0),
							FRotator(0, FMath::RandHelper(360), 0), meshDatas[f].ISMC);
					}
				}
			}
		}
	}
}

// Called every frame
void AMapGeneretor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


float AMapGeneretor::FindRatio(float ratioObject, float textureDivideratio)
{
	float ratio = textureDivideratio;
	ratio *= ratioObject;
	return ratio;
}

bool AMapGeneretor::ObjectInRange(float minX, float maxX, float currX) {
	if (minX < currX && currX < maxX) {
		return true;
	}
	return false;
}

void AMapGeneretor::SpawnObject(FVector vector, FRotator rotator, UInstancedStaticMeshComponent* ISMC)
{
	ISMC->AddInstance(FTransform(rotator, vector, FVector3d(1, 1, 1)), true);
}
