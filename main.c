#include <stdio.h>

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
	int* ars32_WaterHeight = (int*)malloc(sizeof(int) * heightSize);

	// find max height
	for (int i = 0; i < heightSize; i++)
	{
		ars32_WaterHeight[i] = FindMax(height, heightSize);
	}

	// max height left search
	for (int h = FindMax(height, heightSize); h >= 0; h--)
	{
		for (int i = 0; i < heightSize - 1; i++)
		{
			if (height[i + 1] >= h)
			{
				ars32_WaterHeight[i] = 0;
			}
			else
			{
				ars32_WaterHeight[i] = h;
			}
			break;
		}
	}


	// max height right search
	for (int h = FindMax(height, heightSize); h >= 0; h--)
	{
		for (int i = heightSize - 1; i > 0; i--)
		{
			if (height[i - 1] >= h)
			{
				ars32_WaterHeight[i] = 0;
			}
			else
			{
				ars32_WaterHeight[i] = h;
			}
			break;
		}
	}

	for (int i = 0; i < heightSize; i++)
	{
		printf("%d ", ars32_WaterHeight[i]);
	}
}

void main()
{
	int ars32_height[12] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	trap(ars32_height, 12);

}