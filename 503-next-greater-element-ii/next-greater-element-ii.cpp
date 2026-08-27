class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::stack<int> st;
        vector<int> ans(nums.size());
        int i=nums.size()*2-1;
        while(i>=0) {
            int j=i%nums.size();
            while(!st.empty() && st.top()<=nums[j])
                st.pop();
            if(i<nums.size()) {
                if(st.empty())
                    ans[j]=-1;
                else
                    ans[j]=st.top();
            }
            st.push(nums[j]);
            i--;
        }
        return ans;
    }
};