class Solution {
public:
    int clumsy(int n) {
        int sum=0;
        stack<int> st;
        int opr=0;
        st.push(n);
        for(int i=n-1; i>0 ; i--){
            if(opr==0){
                st.top()*=i;
            }else if(opr==1){
                st.top()/=i;
            }else if(opr==2){
                st.top()+=i;
            }else{
                st.push(-i);
            }
            opr++;
            opr%=4;
        }
        while(st.size()){
            sum+=st.top();
            st.pop();
        }

        return (int)sum;
    }
};
