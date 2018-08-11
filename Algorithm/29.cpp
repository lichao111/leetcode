#include "../base.h"

class Solution {
public:
	int divide(int dividend, int divisor) {//用加法  Time Limit Exceeded
		long int t_nSum=0;
		if (divisor == 0)
			return dividend > 0 ? INT_MAX : INT_MIN;
		//assert(t_nCounts == (dividend / divisor));
		long int t_ndivedend =dividend;
		long int t_ndivisor =divisor;
		t_ndivedend = abs(t_ndivedend);
		t_ndivisor = abs(t_ndivisor);

		while (t_ndivedend >=t_ndivisor){
			//cout << '-' << endl;
			t_ndivedend -=t_ndivisor;
			t_nSum++;
		}
		//cout << t_nSum << endl;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0)) {
			t_nSum = -t_nSum;
		}
		if (t_nSum > INT_MAX)
			return INT_MAX;
		if (t_nSum < INT_MIN)
			return INT_MIN;

		return t_nSum;
	}

	int divided(int dividend, int divisor) {//bit manipulations
		int t_nRes = 0;
		if (divisor == 0 || (dividend == INT_MIN&&divisor == -1))
			return INT_MAX;
		long t_ndividend = labs(dividend);
		long t_ndivisor = labs(divisor);
		int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
		while (t_ndividend>=t_ndivisor)
		{
			long temp = t_ndivisor, multiple = 1;
			while (t_ndividend >= (temp << 1)) {
				temp <<= 1;
				multiple <<= 1;
				cout << multiple << endl;
			}
			t_ndividend -= temp;
			t_nRes += multiple;
		}
		return sign*t_nRes;
	}
};