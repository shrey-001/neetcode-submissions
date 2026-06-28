class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int leftMin = prices[0];
        for(int i =1 ;i<n;i++){
            if(prices[i]>leftMin) ans = max(ans, prices[i]-leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        return ans;
    }
};
