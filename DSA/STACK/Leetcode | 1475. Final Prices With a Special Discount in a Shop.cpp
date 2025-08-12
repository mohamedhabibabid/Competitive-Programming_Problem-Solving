class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> ind;
        vector<int> ans=prices;

        for(int i=0 ; i<prices.size(); i++)
        {      
            int price=prices[i];          
            while(ind.size() and prices[ind.top()]>=price){ // tric enou ken stack m3ebi wyel9a we7ed as8r mel top, 
          // el as8ar heka yejm maykounch juste lel top houwa el as8ar lbarsha 
          //elements -> bch yn4f el stack 
                ans[ind.top()]-=price;
                ind.pop();
            }
          // yejm ykoun mazel fama elemnts fel stack ken el price akbar menhm
            ind.push(i);
           
        }

    return ans;

    }

};
