class Solution {
public:
    int beautySum(string s) {
        int b=0;
        for(int i=0; i<s.size(); i++)
        {
            int a[26]={0};
            for(int j=i; j<s.size(); j++)
            {
                a[s[j]-'a']++;
                int maxx=0;
                int minn=INT_MAX;
                for(int k=0; k<26; k++)
                {
                    if(a[k]>0)
                    {
                        maxx=max(a[k], maxx);
                        minn=min(minn, a[k]);
                    }
                }
                b=b+(maxx-minn);
            }
        }
        return b;
    }
};