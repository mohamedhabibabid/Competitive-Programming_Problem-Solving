class Solution {
public:
    int maxDepth(string s) {
        int ans=0; 
        int temp=0;
        for(auto x: s){
            if(x =='('){
                temp++;
            }
            else if(x==')'){
                ans=max(temp,ans);
                temp--;
            }
        }
        return ans;
    }
};
