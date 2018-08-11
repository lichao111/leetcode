#include "../base.h"

class Solution {
public:
	int maxArea(vector<int>& height) {
		int water = 0;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int h = min(height[i], height[j]);
			water = max(water, (j - i) * h);
			while (height[i] <= h && i < j) i++;
			while (height[j] <= h && i < j) j--;
		}
		return water;
	}
private:
	int min(int a, int b)
	{
		return a <= b ? a : b;
	}

	int max(int a, int b)
	{
		return a >= b ? a : b;
	}
};