#include <stdio.h>

typedef unsigned char uint8_t;

int FindMax(int* height, int heightSize)
{
	int MaxVal = 0;
	for (int i = 0; i < heightSize; i++)
	{
		if (height[i] > MaxVal)
		{
			MaxVal = height[i];
		}
	}
	return MaxVal;
}


int trap(int* height, int heightSize)
{
	uint8_t** aru8_WaterMap = NULL;
	int s32_MaxHeight = 0, s32_WaterVolume = 0;

	// find max height
	s32_MaxHeight = FindMax(height, heightSize);
	aru8_WaterMap = (uint8_t**)malloc(sizeof(uint8_t*) * s32_MaxHeight);
	for (int i = 0; i < s32_MaxHeight; i++)
	{
		aru8_WaterMap[i] = malloc(sizeof(uint8_t) * heightSize);
		memset(aru8_WaterMap[i], 0, sizeof(uint8_t) * heightSize);
	}


	for (int j = 0; j < heightSize; j++)
	{
		for (int i = 0; i < s32_MaxHeight; i++)
		{
			if (i < height[j])
			{
				aru8_WaterMap[i][j] = 2;
			}
			else
			{
				aru8_WaterMap[i][j] = 1;
			}
		}
	}

	// max height left search
	for (int i = 0; i < s32_MaxHeight; i++)
	{
		for (int j = 0; j < heightSize; j++)
		{

			if (aru8_WaterMap[i][j] == 1)
			{
				aru8_WaterMap[i][j] = 0;
			}
			else if (aru8_WaterMap[i][j] == 2)
			{
				break;
			}
		}
	}


	// max height right search
	for (int i = 0; i < s32_MaxHeight; i++)
	{
		for (int j = heightSize-1; j >= 0 ; j--)
		{

			if (aru8_WaterMap[i][j] == 1)
			{
				aru8_WaterMap[i][j] = 0;
			}
			else if (aru8_WaterMap[i][j] == 2)
			{
				break;
			}
		}
	}


	for (int j = s32_MaxHeight - 1; j >= 0; j--)
	{
		for (int i = 0; i < heightSize; i++)
		{
			//printf("%d ", aru8_WaterMap[j][i]);
			if (aru8_WaterMap[j][i] == 1)
			{
				s32_WaterVolume++;
			}
		}
		//printf("\n");
	}

	for (int i = 0; i < s32_MaxHeight; i++)
	{
		free(aru8_WaterMap[i]);
	}
	free(aru8_WaterMap);

	return s32_WaterVolume;
}

void main()
{
	int ars32_height[15] = { 1,1,1,1,1,0,1,3,2,1,2,3,3,3,1 };
	for (int kk = 0; kk < 15; kk++)
	{
		printf("%d ", ars32_height[kk]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Result: %d\n", trap(ars32_height, 15));

}