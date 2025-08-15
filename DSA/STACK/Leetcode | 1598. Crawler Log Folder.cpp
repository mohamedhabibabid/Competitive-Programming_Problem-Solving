#include <bits/stdc++.h>

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> sq;
        int x=0; 
        for(int i=0 ; i< logs.size(); i++){
            if(logs[i]=="../" ){
                x=max(0,x-1);
            }else if(logs[i]!="./"){
                x++;
            }
        }
        
        return max(0,x);
    }
};
