class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int j=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                if(j>0)
                    ans=ans+s[i];
                j++;
            }
            else
            {
                j--;
                if(j>0)
                    ans=ans+s[i];
            }
        }
        return ans;
    }
};