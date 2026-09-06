class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long s=0;
        vector<int> nse=nextSmaller(arr);
        vector<int> pse=prevSmaller(arr);
        int mod=1e9+7;

        for(int i=0; i<arr.size(); i++) {
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long total_ways=(left*right)%mod;
            long long total=((total_ways*arr[i])%mod);
            s=(s+total)%mod;
        }
        return s;
    }

    vector<int> nextSmaller(vector<int> &arr) {
        stack<int> st;
        vector<int> ans(arr.size(), arr.size());    //(size, default value at each index)
        for(int i=arr.size()-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size(), -1);   //(size, default value at each index)
        for(int i=0; i<arr.size(); i++) {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
};