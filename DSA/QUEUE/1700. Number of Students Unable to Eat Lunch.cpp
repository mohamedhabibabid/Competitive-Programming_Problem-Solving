class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       queue<int> q(students.begin(),students.end());
       stack<int>s(sandwiches.rbegin(), sandwiches.rend());
       for(int i=0; i< students.size(); i++){
            q.push(i);
            s.push(i);
       } 
       int stayed=0;
       while(!q.empty() && stayed<q.size()){
        int frq=q.front();
        int tops=s.top();
        if(frq==tops){
            q.pop();
            s.pop();
            stayed=0;
        }
        else{
            q.pop();
            q.push(frq);
            stayed++;
        }
       }
       return stayed;
    }
};
