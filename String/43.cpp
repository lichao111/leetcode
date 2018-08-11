#include "../base.h"

#include <sstream>
class Solution {
public:
	string multiply(string num1, string num2) {//O(m*n)
		if(num1=="0"||num2=="0") return "0";
		string t_strRet = "";
		// int t_nSum = 0;
		// int t_nX = 0;
		// int t_nJ = 0;
		for(int i = num1.size()-1,k= 0;i>=0;i--,k++)
		{
			int t_nSum = 0;
			int t_nX = 0;
			int t_nJ = 0;
			string t_strSumone="";
		
			for(int j = num2.size()-1;j>=0;j--)
			{
				t_nSum = (num1[i]-'0')*(num2[j]-'0')+t_nJ;
				t_nX = t_nSum%10;
				t_nJ = t_nSum/10;
				ostringstream os;
				os<<t_nX;
				t_strSumone = os.str()+t_strSumone;
			}
			if(t_nJ!=0)
			{
				ostringstream os;
				os<<t_nJ;
				t_strSumone = os.str()+t_strSumone;
			}
			int ll =k;
			while(ll !=0)
			{
				t_strSumone = t_strSumone+"0";
				ll --;
			}
			t_strRet = sum(t_strSumone,t_strRet);
		}
		return t_strRet;
		
	}
	string sum(string p_str1, string p_str2)//O(N) N is the max length of str1 and str2
	{
		int t_nLen = p_str1.size()>=p_str2.size()?p_str1.size():p_str2.size();//the longger 
		while(p_str1.size()<t_nLen)
		{
			p_str1 = "0"+p_str1;
		}
		while(p_str2.size()<t_nLen)
		{
			p_str2 = "0"+p_str2;
		}
		string t_nRet = "";
		int t_nSum = 0;
		int t_nX = 0;
		int t_nJ = 0;
		for(int i = t_nLen-1;i>=0;i--)
		{
			t_nSum = (p_str1[i]-'0')+(p_str2[i]-'0')+t_nJ;

			t_nJ = t_nSum/10;
			t_nX = t_nSum%10;
			ostringstream os;
			os<<t_nX;
			t_nRet = os.str()+t_nRet;
		}
		if(t_nJ!=0)
		{
			ostringstream os;
			os<<t_nJ;
			t_nRet = os.str()+t_nRet;
		}
		return t_nRet;
	}
};