//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 

        for(auto c:s){
            if(c!='c'){
                st.push(c);
            }else{
                if(st.size()<2 || st.top()!='b'){
                    st.push(c);
                }else{
                    st.pop();
                    if(st.top()=='a'){
                        st.pop();
                    }else{
                        st.push('b');
                        st.push(c);
                    }
                }
            }
        }
        return st.empty();
    }
};
