
#include "./Arry/54.cpp"

#include "./Arry/BinarySearch.cpp"

int main()
{
	Solution t_mSoluton;
	//5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
	int myints11[] = {1,2,3,4};
	std::vector<int> nums11(myints11, myints11 + sizeof(myints11) / sizeof(int));

	int myints12[] = {5,6,7,8};
	std::vector<int> nums12(myints12, myints12 + sizeof(myints12) / sizeof(int));

	int myints13[] = {9,10,11,12};
	std::vector<int> nums13(myints13, myints13 + sizeof(myints13) / sizeof(int));

	int myints14[] = {13,14,15,16};
	std::vector<int> nums14(myints14, myints14 + sizeof(myints14) / sizeof(int));

	vector<vector<int> > nums1;
	// nums1.push_back(nums11);
	// nums1.push_back(nums12);
	// nums1.push_back(nums13);
	//nums1.push_back(nums14);

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

	Display(t_mSoluton.spiralOrder(nums1));
	
	return 0;
}
