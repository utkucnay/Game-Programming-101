// Fill out your copyright notice in the Description page of Project Settings.


#include "TextureHelper.h"

TArray<FVector4f> TextureHelper::FractalAlgorithm(int count, TArray<FVector4f> texture, FVector2f& textureLength)
{
	for (int z = 0; z < count; z++) {
		for (int y = 0; y < textureLength.Y - 1; y++)
		{
			for (int x = 0; x < textureLength.X - 1; x++)
			{
				texture[y * textureLength.Y + x] = (texture[y * textureLength.Y + x + 1] + texture[(y + 1) * textureLength.Y + x + 1] +
					texture[(y + 1) * textureLength.Y + x]) / 3;
			}
		}
	}
	return texture;
}
