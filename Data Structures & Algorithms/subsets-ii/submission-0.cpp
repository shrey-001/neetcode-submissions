class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& temp, int i){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }

        

        temp.push_back(nums[i]);
        backtrack(nums, temp, i+1);
        temp.pop_back();
        int  j = i;
        while(j<nums.size() && nums[j]==nums[i]){
            j++;
        }
        backtrack(nums, temp, j);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        backtrack(nums, temp, 0);
        return ans;

        
    }
};
