#include <stdio.h>

#define MAPFIELD_X 1000
#define MAPFIELD_Y 100
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
	//int* ars32_WaterHeight = (int*)malloc(sizeof(int) * heightSize);
	int ars32_WaterMap[MAPFIELD_X][MAPFIELD_Y] = { 0 };
	int s32_MaxHeight = 0, s32_WaterVolume = 0;
	// find max height
	s32_MaxHeight = FindMax(height, heightSize);
	for (int i=0; i<heightSize; i++)
	{
		for (int j=0; j< s32_MaxHeight; j++)
		{
			if (j <= height[i])
			{
				ars32_WaterMap[i][j] = 2;
			}
			else
			{
				ars32_WaterMap[i][j] = 1;
			}			
		}
	}

	// max height left search
	for (int j = 0; j < MAPFIELD_Y; j++)
	{
		for (int i = 0; i < MAPFIELD_X; i++)
		{
			if (ars32_WaterMap[i][j] == 1)
			{
				ars32_WaterMap[i][j] = 0;
			}
			else if (ars32_WaterMap[i][j] == 2)
			{
				break;
			}
		}
	}


	// max height right search
	for (int j = 0; j < MAPFIELD_Y; j++)
	{
		for (int i = MAPFIELD_X-1; i >= 0; i--)
		{
			if (ars32_WaterMap[i][j] == 1)
			{
				ars32_WaterMap[i][j] = 0;
			}
			else if (ars32_WaterMap[i][j] == 2)
			{
				break;
			}
		}
	}

	for (int i = 0; i < heightSize; i++)
	{
		for (int j = 0; j < s32_MaxHeight; j++)
		{
			if (ars32_WaterMap[i][j] == 1)
			{
				s32_WaterVolume++;
			}
		}
	}

	return s32_WaterVolume;
}

void main()
{
	int ars32_height[12] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	printf("Result: %d\n", trap(ars32_height, 12));

}