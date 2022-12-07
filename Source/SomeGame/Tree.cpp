// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

// Sets default values
ATree::ATree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto treeThrunk = ConstructorHelpers::FObjectFinder<UStaticMesh>(
		TEXT("StaticMesh'/Game/TreeMesh/American_Elm_tree_vray.American_Elm_tree_vray'"));


	auto ThreeTrunkPtr = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Three Trunk"));
	ThreeTrunkPtr->SetStaticMesh(treeThrunk.Object);
	
	SetRootComponent(ThreeTrunkPtr);
}

// Called when the game starts or when spawned
void ATree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

