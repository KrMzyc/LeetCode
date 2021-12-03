class Solution {
public:
    bool isPalindrome(int x) {
        // if (x<0) return 0;
        // else
        // {
        //     string s=to_string (x);
        //     return s==string(s.rbegin(),s.rend());
        // }                  //转换为字符串再倒置判断
        
        if (x<0) return 0;
        long long res=0,x1=x;
        while(x)
        {
            res=res*10+x%10;
            x/=10;
        }

        return res==x1;
    }
};