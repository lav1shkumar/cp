#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
    find min m>=n


    solve in logn or logm
    basically and of consecutive numbers till m=x

        a&(a+1)&(a+2)....= x
        means all the set bits in x, were also in all numbers

        00001110101001 + 1 in binary, carry over

        n & n+1 & n+2 ==  m>=n
        100 & 101 == 100
        0111 1000 --> -1
        110  111
        
        n=10,x=8
        1000 == 1010 == 1010 0101 0011 == 1100
    
        001 == 011 == 1
        010 == 011 == 01 +1 == 11

*/


void solve(){
    int n,x;cin>>n>>x;

    if((n&x)!=x){
        cout<<-1<<endl;
        return;
    }
    if(n==x){
        cout<<n<<endl;
        return;
    }

    for(int b=61;b>=0;--b){
        int bit=1ll<<b;
        if(n&bit && !(x&bit)){ // had to remove this bit by min addition
            // 011010 remove 3rd pod 1 to 0
            // 01+1 | 01 = 10 == 11
            int mask = (n>>(b+1))+1ll;
            mask = (mask<<(b+1));
            if((n&mask)==x){
                cout<<mask<<endl;
                return;
            }
            else {
                cout<<-1<<endl;
                return;
            }

        }
    }




}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();

}