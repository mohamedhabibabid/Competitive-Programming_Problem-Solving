class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        if (numRows>1){
            ans.push_back({1,1});
        }
        for(int i=2; i<numRows;i++){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=1; j<i;j++){
                tmp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);

        }
        return ans;
    }
};
