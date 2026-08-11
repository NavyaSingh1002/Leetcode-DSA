class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        int i=0;
        while(s[i]!='\0') {
            char c=s[i];
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else {
                if(st.empty())
                    return false;
                else if((c==')' && st.top()=='(') || (c=='}' && st.top()=='{') || (c==']' && st.top()=='['))
                    st.pop();
                else
                    return false;
            }
            i++;
        }
        return st.empty();
    }
};