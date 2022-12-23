// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SOMEGAME_API TextureHelper
{
public:
	// TArray has already memory alloction
	static TArray<FVector4f> FractalAlgorithm(int count, TArray<FVector4f> texture, FVector2f& textureLength);
};
