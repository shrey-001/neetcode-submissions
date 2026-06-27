class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string s: strs){
            ans+=to_string(s.size());
            ans+='#';
            ans+=s;
        }
        cout<<ans<<" ";
        return ans;
    }
    
    vector<string> decode(string s) {
        vector<string> ans;
        int start = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '#'){
                string num = s.substr(start, i-start);
                int t = stoi(num);
                ans.push_back(s.substr(i+1, t));
                start =i+t+1;
                i = i+t;
            }
        }
        return ans;

    }
};
