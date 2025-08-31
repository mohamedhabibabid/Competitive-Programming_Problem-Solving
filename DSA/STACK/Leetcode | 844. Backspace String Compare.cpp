class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for(auto c:s){
            if(st1.size() && c=='#'){
                st1.pop();
            }else if(c!='#'){
                st1.push(c);
            }
        }
        for(auto c:t){
            if(st2.size() && c=='#'){
                st2.pop();
            }else if(c!='#'){
                st2.push(c);
            }
        }
        return st1==st2;
    }
};
