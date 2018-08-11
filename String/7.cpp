#include "../base.h"

class Solution {
public:
	int reverse(int x) { //关于整形的题要注意溢出问题
		long int t_nRes = 0;
		int t_nflag = x >= 0 ? 1 : -1;
		x = t_nflag * x;
		while(x!=0)
		{
			t_nRes = 10*(t_nRes) + x % 10;
			x = x / 10;
		}
		t_nRes =  t_nRes*t_nflag;
		if (t_nRes < INT_MIN || t_nRes > INT_MAX)
			return 0;
		else
			return t_nRes;
	}
};