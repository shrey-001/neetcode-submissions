class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = INT_MIN;

        int n = heights.size();
        int l =0 , r =n-1;

        while(l<r){
            int curr = (r-l)* min(heights[l],heights[r] );
            if(heights[l]>heights[r]) r--;
            else l++;
            ans = max(ans, curr);
            
        }
        return ans;
    }
};
