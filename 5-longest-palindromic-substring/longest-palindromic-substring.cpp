class Solution {
public:
    string longestPalindrome(string s) {
        int maxl=0, j=0;
        for(int i=0; i<s.size(); i++)
        {
            int l1=expand(s, i, i);
            int l2=expand(s, i, i+1);
            int l=max(l1, l2);
            if(l>maxl)
            {
                maxl=l;
                j=i-(l-1)/2;
            }
        }
        return s.substr(j, maxl);
    }

    int expand(const string& s, int left, int right)
    {
        while(left >=0 && right<s.size() && s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
};