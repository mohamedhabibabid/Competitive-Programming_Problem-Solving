class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto c: s){
            if(st.size() && st.top()=='A' && c=='B'){
                st.pop();
            }else if(st.size() && st.top()=='C' && c=='D'){
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.size();
    }
};
