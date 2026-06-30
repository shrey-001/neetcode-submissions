class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int target, vector<int>& temp, int i, int currSum){
        if(target == currSum){
            ans.push_back(temp);
            return;
        }
        if(i>=nums.size()) return;
        if(currSum>target) {
            return;
        }
        temp.push_back(nums[i]);
        backtrack(nums, target, temp, i, currSum+nums[i]);
        temp.pop_back();
        backtrack(nums, target, temp, i+1, currSum);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        backtrack(nums, target, temp, 0, 0);

        return ans;
        
    }
};
