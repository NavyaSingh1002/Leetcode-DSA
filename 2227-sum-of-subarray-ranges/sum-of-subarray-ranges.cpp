class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return (maximum(nums)-minimum(nums));
    }

    long long minimum(vector<int> &nums) {
        vector<int> nse=nextSmaller(nums);
        vector<int> pse=prevSmaller(nums);
        long long s=0;
        for(int i=0; i<nums.size(); i++) {
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long total=(left*right*nums[i]);
            s=s+total;
        }
        return s;
    }

    long long maximum(vector<int> &nums) {
        vector<int> nge=nextGreater(nums);
        vector<int> pge=prevGreater(nums);
        long long s=0;
        for(int i=0; i<nums.size(); i++) {
            long long left=i-pge[i];
            long long right=nge[i]-i;
            long long total=(left*right*nums[i]);
            s=s+total;
        }
        return s;
    }

    vector<int> nextSmaller(vector<int> &nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            else
                ans[i]=nums.size();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && nums[st.top()]>nums[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            else
                ans[i]=-1;
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGreater(vector<int> &nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            else
                ans[i]=nums.size();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreater(vector<int> &nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && nums[st.top()]<nums[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            else
                ans[i]=-1;
            st.push(i);
        }
        return ans;
    }
};