class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char c: s)
        {
            m[c]++;
        }
        vector<string> buckets(s.size()+1, "");
        for(auto it: m)
        {
            char ch=it.first;
            int freq=it.second;
            buckets[freq].append(freq, ch);
        }
        string ans="";
        for (int i=s.size(); i>=1; i--)
        {
            if(!buckets[i].empty())
                ans=ans+buckets[i];
        }
        return ans;
    }
};