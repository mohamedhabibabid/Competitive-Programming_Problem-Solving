class Solution {
public:
    string clearDigits(string s) {
        string st;

        for(auto c: s){
            if( c>='0' && c<='9'){
                if(st.size()){
                   st.pop_back();
                }
            }else{
                st.push_back(c);
            }
        }
        return st;
    }
};
