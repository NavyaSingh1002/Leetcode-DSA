class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int a[256]={0}, b[256]={0};
        for(int i=0; i<s.length(); i++)
        {
            char chs=s[i], cht=t[i];
            if(a[chs]!=0 && a[chs]!=cht)
                return false;
            if(b[cht]!=0 && b[cht]!=chs)
                return false;
            a[chs]=cht;
            b[cht]=chs;
        }
        return true;
    }
};