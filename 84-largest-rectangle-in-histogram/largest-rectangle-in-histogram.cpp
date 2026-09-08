class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nse=nextSmaller(heights);
        vector<int> pse=prevSmaller(heights);
        int max_area=0;
        for(int i=0; i<heights.size(); i++) {
            int width=nse[i]-pse[i]-1;
            int area=width*heights[i];
            max_area=max(max_area, area);
        }
        return max_area;
    }

    vector<int> nextSmaller(vector<int> &heights) {
        stack<int> st;
        vector<int> ans(heights.size(), heights.size());
        for(int i=heights.size()-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &heights) {
        stack<int> st;
        vector<int> ans(heights.size(), -1);
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
};