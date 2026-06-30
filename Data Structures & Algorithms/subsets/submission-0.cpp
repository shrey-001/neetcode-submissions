class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums,vector<int>& temp, int k){
        if(k>=nums.size()) {
            ans.push_back(temp);
            return;
        }
    
        temp.push_back(nums[k]);
        backtrack(nums, temp, k+1);
        temp.pop_back();
        backtrack(nums, temp, k+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> temp;
        backtrack(nums,temp ,0);
        return ans;
        
    }
};
