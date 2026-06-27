class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(auto str: strs){
            vector<int> temp(26, 0);
            for(char i: str){
                temp[i-'a']++;
            }
            mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
