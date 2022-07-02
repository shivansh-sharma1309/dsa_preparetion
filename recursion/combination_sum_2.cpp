/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

                                // JAI MATA DI 

class Solution {
public:
    
    void func(int src,vector<int> &candidates,int target,vector<int> temp,vector<vector<int>> &result)
    {
        if(target < 0)
        {
            return;
        }
        
        if(target == 0)
        {
            result.push_back(temp);
            return ;
        }
        
        for(int i=src;i<candidates.size();i++)
        {
            if(i==src || candidates[i] != candidates[i-1])
            {
                temp.push_back(candidates[i]);
                func(i+1,candidates,target - candidates[i],temp,result);
                temp.pop_back();
            }
        }
        return;
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        for(int i=0;i<candidates.size();i++)
        {
            if(i == 0 || candidates[i] != candidates[i-1])
            {
                temp.push_back(candidates[i]);
                func(i+1,candidates,target - candidates[i],temp,result);
                temp.pop_back();
            }
        }
        return result;
    }
};