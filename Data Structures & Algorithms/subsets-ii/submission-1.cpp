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
        // int  j = i;
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        backtrack(nums, temp, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        backtrack(nums, temp, 0);
        return ans;

        
    }
};
