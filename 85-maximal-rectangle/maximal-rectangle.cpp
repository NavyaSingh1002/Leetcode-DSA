class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size(), c=matrix[0].size();
        int max_area=0;
        vector<int> heights(c, 0);
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            int curr=largestRectangleHistogram(heights);
            max_area=max(max_area, curr);
        }
        return max_area;
    }

    int largestRectangleHistogram(vector <int> &row) {
        vector<int> nse=nextSmaller(row);
        vector<int> pse=prevSmaller(row);
        int max_area=0;
        for(int i=0; i<row.size(); i++) {
            int width=nse[i]-pse[i]-1;
            int area=width*row[i];
            max_area=max(max_area, area);
        }
        return max_area;
    }

    vector<int> nextSmaller(vector<int> &row) {
        stack<int> st;
        vector<int> ans(row.size(), row.size());
        for(int i=row.size()-1; i>=0; i--) {
            while(!st.empty() && row[st.top()]>=row[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &row) {
        stack<int> st;
        vector<int> ans(row.size(), -1);
        for(int i=0; i<row.size(); i++) {
            while(!st.empty() && row[st.top()]>=row[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
};