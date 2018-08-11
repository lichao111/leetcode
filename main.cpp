
#include "./Arry/53.cpp"

#include "./Arry/BinarySearch.cpp"

int main()
{
	Solution t_mSoluton;
	//5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
	int myints1[] = {-1,-1,-1,-1,-1,100,-100};
	std::vector<int> nums1(myints1, myints1 + sizeof(myints1) / sizeof(int));

	int myints2[] = { 10, 1, 2, 7, 6, 1, 5 };
	std::vector<int> nums2(myints2, myints2	 + sizeof(myints2) / sizeof(int));

	char myints3[] = {'.','1','2','3','.','5','6','8','9'};
	std::vector<char> nums3(myints3, myints3 + sizeof(myints3) / sizeof(char));

	//ListNode* l1 = BuildList(nums1);
	//ListNode* l2 = BuildList(nums2);
	//ListNode* l3 = BuildList(nums3);
	//DisplayLiseNode(l1);
	//DisplayLiseNode(l2);
	//DisplayLiseNode(l3);

	cout<<t_mSoluton.maxSubArray(nums1)<<endl;
	
	return 0;
}
