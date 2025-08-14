class Solution {  
public:
    string largestGoodInteger(string num) {
    int mx=-1;

    for(int i=0 ; i< num.size(); i++){
        if(i+2<num.size() && num[i]==num[i+1] && num[i+1]==num[i+2]){
            mx=max(mx, int(num[i]));
        }
    }
    if(mx==-1){
        return "";
    }
    
    return string(3,char(mx));
    }
};
