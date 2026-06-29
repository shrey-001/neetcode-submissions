class Solution {
public:
    bool isValid(vector<int> mp, int k){
        int maxFreq = *max_element(mp.begin(), mp.end());
        int sum = 0;
        for(int i: mp) sum+=i;

        cout<<sum<<" "<<maxFreq<<endl;

        if(sum-maxFreq>k) return false;
        return true;

    }
    int characterReplacement(string s, int k) {
        vector<int> mp(26, 0);
        int l =0;
        int ans=0;
        for(int r =0;r<s.size();r++){
            mp[s[r]-'A']++;
            while(!isValid(mp, k)){
                mp[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
