#include "../base.h"
#include <stdio.h>
/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line : "PAHNAPLSIIGYIR" PAHNAPLSIIGYYIIRR PAHNAPLSIIGYYIR PAHNAPLSIIGIR
Write the code that will take a string and make this conversion given a number of rows :

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/

class Solution {
public:
	string convert(string s, int numRows) {
		int t_nLen = s.size();
		string t_strRes = "";
		if (t_nLen == 1 || numRows == 1)
			return s;
		numRows = t_nLen > numRows ? numRows : t_nLen;
		for (int t_nRow = 0; t_nRow < numRows; t_nRow++)//遍历行
		{
			int t_nPos = t_nRow;
			cout <<"--"<< t_nPos<<"--" << endl;
			for (int t_nColu = 0; ;)//遍历列
			{
				cout << t_nColu << endl;
				if (t_nColu == 0)
				{
					t_strRes.push_back(s[t_nPos]);
					if ((t_nRow == 0))
						t_nColu = 1;
					else if (t_nRow == numRows - 1)
						t_nColu = 2;
					else
						t_nColu += 1;
					continue;
				}
				if (t_nColu % 2 == 0)//奇数列
				{
					t_nPos += (2 * t_nRow);
				}
				else//偶数列
				{
					t_nPos += (2 * (numRows - t_nRow - 1));
				}
				if (t_nPos < t_nLen)
				{
					t_strRes.push_back(s[t_nPos]);
				}
				else
				{
					break;
				}
				cout << t_nPos << endl;
				if ((t_nRow == 0))
					t_nColu = 1;
				else if (t_nRow == numRows - 1)
					t_nColu = 2;
				else
					t_nColu += 1;
				//getchar();
			}
		}
		return t_strRes;
	}
};