#include "../base.h"

//if target found , return its index
//if not found , return -1

//Node : a is need to be sorted
int BinarySearch(vector<int> a, int p_nTarget) {
	int t_nRes = -1;
	int t_nLen = a.size();
	//if (t_nLen == 0) return t_nRes;
	int start = 0;
	int end = t_nLen - 1;
	int t_nBinary;
	for (;start<=end;) {
		t_nBinary = (end + start) / 2;
		if (a[t_nBinary] > p_nTarget) {
			end = t_nBinary-1;
		}
		else if (a[t_nBinary] < p_nTarget) {
			start = t_nBinary+1;
		}
		else {
			return t_nBinary;
		}
	}
	return -1;
}