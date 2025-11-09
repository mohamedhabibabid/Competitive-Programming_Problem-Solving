// https://leetcode.com/problems/my-calendar-i/description/
#define pp pair<int, int> 
class MyCalendar {
public:
    set<pp> st;
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        if(st.size()){
            auto it=st.lower_bound({s,e}); //nearest akber meni wala 9adi
            //auto it=upper_bound({s,e}); //nearest as8er meni
            if( it!=st.end() && e> it->first){
                return 0; 
            }
        
            if(it!= st.begin()){
                it=prev(it);
                if(it->second  > s){
                    return 0;
                }

            }

            
        } 
        st.insert({s, e}); return 1; 

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
