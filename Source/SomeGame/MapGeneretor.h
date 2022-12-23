// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.h"
#include "MapGeneretor.generated.h"


USTRUCT()
struct FMeshData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnyWhere)
		FString name;
	UPROPERTY(EditAnyWhere, meta=(ClampMin = "0", ClampMax = "1000"))
		float density;
	UPROPERTY(EditAnyWhere)
		float distance;
	UPROPERTY(EditAnyWhere)
		UStaticMesh* mesh;
	UPROPERTY(EditAnyWhere)
		bool RandomRotation;
	UPROPERTY(EditAnyWhere)
		bool RandomScale;
	UPROPERTY(EditAnyWhere)
		FVector ScaleMax;
	UPROPERTY(EditAnyWhere)
		FVector ScaleMin;
	ABaseActor* ActorOfMesh;
	UInstancedStaticMeshComponent* ISMC;
	float distanceRatio;
	float divideRatio;
};


UCLASS()
class SOMEGAME_API AMapGeneretor : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnyWhere)
		FVector2f textureLenght;

	UPROPERTY(EditAnyWhere)
		FVector2f groundLoc;
	UPROPERTY(EditAnyWhere)
		FVector2f groundScale;

	UPROPERTY(EditAnyWhere)
		TArray<FMeshData> meshDatas;

	const float cScaleValueMulti = 100;

public:	
	// Sets default values for this actor's properties
	AMapGeneretor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float FindRatio(float ratioObject, float textureDivideLenght);

private:
	void SpawnInstancedObjectWithMeshData(TArray<FMeshData> meshDatas);
	bool ObjectInRange(float minX, float maxX, float currX) const;
	void InstanceObject(FVector vector, FRotator rotator, FVector3d scale, UInstancedStaticMeshComponent* ISMC);
};




