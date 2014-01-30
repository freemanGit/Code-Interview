#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <climits>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>

static double median_of_two_sorted_arrays1(int A[],int m, int B[], int n)
{
	//int m = sizeof(*A)/sizeof(int);
	//int n = sizeof(*B)/sizeof(int);
	std::priority_queue<int> heap(A,A+m);
    for(int i = 0; i< n; ++i)
		heap.push(B[i]);
	
	if((m+n)%2 != 0) //ood
	{
		int mid = (m+n)/2;
		for(int i =0; i<mid;++i)
			heap.pop();
		return heap.top();
	}
	else //even
	{
		int mid = (m+n)/2;
		for(int i=0;i<mid-1;++i)
			heap.pop();
		int mid1 = heap.top();
		heap.pop();
		int mid2 = heap.top();
		return (mid1+mid2)/2.0;
	}
}

static void quickSort(int arr[], int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

 

      /* partition */

      while (i <= j) {

            while (arr[i] < pivot)

                  i++;

            while (arr[j] > pivot)

                  j--;

            if (i <= j) {

                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;

                  i++;

                  j--;

            }

      };

	  for(int it = left; it<=right; ++it)
	    std::cout<<arr[it]<<" ";
	  std::cout<<"\n";

      /* recursion */

      if (left < j)

            quickSort(arr, left, j);

      if (i < right)

            quickSort(arr, i, right);

}


static int partition_leftPos(int arr[], int leftPos, int rightPos)
{
	int randIndex = std::rand()%(rightPos-leftPos+1);
	int pivot = arr[randIndex];

	int i = leftPos;
	int j = rightPos;
	while (i <= j)
	{
		while (arr[i]<pivot)
			i++;
		while (arr[j]>pivot)
			j--;

		if(i<=j)
		{
			int temp = arr[i];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
			j--;
		}
	}
	return randIndex;
}

static int getMax(int arr[],int leftPos, int rightPos)
{
	int resMax = INT_MIN;
	for (int i = leftPos; i <= rightPos; ++i)
	{
		if (arr[i]>resMax)
			resMax = arr[i];
	}
	return resMax;
}

static int find_kth_smallest(int arr[], int leftPos, int rightPos, int k) 
{
   int leftPartPos = partition_leftPos(arr,leftPos,rightPos);
   int targetPos = k-1;
   if(leftPartPos == targetPos)
	   return getMax(arr,0,leftPartPos);
   if(leftPartPos > targetPos)
	   return find_kth_smallest(arr,leftPos,leftPartPos,k);
   if(leftPartPos < targetPos)
	   return find_kth_smallest(arr,leftPartPos+1,rightPos,k);
}


struct linkNode
{
	linkNode *next;
	int data;
};

//recursive way; time complexity O(n), space O(n)
static linkNode *MergeTwoSortedList1(linkNode *l1, linkNode *l2)
{
	if(!l1) 
		return l2;
	if(!l2)
		return l1;

	linkNode *res;

	if(l1->data<l2->data)
	{
		res = l1;
		res->next = MergeTwoSortedList1(l1->next,l2);
	}
	else
	{
		res = l2;
		res->next = MergeTwoSortedList1(l1,l2->next);
	}
	return res;
}

//loop way; time complexity O(n), space O(1)
static linkNode *MergeTwoSortedList(linkNode *l1, linkNode *l2)
{
	if(!l1) 
		return l2;
	if(!l2)
		return l1;

	linkNode *res;
	if(l1->data < l2->data)
	{
	   res = l1;
	   l1 = l1->next;
	}
	else
	{
       res = l2;
	   l2 = l2->next;
	}

	linkNode *cur = res; //maintain header

	while (l1 && l2)
	{
		if(l1->data < l2->data)
		{
		   cur->next = l1;
		   l1 = l1->next;
		}
		else
		{
           cur->next = l2;
	       l2 = l2->next;
		}
		cur = cur->next;
	}

	if(!l1)
		cur->next = l2;
	else
	    cur->next = l1;

	return res;
}

static void merge(int theArray[],int leftPos, int midPos, int RightPos)
{
	std::vector<int> tempLeft;
	std::vector<int> tempRight;

	for (int i = leftPos; i <= midPos; ++i)
		tempLeft.push_back(theArray[i]);
	for (int i = midPos + 1; i <= RightPos; ++i)
		tempRight.push_back(theArray[i]);

	std::vector<int>::iterator itLeft = tempLeft.begin();
	std::vector<int>::iterator itRight = tempRight.begin();

	while (itLeft!=tempLeft.end() && itRight!=tempRight.end())
	{
		if (*itLeft < *itRight)
		{
			theArray[leftPos++] = *(itLeft++);
		}
		else
		{
			theArray[leftPos++] = *(itRight++);
		}
	}

	while (itLeft!=tempLeft.end())
	{
		theArray[leftPos++]=*(itLeft++);
	}   
	while (itRight!=tempRight.end())
	{
		theArray[leftPos++] = *(itRight++);

	}


}

/*
mergeSort(A,l,r)
  if (l<r)
     mid = (i+r)/2
	 mergeSort(A,l,mid)
	 mergeSort(A,mid+1,r)
	 merge(A,l,mid,r)

*/
static void mergeSort(int theArray[], int leftPos, int rightPos)
{
   int mid;
   if(leftPos < rightPos)
   {
	  mid = (leftPos + rightPos)/2;

      mergeSort(theArray, leftPos,mid);
      mergeSort(theArray, mid+1, rightPos);
      merge(theArray,leftPos,mid,rightPos);
   }
   return;
}

static void mergeSortDriver(int theArray[],int size)
{
	mergeSort(theArray,0,size-1);
}


//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. 
static void combinationRecursion(int n, int k, std::vector<int> part, std::vector<std::vector<int> > &result)
{
	if (part.size() > k)
		return;
	if (part.size() == k)
	{
		if (std::find(result.begin(),result.end(),part) == result.end())
		{
			//std::sort(result.begin(),result.end());
			result.push_back(part);
		}
	}
	else
	{
		for (int i = n; i >= 1; --i)
		{   
			//std::vector<int> tempPart(part);
			//tempPart.push_back(i);
			//combinationRecursion(i-1,k,tempPart,result);

			//if not use temp vector to save current part, backtracking part!
			part.push_back(i);
			combinationRecursion(i-1,k,part,result);
			part.erase(part.end()-1);  
		}

	}

}

static void combinationRun(int n, int k, std::vector<std::vector<int> > &result)
{
	std::vector<int> part;
	combinationRecursion(n,k,part,result);
}

	
//find if a specific sum can be combined with set of 2 in an array
static bool findSum(int arr[], int size, int target)
{
	if (size <= 1)
		return false;

	std::map<int,int> hashMap;
	for (int i = 0; i< size; ++i)
	{
		if (hashMap.find(target - arr[i])==hashMap.end())  // can not find 
		{
			hashMap.insert(std::pair<int,int>(arr[i],1));
		}
		else
			return true;
	}

	return false;

}

//generate Pascal's triangle
static std::vector<std::vector<int> > PascalTriangle(int n)
{
	std::vector<std::vector<int> > res;
	std::vector<int> curr;

	if(n == 0)
	   return res;

	curr.push_back(1);
    res.push_back(curr);
	curr.clear();

	if(n == 1)
		return res;

	for (int i = 1; i<= n-1;++i)
	{   
		curr.push_back(1);
		for (int j = 0; j < res[i-1].size()-1;++j)
		     curr.push_back(res[i-1][j]+res[i-1][j+1]);

		curr.push_back(1);
		res.push_back(curr);
		curr.clear();
	}
	return res;
}

//valid parentheses
//assume we have () {} [] to determine
static bool isValidParentheses(char *str)
{
	if (!str)
		return false;
	if (strlen(str) == 0)
		return true;
	std::stack<char> comp; 
	for (int i = 0; i < strlen(str); ++i)
	{
		if(str[i] == '(' || str[i] == '[' || str[i] == '{')
			comp.push(str[i]);

		switch (str[i])
		{
		case ')':
			if (comp.top() != '(')
				return false;
			else
				comp.pop();
			break;
		case ']':
			if (comp.top() != '[')
				return false;
			else
				comp.pop();
			break;
		case '}':
			if (comp.top() != '{')
				return false;
			else
				comp.pop();
			break; 
		default:
			break;
		}

	}
	return true;
}


//subsets
static std::vector<std::vector<int> > subsets(std::vector<int> &s)
{
	std::vector<std::vector<int> > res;
	std::vector<int> curr;
	std::sort(s.begin(),s.end());
    for (int i = 0; i<s.size();++i)
	{
		for (int iter=i;iter<s.size();++iter)
		{
			curr.push_back(s[iter]);
			res.push_back(curr);
		}
		curr.clear();
	}
	return res;
}

static std::vector<std::vector<int> > subsets2(std::vector<int> &S) 
{
    std::sort(S.begin(), S.end());
    std::vector<std::vector<int> > v(1);
    for(int i = 0; i < S.size(); ++i) {
        int j = v.size();
        while(j-- > 0) {
            v.push_back(v[j]);
            v.back().push_back(S[i]);
        }
    }
    return v;
}

//XOR (^): find odd number in even numbers of array a^b^c^d = a^c^d^b; a^a = 0; 0^b = b
static int findOddNumber(int arr[],int length)
{
	if (length == 0)
		return INT_MIN;
	int res = arr[0];
	for (int i = 1; i < length; ++i)
		res ^= arr[i];
	return res;
}

static bool isSubsetSum1(int set[], int index, int sum)
{
	if (index == 0 && sum != 0)
		return false;
	if (sum == 0)
		return true;

	if (set[index] > sum)
		return isSubsetSum1(set,index-1, sum);

	return isSubsetSum1(set, index-1, sum) || isSubsetSum1(set, index-1, sum - set[index]);
}


// Returns true if there is a subset of set[] with sun equal to given sum
static bool isSubsetSum2(int set[], int n, int sum, std::vector<std::vector<bool> > &subset)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    //bool subset[sum+1][n+1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
    // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          std::cout<<subset[i][j]<<" ";
       printf("\n");
     } 
 
     return subset[sum][n];
}

//reverse number in binary
//1011(11) -> 1101(13)
static int reverseInBinary(int orig)
{
	int res = 0;
	while (orig > 0)
	{
		res <<= 1;
		if (orig & 1 == 1)
			res |= 1;
		orig >>= 1;
	}
	return res;
}

static std::string itoa(int n)
{
	std::string res;
	while (n!=0)
	{
		res.insert(res.begin(),(char)(n%10));
		n=n/10;
	}
	return res;
}

//compress string e.g.  aaabbb
static std::string compressStr(std::string str)
{
	int strlen = str.length();
	if (strlen <=1)
		return str;

	char last = str[0];
	int count = 1;
	std::string res;
	for (int i = 1; i < strlen; i++)
	{
		if (str[i] == last)
		{
			count++;
		}
		else
		{
			res.push_back(last);
			res.append(itoa(count));
			last = str[i];
			count = 1;
		}
	}
	int reslen = res.length();
	return reslen > strlen ? str : res;
}
