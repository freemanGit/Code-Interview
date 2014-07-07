/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 
 For example,
 If n = 4 and k = 2, a solution is:
 
 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]
 
 
*/ 

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> solution;
        vector<vector<int> > res;
        helper(n,k,1,solution,res);
        return res;
    }
    
    void helper(int n, int k, int level, vector<int> &solution, vector<vector<int> > &res)
    {
        if(solution.size() == k)
        {
            res.push_back(solution);
            return;
        }
        
        for(int i = level; i<=n; ++i)
        {
            solution.push_back(i);
            helper(n,k,i+1,solution,res);
            solution.pop_back();  //backtracking
        }
        return;
    }
};
