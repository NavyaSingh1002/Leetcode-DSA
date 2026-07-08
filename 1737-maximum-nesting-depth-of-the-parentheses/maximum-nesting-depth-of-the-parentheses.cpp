class Solution {
public:
    int maxDepth(string s) {
        int c=0, d=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                c++;
                d=max(c, d);
            }
            else if(s[i]==')')
                c--;
        }
        return d;
    }
};