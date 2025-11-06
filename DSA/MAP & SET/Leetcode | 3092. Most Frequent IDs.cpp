//https://leetcode.com/problems/most-frequent-ids/
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<long long,long long> frq; //frq, total number 
        map<long long,long long> mp; // id, frequencey sum
        int n=nums.size();
        vector<long long> a(n);
        for(int i=0; i< nums.size(); i++){
            int x=nums[i];
            if(frq[mp[x]]){ //i4a lfrq heki mawjouda na9sou ml counter mte3ha we7ed 
                frq[mp[x]]--;
                if(frq[mp[x]]==0){ // counter mta3 lfreq heki 0 donc tetfs5 
                    frq.erase(mp[x]);
                }
            }
            if(mp[x]+freq[i]==0){
                mp.erase(x);
            }else{
                mp[x]+=freq[i];
                frq[mp[x]]++;
            }
            a[i] = frq.empty() ? 0 : frq.rbegin()->first;
        }
        return a; 
    }
};
