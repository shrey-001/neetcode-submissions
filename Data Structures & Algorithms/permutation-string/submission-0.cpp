class Solution {
public:

    bool ifvalid(vector<int>& a, vector<int>& b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26, 0);
        for(char c: s1) a[c-'a']++;

        vector<int> b(26, 0);
        if(s2.size()<s1.size()) return false;
        for(int i=0;i<s1.size();i++){
            b[s2[i]-'a']++;
        }
        for(int i=s1.size()-1;i<s2.size();i++){
            if(ifvalid(a, b)) return true;
            if(i+1<s2.size()){
                b[s2[i+1]-'a']++;
                b[s2[i+1-s1.size()]-'a']--;
            }
        }
        return false;
    }
};
