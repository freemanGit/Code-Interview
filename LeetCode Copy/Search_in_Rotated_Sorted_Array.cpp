class Solution {
public:
  int search(int A[], int n, int target) {
    return helper(A,0,n-1,target);
        
  }
    
  int helper(int A[], int left, int right, int target)
  {
    if(left > right) return -1;
    int mid = (left+right)/2;
    if (A[mid] == target) return mid;
    else if (A[left] <= A[mid])  //left part ordered
	{
	    if(target >= A[left] && target <= A[mid])
	      return helper(A,left,mid-1,target);
	    else
	      return helper(A,mid+1,right,target);
	}
	else if (A[mid] < A[left]) //right part ordered
	{
	    if (target >=A[mid] && target <= A[right])
	      return helper(A,mid+1,right,target);
	    else
	      return helper(A,left,mid-1,target);
	}
    return -1;
        
  }
};
