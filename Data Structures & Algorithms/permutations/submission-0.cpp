class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& temp, vector<int>& vis){
        if(temp.size()==nums.size()) {
            ans.push_back(temp); 
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]==1) continue;

            temp.push_back(nums[i]);
            vis[i]=1;
            backtrack(nums, temp, vis);
            temp.pop_back();
            vis[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;

        vector<int> vis(nums.size(), 0);
        backtrack(nums, temp, vis);
        return ans;
        
    }
};
