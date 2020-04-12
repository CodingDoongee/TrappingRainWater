#include <stdio.h>

typedef unsigned char uint8_t;
typedef int int32_t;

int trap(int32_t* height, int32_t heightSize)
{
	int32_t s32_WaterVolume = 0, s32_MaxIdx = 0, s32_LeftMaxIdx = 0, s32_RightMaxIdx = heightSize - 1;
	int32_t s32_LeftIdx = 0, s32_RightIdx = heightSize - 1;

	while (1)
	{
		if (s32_LeftIdx > s32_RightIdx)
		{
			break;
		}
		else
		{
			;
		}

		if (height[s32_LeftMaxIdx] <= height[s32_RightMaxIdx])
		{
			if (height[s32_LeftIdx] >= height[s32_LeftMaxIdx])
			{
				s32_LeftMaxIdx = s32_LeftIdx;
			}
			else
			{
				s32_WaterVolume = s32_WaterVolume + height[s32_LeftMaxIdx] - height[s32_LeftIdx];
			}
			s32_LeftIdx++;
		}
		else
		{
			if (height[s32_RightIdx] >= height[s32_RightMaxIdx])
			{
				s32_RightMaxIdx = s32_RightIdx;
			}
			else
			{
				s32_WaterVolume = s32_WaterVolume + height[s32_RightMaxIdx] - height[s32_RightIdx];
			}
			s32_RightIdx--;
		}
	}
	return s32_WaterVolume;
}


void main()
{
	int32_t ars32_height[4] = {33, 0, 22, 100};
	
	printf("Result: %d\n", trap(ars32_height, 4));

}