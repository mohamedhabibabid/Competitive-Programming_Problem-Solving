class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int large,small;
        char first,last;
        int ans=0;

        if(x>=y){
            large=x;
            small=y;
            first='a'; last='b';
        }else{
            large=y;
            small=x;
            first='b'; last='a';
        }

        for(int i=0; i<s.size(); i++){
            if(st.size() && st.top()==first && s[i]==last){
                st.pop();
                ans+=max(x,y);
            }else{
                st.push(s[i]);
            }
        }
        string scp="";
        while(!st.empty()){
            scp+=st.top(); //ken test3ml scp=st.top()+scp ti7 TLE 5aterha O(n^2) 
          //Each time you do scp = st.top() + scp, you create a new string and shift all characters → O(n²) in the worst case.
            st.pop();
        }
        reverse(scp.begin(), scp.end());
      
        for(int i=0 ; i<scp.size(); ++i){
            if(st.size() && st.top()==last && scp[i]==first){
                st.pop();
                ans+=min(x,y);
            }else{
                st.push(scp[i]);
            }
        }
        return ans;
    }
};
