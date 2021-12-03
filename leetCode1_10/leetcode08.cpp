class Solution {
public:
    int myAtoi(string s) {
        int k=0;
        while(k<s.size() && s[k]==' ') k++;      //过滤空白字符
        if (k==s.size()) return 0;
        int flag=1;         //默认符号为正
        if (s[k]=='-') flag=-1,k++;
        else if (s[k]=='+') k++;

        long long res=0;
        while(k<s.size() && s[k]>='0' && s[k]<='9')
        {
            res=res*10+s[k]-'0';
            k++;
            if (res>INT_MAX) break;
        }
        res*=flag;
        if (res>INT_MAX) res=INT_MAX;
        else if (res<INT_MIN) res=INT_MIN;

        return res;
    }
};