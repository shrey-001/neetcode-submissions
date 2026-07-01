class Solution {
public:
    vector<string> ans;
    int k;
    void backtrack(string& s, int n, int m){
        if(n>m) return ;
        if(n<0 || m<0) return;
        if(s.size()==k){
            ans.push_back(s);
            return;
        }
        s+="(";
        backtrack(s, n-1, m);
        s.pop_back();
        s+=")";
        backtrack(s, n, m-1);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp="";
        k=n*2;
        backtrack(temp, n, n);
        return ans;
    }
};
