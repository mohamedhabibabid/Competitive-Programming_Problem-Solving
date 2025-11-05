//https://leetcode.com/problems/design-a-number-container-system/description/
class NumberContainers {
public:

    map<int, int> numbyPOS;        // index, number eli fih 
    map<int, set<int>> num_indxes; // number, set mta3 indexes    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int currPOS=numbyPOS[index];    // current number in the index 
        if(numbyPOS.count(index)){
            num_indxes[currPOS].erase(index);
            if(num_indxes[currPOS].empty()){
                num_indxes.erase(currPOS);
            }
        }
        numbyPOS[index]=number;
        num_indxes[number].insert(index);
    }
    
    int find(int number) {
        if(num_indxes.count(number)){
            return *num_indxes[number].begin();
        }

        return -1;
    }

};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
