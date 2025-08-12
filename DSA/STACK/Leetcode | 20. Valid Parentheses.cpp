class Solution {
public:
    bool isValid(string s) {
        stack<char> opened;
        map<char,char> opp{
            {'{','}'},
            {'(',')'},
            {'[',']'}
        };

        for(int i=0 ; i< s.size();i++){
            if (s[i]==']' or s[i]=='}' or s[i]==')'){
                if(opened.empty()){
                    return false;
                }

                //stack mouch fer8a 
                //taskira wel ma7loula mch kifkif
                if(opp[opened.top()]!=s[i]){
                    return false;
                }

                opened.pop();
            }else{
                opened.push(s[i]);
            }
        }
        return opened.size()==0;
    }
};
