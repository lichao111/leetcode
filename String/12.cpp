#include "../base.h"

/*Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.*/

//What is roman numeral?

/*罗马数字是阿拉伯数字传入之前使用的一种数码。罗马数字采用七个罗马字母作数字、
即Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）*/

class Solution {
public:
	string intToRoman(int num) {
		const int radix[] = { 1000, 900, 500, 400, 100, 90,50, 40, 10, 9, 5, 4, 1 };
		const string symbol[] = { "M", "CM", "D", "CD", "C", "XC","L", "XL", "X", "IX", "V", "IV", "I" };
		string roman;
		for (size_t i = 0; num>0; ++i) {
			int count = num / radix[i];
			num %= radix[i];
			for (; count>0; --count) {
				roman += symbol[i];
			}
		}
		return roman;
	}
};
