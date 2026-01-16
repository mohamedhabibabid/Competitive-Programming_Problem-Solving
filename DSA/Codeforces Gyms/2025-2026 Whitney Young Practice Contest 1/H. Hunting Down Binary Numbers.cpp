#include "bits/stdc++.h"
#include <bit>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vcl vector<ll>
#define str string
  

//-----------------solve function------------------//
    void solve() {
        // make xor of all bits less than the highest bit of l to 1 -> h-1 bits
        // h is on in L so h should be 0 in B && h+1 should be on in B -> h+1 bits in total of x 
        // if h<x set all higher bits of b to 1 until count=x (ya3ni mel h+2 to 60th bit set it on)
        ll l, x;  
        cin>>l>>x;
        ll a=l, b=l,  bit=0; 
        ll count=0; 
        ll h=0; // highest bit of l   
        for(ll bit=60 ; bit>=0; bit--){
            if((l & (1LL << bit)) !=0){
               h=bit;
               break;
            }
        }
        // // b|=((1LL << (h))-1); // set all bits lower than h to 1 in B 
        b|=(1LL << (h+1)); // set h+1 th bit to 1 in B 
        // // b&= ~(1LL << h);
        // b|=((1LL << (h+1)));  
        count+=1; 
        // ---- Explanation --- 
        // te5ou el a = l 
        // Bch t7awel tasna3 el b mel L 
        // bch tchouf el most significant bit fl A= l  , n9oulou h  // highest bit 
        // bch te5ou juste lbit li ba3dou h+1 wtsetih on bch twali el B akber mel A 
        // mb3d titerati mel 0th bit 7ata lel h wtflipi lbit li yo3r4k fl B (3aks el A) 
        // bch lXOR mte3hm ta3tik 1  : te9ef ki tlem (x-1) bits , 5ater deja 3andek lbit h+1 fl B on woff fl A

        for(ll bit=0; bit<=h && count<x ; bit++){  
            if((l & (1LL << bit))==0){ // if bit is on 
                
                b|=(1LL << (bit)); //set bit to 1
            }else{
                b&= ~(1LL << bit); // set bit to 0
            }
            count++;
        }
        bit=h+2;
        while(count<x){ 
            b|=(1LL << bit);
            count++;
            bit++;
        }
   
        cout<<min(a,b)<<' '<<max(a,b)<<endl;  
    }


//------------------------------------------------//
int main() {
    fast;
    int t = 1;
    cin>>t; 
    while (t--) solve();
    return 0;
}
 
