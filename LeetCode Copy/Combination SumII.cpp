/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 Each number in C may only be used once in the combination.
 
 Note:
 
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 
 For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 A solution set is:
 [1, 7]
 [1, 2, 5]
 [2, 6]
 [1, 1, 6]  
 
*/ 

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> currList;
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        getCombinationSum(num,target,0,0,currList,res);
        return res;
    }
    
    void getCombinationSum(vector<int> &candi, int target, int currSum, int level, vector<int> currList, vector<vector<int> > &res)
    {
        if(currSum > target) return;
        if(currSum == target)
        {
            res.push_back(currList);
            return;
        }
        
        for (int i = level; i < candi.size(); ++i)
        {
            int sum = currSum + candi[i];
            currList.push_back(candi[i]);
            getCombinationSum(candi,target,sum,i+1,currList,res);  //no
            sum = sum - candi[i];
            currList.pop_back();
            
            while(i<candi.size()-1 && candi[i] == candi[i+1]) i++;  //but why??Need to handle the index and skip duplicate candidate.
        }
        return;
    }
};