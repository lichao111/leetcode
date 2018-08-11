#include "../base.h"

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		long int t_x = x;

		int t_nTmp = 0;
		while (x)
		{
			t_nTmp = 10 * t_nTmp + (x % 10);
			x = x / 10;
		}

		if (0 == (t_nTmp - t_x))
			return true;
		else
			return false;
	}
};