class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char ch: t) mp[ch]++;

        int l =0 ;int count = 0, n = s.size(), head = l;
        int ans = INT_MAX;

        for(int r =0;r<n;r++){
            mp[s[r]]--;
            if(mp[s[r]]>=0){
                count++;
            }
            while(count == t.size()){
                if(r-l+1<ans){
                    head = l;
                    ans = min(ans, r-l+1);
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count--;
                    
                }
                l++;
            }
        }
        return ans==INT_MAX? "": s.substr(head, ans);
    }
};
