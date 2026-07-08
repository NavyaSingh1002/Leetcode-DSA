class Solution {
public:
    int myAtoi(string s) {
        int ans=0, sign=1, i=0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(i<s.length() && (s[i]=='+' || s[i]=='-'))
        {
            if(s[i]=='-')
                sign=-1;
            i++;
        }
        while(i<s.length() && s[i]>='0' && s[i]<='9')
        {
            int d=s[i]-'0';
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && d>INT_MAX%10))
                return (sign==1)?INT_MAX:INT_MIN;
            ans=ans*10+d;
            i++;
        }
        return ans*sign;
    }
};