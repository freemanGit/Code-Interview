// DataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.cpp"
#include "CodePractice.cpp"
#include "KnightTour.cpp"
#include "8Queen.cpp"
#include <algorithm>
#include <functional>
#include <string>
#include <regex>
//#include "P2.cpp"

int _tmain(int argc, _TCHAR* argv[])
{
	//typedef Queue<int> myQueue;
#pragma region Queue	

	Queue<int>* q1 = new Queue<int>;
	q1->Display();

	q1->Enqueue(1);
	q1->Enqueue(56);
	q1->Enqueue(30);
	q1->Display();
    std::cout<<"dequeue "<< q1->Dequeue()<<"\n";
	std::cout<<"dequeue "<< q1->Dequeue()<<"\n";
	//std::cout<<"dequeue "<< q1.Dequeue()<<"\n";
    q1->Display();
	//delete q1;
	/*Queue<int> q2;
	q2.Enqueue(3);
	Queue<int> q3(q2);*/

#pragma endregion

	std::cout<<"\n\n";

#pragma region stl: container&algrithm

	//copy from an array
	int myArr[] = {16,2,56,8,6};
    std::vector<int> vec1(myArr,myArr+sizeof(myArr)/sizeof(int));
	vec1.push_back(42);

	for(std::vector<int>::iterator iter = vec1.begin(); iter < vec1.end(); ++iter)
		std::cout << *iter<<"  ";

	std::cout<<"\n";
	std::vector<int>::iterator it = vec1.begin();
	vec1.insert(it+1,66);

	for(std::vector<int>::iterator iter = vec1.begin(); iter < vec1.end(); ++iter)
		std::cout << *iter<<"  ";

	std::cout<<"\n";
	std::vector<int>::iterator findIt = std::find(vec1.begin(),vec1.end(),21);
	if(findIt == vec1.end())  //not find go to the end of iterator
		std::cout<<"not find"<<"\n";
	else
	{
		std::cout<<"find at position "<<findIt-vec1.begin()<<" with value "<<*findIt<<"\n";
		vec1.insert(findIt,777); //insert into front of find position
		for(std::vector<int>::iterator iter = vec1.begin(); iter < vec1.end(); ++iter)
		std::cout << *iter<<"  ";  //run time error if not find; vector iterator not dereferencable
	}

	std::cout<<"\n";
	std::sort(vec1.begin(),vec1.end());  //sort and changed original vector
	for(std::vector<int>::iterator iter = vec1.begin(); iter < vec1.end(); ++iter)
		std::cout << *iter<<"  ";

#pragma endregion

	std::cout<<"\n\n";

#pragma region median_of_two_sorted_arrays

	int a1[]={1,2,3,4,6};
	int a2[]={7,8,9,10,11};
	int m = sizeof(a1)/sizeof(int);
	int n = sizeof(a2)/sizeof(int);

	std::cout <<"median is "<<median_of_two_sorted_arrays1(a1,m,a2,n);
#pragma endregion

	std::cout<<"\n\n";

#pragma region fin_kth_smallest
	int arr1[]={12,2,4,41,6};
	int k = 2;
	std::cout <<"kth smallest is "<<find_kth_smallest(arr1,0,4,k);

	//int arr2[]={12,2,4,41,6};
	//quickSort(arr2,0,size-1);

	//for(int it = 0; it < size; ++it)
	//    std::cout<<arr2[it]<<" ";

#pragma endregion
	std::cout<<"\n\n";

#pragma region Merge Sort
	int arrMerg[] = {21,51,87,99,56,7,5};
	int sizeMerg = 7;
	mergeSortDriver(arrMerg,sizeMerg);
	for (int i = 0; i < sizeMerg; i++)
	{
		std::cout<<arrMerg[i]<<" ";
	}
	std::cout<<"\n";

#pragma endregion

	std::cout<<"random Number: 0 - 99 "<<std::rand()%100<<std::endl;
	std::cout<<"random Number: 1 - 100 "<<std::rand()%100 + 1<<std::endl;
	std::cout<<"random Number: 10 - 29 "<<std::rand()%20 + 10<<std::endl;
	std::cout<<"\n\n";

#pragma region Combination numbers
	std::vector<std::vector<int> > result;
	combinationRun(4,2,result);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
			std::cout<<result[i][j]<<" ";
	    std::cout<<std::endl;
	}
#pragma endregion
	std::cout<<"\n";

#pragma region min and max heaps
	std::priority_queue<int> maxHeap;
	std::priority_queue<int,std::vector<int>,std::greater<int> > minHeap;

	maxHeap.push(5);minHeap.push(5);
	maxHeap.push(3);minHeap.push(3);
	maxHeap.push(8);minHeap.push(8);
	maxHeap.push(2);minHeap.push(2);
	maxHeap.pop();minHeap.pop();
	std::printf("maxHeap output->%d, minHeap output->%d",maxHeap.top(),minHeap.top());

#pragma endregion
	std::cout<<"\n";

#pragma region find a specific sum
	int target = 10;
    int array2[]={1,3,5,2,11,6};

	std::printf("result is %d",findSum(array2,6,target));

#pragma endregion
	std::cout<<"\n"<<"\n";


#pragma region generate pascals triangle
	int level =14;
	std::vector<std::vector<int> > res = PascalTriangle(level);
	for (int i = 0; i< res.size();++i)
	{
		for (int j = 0; j< res[i].size(); ++j)
			std::cout<<res[i][j]<<" ";
		std::cout<<std::endl;
	}

#pragma endregion
	std::cout<<"\n\n";


#pragma region valid parentheses
	char *tester="asdf(ytr}[iuy]{ytr})";
	std::cout<<isValidParentheses(tester) ? "true":"false";

#pragma endregion
	std::cout<<"\n\n";

#pragma region subset
	int tmp[]={1,2,3};
	std::vector<int> s(tmp,tmp+sizeof(tmp)/sizeof(int));
	std::vector<std::vector<int> > resSubset = subsets2(s);
	for (int i = 0; i<resSubset.size();++i)
	{
		for (int j = 0; j< resSubset[i].size();++j)
			std::cout<<resSubset[i][j]<<" ";
		std::cout<<std::endl;
	}

	for (auto itr = s.begin(); itr != s.end(); ++itr)
	{
		std::cout << *itr<< "E   ";
	}

#pragma endregion
	std::cout<<"\n\n";

#pragma region XOR
	int xorArray[9]={5,6,3,5,3,6,5,3,5};
	std::cout << findOddNumber(xorArray,9) << std::endl;
#pragma endregion
	std::cout<<"\n";

#pragma region Knight Tour Question
	//std::cout<<"Tour Start"<<std::endl;
	KnightTour();
	//std::cout<<"Tour End"<<std::endl;
#pragma endregion
	std::cout<<"\n";

#pragma region 8 Queen
	//std::cout<<"Tour Start"<<std::endl;
	EightQueen();
	//std::cout<<"Tour End"<<std::endl;
#pragma endregion
	std::cout<<"\n";

#pragma region subset sum
  int set[] = {2,3};
  int sum = 5;
  int ns = 2;
  std::vector<std::vector<bool> >  subset(sum+1, std::vector<bool>(ns+1));

  if (isSubsetSum1(set, ns, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");

#pragma endregion
	std::cout<<"\n";
	std::cout<<"\n";


#pragma region hashtable unodered_map
    std::unordered_map<char*, int> hashMap;
	hashMap.insert(std::pair<char*,int>("apple",1));
	hashMap.insert(std::pair<char*,int>("orange",1));

	char* tar = "appe";
	std::unordered_map<char*, int>::iterator got = hashMap.find(tar);
	if (got != hashMap.end())
	{
		(got->second)++;
	}
	else
	{
		hashMap.insert(std::pair<char*, int>(tar,1));
	}
		
	for(auto gg = hashMap.begin(); gg != hashMap.end(); ++gg)
		std::cout << gg->first <<" "<<gg->second<<std::endl;

#pragma endregion
	std::cout<<"\n";

#pragma region reg_match
	std::string toFind = "P";
	std::regex reg ("[a-zA-Z]");
	if (std::regex_match(toFind,reg))
		std::cout << "string object matched"<<std::endl;
	else
		std::cout << "string object not matched"<<std::endl;
#pragma endregion
	std::cout<<"\n";

#pragma region bit ops
    int ww = 6;
	while (ww>1)
	{
		if(ww&1 != 0)
		{
			std::cout<<"not pow of 2"<<std::endl;
		    break;
		}
		else
		{
			ww >>= 1;
		    std::cout<<ww <<std::endl;
		}
		
	}
#pragma endregion
	std::cout<<"\n";

#pragma region reverse number in binary
    int ori = 0;
	std::cout << reverseInBinary(ori)<<std::endl;
#pragma endregion
	std::cout<<"\n";

	getchar();
	return 0;
}

