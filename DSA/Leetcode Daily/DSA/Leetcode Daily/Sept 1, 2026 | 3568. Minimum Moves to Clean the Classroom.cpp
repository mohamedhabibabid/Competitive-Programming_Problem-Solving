// https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/?envType=daily-question&envId=2026-09-01
class Solution {
public:
        int movex[4]={1,-1,0,0};
        int  movey[4]={0,0,1,-1};
        int m,n,k; 

        int minMoves(vector<string>& classroom, int energy) {
            n=classroom.size();
            m=classroom[0].size();
            int sourcex,sourcey; 
            int cntLitter=0;
            vector<vector<int>> litter(n, vector<int> (m));
            for (int i=0; i<classroom.size(); i++){
                for(int j=0; j<classroom[0].size(); j++){
                    if(classroom[i][j]=='S'){
                        sourcex=i;
                        sourcey=j;
                    }
                    if(classroom[i][j]=='L'){
                        litter[i][j]= 1 << cntLitter++;
                    }
                }
            }
            vector dp(n, vector(m,vector<int> (1<<cntLitter, -1)));
            dp[sourcex][sourcey][0]=energy;
            struct State{
                int x,y;
                int mask;
                int energy;
                int moveCount;
            };
            queue<State> q;
            q.push({sourcex,sourcey,0,energy,0});
            while(!q.empty()){
                State s=q.front();
                q.pop();
                if(s.mask == (1<<cntLitter) -1 ){
                    return s.moveCount;
                }
                if(s.energy==0){
                    continue;
                }
                for(int i=0; i<4; i++){
                    int newx=s.x+movex[i];
                    int newy=s.y+movey[i];

                    if(newx<0 || newy<0 || newx>=n || newy>=m || classroom[newx][newy]=='X'){   
                        continue;
                    }

                    int newEnergy= classroom[newx][newy] =='R'? energy: s.energy-1;
                    int newMask = s.mask | litter[newx][newy];

                    if(newEnergy > dp[newx][newy][newMask]){
                        dp[newx][newy][newMask]= newEnergy;
                        q.push({newx,newy,newMask,newEnergy,s.moveCount+1});
                    }
                }
            }
            return -1;
        }

    
};
