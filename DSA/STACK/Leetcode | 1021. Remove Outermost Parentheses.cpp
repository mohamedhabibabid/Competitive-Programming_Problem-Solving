class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        int i=0,lpointer=0; // i : to iterate (right pointer); 
                                    // lpointer : left pointer , 
        while(i<s.size()){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                st.pop();
            }
            if(st.empty()){ //if one primitive is done <-> the stack is empty
                ans.append(s.begin()+lpointer+1, s.begin()+i);
                lpointer=i+1;
            }
            i++;
        }
        return ans;
    }
};
