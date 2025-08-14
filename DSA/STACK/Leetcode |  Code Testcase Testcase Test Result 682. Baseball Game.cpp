class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s; 
        vector<int> record; 
        int ans=0; 
        for(int i=0; i< operations.size(); i++){
            int n=record.size();
            if(operations[i]=="+"){
                record.push_back(record[n-1]+record[n-2]);
                ans+=record[n];
            }
            else if(operations[i]=="D"){
                record.push_back(record[n-1]*2);
                ans+=record[n];
            }else if(operations[i]=="C"){
                record.pop_back();
                ans-=record[n-1];
            }else{
                record.push_back(stoi(operations[i]));
                ans+=record[n];
            }
        }
        
        return ans;
    }
};
