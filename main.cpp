#include "./Algorithm/52.cpp"
#include "./Arry/BinarySearch.cpp"

int main()
{
	Solution t_mSoluton;
	//5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
	int myints11[] = {6,13,2,15,1,25,12,30,14,26,13,18,37,6,5,9,31,33,22,29};
	std::vector<int> nums11(myints11, myints11 + sizeof(myints11) / sizeof(int));

	int myints12[] = {10,1,2,7,6,1,5};
	std::vector<int> nums12(myints12, myints12 + sizeof(myints12) / sizeof(int));

	int myints13[] = {9,10,11,12};
	std::vector<int> nums13(myints13, myints13 + sizeof(myints13) / sizeof(int));

	int myints14[] = {13,14,15,16};
	std::vector<int> nums14(myints14, myints14 + sizeof(myints14) / sizeof(int));

	vector<pair<int,int> > nums1;
	nums1.push_back(make_pair(2,2));
	nums1.push_back(make_pair(5,4));

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

	vector<string> aaa;
	aaa.push_back("abc");
	aaa.push_back("deq");
	aaa.push_back("mee");
	aaa.push_back("aqq");
	aaa.push_back("dkd");
	aaa.push_back("ccc");


	//DisplayVecofVec(t_mSoluton.solveNQueens(8));

	cout<<t_mSoluton.totalNQueens(5)<<endl;

	return 0;
}
