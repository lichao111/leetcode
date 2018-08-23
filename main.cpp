#include "./Algorithm/62.cpp"
#include "./Arry/BinarySearch.cpp"

int main()
{
	Timer t_mTimer;
	t_mTimer.TimeStart();
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

	char myints3[] = {'5','3','.','.','7','.','.','.','.'};
	std::vector<char> nums3(myints3, myints3 + sizeof(myints3) / sizeof(char));
	char	 myints4[] = {'6','.','.','1','9','5','.','.','.'};
	std::vector<char> nums4(myints4, myints4 + sizeof(myints4) / sizeof(char));
	char		 myints5[] = {'.','9','8','.','.','.','.','6','.'};
	std::vector<char> nums5(myints5, myints5 + sizeof(myints5) / sizeof(char));
	char			 myints6[] = {'8','.','.','.','6','.','.','.','3'};
	std::vector<char> nums6(myints6, myints6 + sizeof(myints6) / sizeof(char));
	char				 myints7[] = {'4','.','.','8','.','3','.','.','1'};
	std::vector<char> nums7(myints7, myints7 + sizeof(myints7) / sizeof(char));
	char					 myints8[] = {'7','.','.','.','2','.','.','.','6'};
	std::vector<char> nums8(myints8, myints8 + sizeof(myints8) / sizeof(char));
	char						 myints9[] = {'.','6','.','.','.','.','2','8','.'};
	std::vector<char> nums9(myints9, myints9 + sizeof(myints9) / sizeof(char));
	char						 myints10[] = {'.','.','.','4','1','9','.','.','5'};
	std::vector<char> nums10(myints10, myints10 + sizeof(myints10) / sizeof(char));
	char						 myints15[] = {'.','.','.','.','8','.','.','7','9'};
	std::vector<char> nums15(myints15, myints15 + sizeof(myints15) / sizeof(char));
	vector<vector<char> > board;
	board.push_back(nums3);
	board.push_back(nums4);
	board.push_back(nums5);
	board.push_back(nums6);
	board.push_back(nums7);
	board.push_back(nums8);
	board.push_back(nums9);
	board.push_back(nums10);
	board.push_back(nums15);

	cout<<t_mSoluton.uniquePaths(23,12)<<endl;
	//ListNode* l1 = BuildList(nums1);
	//ListNode* l2 = BuildList(nums2);
	//ListNode* l3 = BuildList(nums3);
	//DisplayLiseNode(l1);
	//DisplayLiseNode(l2);
	//DisplayLiseNode(l3);

	
	t_mTimer.TimeStop();
	t_mTimer.TimeUsr();
	cout<<"----------------------------"<<endl;
	return 0;
}
