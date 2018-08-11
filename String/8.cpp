#include "../base.h"

/*
1.开头空格删掉
2.开头非数字删掉
3.中间遇到空格不再继续往后读
4.符号问题
5.溢出问题
*/

class Solution {
public:
	int myAtoi(string str) {
		long int t_nRes = 0;
		int t_bflag = 1;
		bool t_bhaveflag = false;
		size_t t_nLen = str.size();
		do
		{
			size_t t_nstart = str.find_first_of("0123456789");
			if (t_nstart == string::npos)
				break;
			for (size_t i = 0; i < t_nstart; i++)
			{
				if (!t_bhaveflag)
				{
					if (str[i] != ' ')
					{
						if (str[i] == '+')
						{
							if (i != t_nstart - 1)
								return 0;
							t_bflag = 1;
							t_bhaveflag = true;
						}
						else if (str[i] == '-')
						{
							if (i != t_nstart - 1)
								return 0;
							t_bflag = -1;
							t_bhaveflag = true;
						}
						else {
							return 0;
						}
					}
				}
				else {
					if (str[i] != ' ')
						return 0;
				}
			}
			for (size_t i = t_nstart; i<t_nLen; i++)
			{
				if (!(str[i] >= 48 && str[i] <= 57))
					break;
				else {
					t_nRes = t_nRes * 10 + (str[i]-48);
					if (t_bflag*t_nRes > INT_MAX)
						return INT_MAX;
					if (t_bflag*t_nRes < INT_MIN)
						return INT_MIN;				
				}
				//cout << t_nRes << endl;
			}
			t_nRes *= t_bflag;
		} while (false);
		if (t_nRes > INT_MAX)
			return INT_MAX;
		else if (t_nRes < INT_MIN)
			return INT_MIN;
		else
		{
			return t_nRes;
		}
	//	return t_bflag*t_nRes;
	}
};