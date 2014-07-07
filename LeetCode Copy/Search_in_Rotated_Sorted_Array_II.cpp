class Solution {
public:
  bool search(int A[], int n, int target) {
        
    return helper(A,0,n-1,target);
  }
  bool helper(int A[], int left, int right, int target)
  {
    if (left > right) return false;
    int mid = (left+right)/2;
    if (A[mid] == target) return true;
    if (A[left] < A[mid])
	{
	  if (target >= A[left] && target <=A[mid])
	    return helper(A,left,mid-1,target);
	  else
	    return helper(A,mid+1,right,target);
	}
    else if (A[mid] < A[left])
	{
	  if(target >= A[mid] && target<=A[right])
	    return helper(A,mid+1,right,target);
	  else
	    return helper(A,left,mid-1,target);
	}
    else if (A[mid] == A[left])
	{
	  if(A[mid] != A[right])//[1,1,4,5]
	    return helper(A,mid+1,right,target);
	  else
	  {
	    bool resTmp = helper(A,left,mid-1,target);//[1,3,1,1], have to search left one by one..
	    if (!resTmp)//[1,1,3,1], then have to try search right one by one
	      return helper(A,mid+1,right,target);
	    else 
	      return resTmp;
                
	  }
	}
    return false;
        
  }
};
