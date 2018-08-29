//#include "./Arry/892.cpp"
#include "./Algorithm/895.cpp"
#include "./Arry/BinarySearch.cpp"

int main()
{
	Timer t_mTimer;
	t_mTimer.TimeStart();
	
	//5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
	int myints11[] =  {4,2};
	std::vector<int> nums11(myints11, myints11 + sizeof(myints11) / sizeof(int));

	int myints12[] = {1,2};
	std::vector<int> nums12(myints12, myints12 + sizeof(myints12) / sizeof(int));

	int myints13[] = {3,4};
	std::vector<int> nums13(myints13, myints13 + sizeof(myints13) / sizeof(int));

	int myints14[] = {0,0,0};
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
	// vector<vector<int> > A;
	// A.push_back(nums12);
	// A.push_back(nums13);
	// //A.push_back(nums14);

	FreqStack *FreqStackl = new FreqStack();
	FreqStackl->push(5);
	FreqStackl->push(7);
	FreqStackl->push(5);
	FreqStackl->push(7);
	FreqStackl->push(4);
	FreqStackl->push(5);

	cout<<FreqStackl->pop()<<endl;
	cout<<FreqStackl->pop()<<endl;
	cout<<FreqStackl->pop()<<endl;
	cout<<FreqStackl->pop()<<endl;

	
	//DisplayVecofVec( t_mSolution->subset(nums11));

	/*TreeNode a(1);TreeNode b(2);TreeNode c(3);
	TreeNode d(4);TreeNode e(5);TreeNode f(6);
	TreeNode g(7);
	a.left=&b;a.right=&c;b.left=&d;b.right=&e;
	c.right=&f;f.left=&g;*/
	

	t_mTimer.TimeStop();
	t_mTimer.TimeUsr();
	return 0;
}
