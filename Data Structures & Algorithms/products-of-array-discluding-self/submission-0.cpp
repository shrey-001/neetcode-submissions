class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n,1), rightProduct(n,1);
        for(int i=1;i<nums.size();i++){
            leftProduct[i] = leftProduct[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            rightProduct[i] = rightProduct[i+1]*nums[i+1];
        }
        vector<int> ans(n,0);
        for(int i=0;i<nums.size();i++){
            ans[i] = leftProduct[i]*rightProduct[i];
        }
        return ans;
    }
};
