class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        vector<int> output;
        sort(candidates.begin(), candidates.end());
        helper(result, output, candidates, target, 0, 0);
        return result;
    }
    
    void helper(vector<vector<int>> &result, vector<int> &output, vector<int> &candidates, int target, int index, int sum){
        if(sum == target){
            result.push_back(output);
            return;
        }
        if(sum > target)
            return;
        
        for(int i = index; i < candidates.size(); ++i){
            output.push_back(candidates[i]);
            sum += candidates[i];
            helper(result, output, candidates, target, i, sum);
            output.pop_back();
            sum -= candidates[i];
        }
    }
};