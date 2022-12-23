// Fill out your copyright notice in the Description page of Project Settings.

#include "MapGeneretor.h"
#include "PerlinNoiseGeneretor.h"
#include "TextureHelper.h"

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

	auto noiseTexture = PerlinNoiseGeneretor::GetPerlinNoise(textureLenght, (FMath::SRand() + .1f) * 20 );
	noiseTexture = TextureHelper::FractalAlgorithm(20, noiseTexture, textureLenght);

	float startPointX = groundLoc.X / cScaleValueMulti - groundScale.X / 2;
	float startPointY = groundLoc.Y / cScaleValueMulti - groundScale.Y / 2;

	FVector2f offset = groundScale * cScaleValueMulti / textureLenght;
	offset -= FVector2f(cScaleValueMulti);
	

	for (int i = 0; i < meshDatas.Num(); i++) 
	{
		meshDatas[i].ActorOfMesh = GetWorld()->SpawnActor<ABaseActor>(FVector(), FRotator());
		meshDatas[i].ActorOfMesh->SetActorLabel(meshDatas[i].name);
		meshDatas[i].ISMC = meshDatas[i].ActorOfMesh->ISMC;
		meshDatas[i].ISMC->SetStaticMesh(meshDatas[i].mesh);
		meshDatas[i].divideRatio = 1.0f / meshDatas[i].distance;
		meshDatas[i].distanceRatio = FindRatio(meshDatas[i].density / 1000.0f, meshDatas[i].divideRatio);
	}

	Algo::SortBy(meshDatas, &FMeshData::density);

	for (int y = 0; y < textureLenght.Y; y++) {
		for (int x = 0; x < textureLenght.X; x++)
		{
			bool IsSpawn = false;
			for(float f = 0; f < meshDatas.Num(); f++)
			{
				auto meshData = meshDatas[f];
				for (float i = 0; i < 1; i += meshData.divideRatio)
				{
					if (ObjectInRange(i, meshData.distanceRatio + i, noiseTexture[textureLenght.Y * y + x].X))
					{
						InstanceObject(
							FVector((startPointX + x) * cScaleValueMulti + offset.X * x, (startPointY + y) * cScaleValueMulti + offset.Y * y, 0),
							FRotator(0, meshData.RandomRotation ? FMath::RandHelper(360) : 0, 0),
							meshData.RandomScale ? meshData.ScaleMin + FMath::SRand() * (meshData.ScaleMax - meshData.ScaleMin) : FVector3d(1, 1, 1)
							,meshData.ISMC);
						IsSpawn = true;
						break;
					}
				}
				if (IsSpawn)
					break;
			}
		}
	}
}

// Called every frame
void AMapGeneretor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


float AMapGeneretor::FindRatio(float ratioObject, float textureDivideRatio)
{
	float ratio = textureDivideRatio;
	ratio *= ratioObject;
	return ratio;
}

bool AMapGeneretor::ObjectInRange(float minX, float maxX, float currX) const
{
	if (minX < currX && currX < maxX) {
		return true;
	}
	return false;
}

void AMapGeneretor::InstanceObject(FVector vector, FRotator rotator, FVector3d scale, UInstancedStaticMeshComponent* ISMC)
{
	ISMC->AddInstance(FTransform(rotator, vector, scale), true);
}
