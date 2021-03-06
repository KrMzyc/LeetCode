class Solution {
public:

    vector<string> ans;
    string str[10]=
    {
        "","",
        "abc","def","ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        dfs(digits,0,"");
        return ans;
    }

    void dfs(string &digits,int u, string path)
    {
        if(u==digits.size()) ans.push_back(path);
        else 
        {
            for (auto c:str[digits[u]-'0'])
                dfs(digits,u+1,path+c);
        }
    }
};