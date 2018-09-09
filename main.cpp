//#include "./Arry/79.cpp"
#include "./Algorithm/900.cpp"
//#include "./LinkedList/100.cpp"
//#include "./String/72.cpp"
#include "./Arry/BinarySearch.cpp"

int main()
{
	Timer t_mTimer;
	t_mTimer.TimeStart();
	
	//5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
	int myints11[] =  {3,8,0,9,2,5};
	std::vector<int> nums11(myints11, myints11 + sizeof(myints11) / sizeof(int));

	char myints12[] = {'A'};
	std::vector<char> nums12(myints12, myints12 + sizeof(myints12) / sizeof(char));

	char myints13[] = {'S','F','C','S'};
	std::vector<char> nums13(myints13, myints13 + sizeof(myints13) / sizeof(char));

	char myints14[] = {'A','D','E','E'};
	std::vector<char> nums14(myints14, myints14 + sizeof(myints14) / sizeof(char));

	vector<vector<char> > nums1;

	nums1.push_back(nums12);
	// nums1.push_back(nums13);
	// nums1.push_back(nums14);
	//nums1.push_back(nums14);

	int myints2[] = { 10, 1, 2, 7, 6, 1, 5 };
	std::vector<int> nums2(myints2, myints2	 + sizeof(myints2) / sizeof(int));

	//cout<<t_mSoluton.uniquePaths(23,12)<<endl;
	//cout<<t_mSoluton.canJump_tmp(nums11)<<endl;
	//ListNode* l1 = BuildList(nums11);
	//ListNode* l2 = BuildList(nums2);
	//ListNode* l3 = BuildList(nums3);
	//DisplayLiseNode(l1);
	//DisplayLiseNode(l2);
	//DisplayLiseNode(l3);
	// vector<vector<int> > A;
	// A.push_back(nums12);
	// A.push_back(nums13);
	// //A.push_back(nums14);

	
	RLEIterator a(nums11);
	cout<<a.next(2)<<endl;;cout<<a.next(1)<<endl;;cout<<a.next(1)<<endl;;cout<<a.next(2)<<endl;;



	t_mTimer.TimeStop();
	t_mTimer.TimeUsr();
	return 0;
}
