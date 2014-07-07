/*
 Given a collection of numbers, return all possible permutations.
 
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].  
 
*/


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        helper(num,0, res);
        return res;
    }
    
    void helper(vector<int> &num, int pivot, vector<vector<int> > &res)
    {
        if(pivot >= num.size()-1)
        {
            res.push_back(num);
            return;
        }
        
        for(int i = pivot; i< num.size(); ++i)
        {
            swap(num[pivot],num[i]);
            helper(num,pivot+1,res);
            swap(num[pivot],num[i]);
        }
        
        return;
    }
};