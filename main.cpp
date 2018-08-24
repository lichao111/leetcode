#include "./Arry/56.cpp"
#include "./Arry/BinarySearch.cpp"

int main()
{
	Timer t_mTimer;
	t_mTimer.TimeStart();
	Solution t_mSoluton;
	//5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
	int myints11[] =  {3,2,1,0};//{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
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

	//cout<<t_mSoluton.uniquePaths(23,12)<<endl;
	//cout<<t_mSoluton.canJump_tmp(nums11)<<endl;
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
