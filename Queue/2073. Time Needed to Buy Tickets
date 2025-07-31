class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i=0 ; i<tickets.size(); i++){
            q.push(i);
        }

        int time=0; 

        while(tickets[k]){
            int top=q.front();
            q.pop();
            
            tickets[top]--;
            time++;

            if(tickets[top]){
                q.push(top);
            }
            
        }
    return time;
    }
};
