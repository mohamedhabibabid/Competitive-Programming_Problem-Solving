#include <iostream>
using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;
    int ans=0;
    int tracker[]={0,0};
    for(int i=0; i<n;i++){
        int minit,side;
        cin>>minit>>side;
       if(((minit-tracker[0])%2==0 && side==tracker[1])|| ((minit-tracker[0])%2==1 && side!=tracker[1])){
            ans+=minit-tracker[0];
        }else{
            ans+=minit-tracker[0]-1;
        }
        tracker[0]=minit;
        tracker[1]=side;

    }
    ans+=(tracker[0]==m? 0 : m-tracker[0]);
    cout<<ans<<endl;
}
// 1 0 1 0 1 0
// 0 1 0 1 0 1
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
