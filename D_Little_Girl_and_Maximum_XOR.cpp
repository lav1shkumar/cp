#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
lfind max msb == 100000 and 010000 both in range, then ans == 111111



*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l,r;cin>>l>>r;


    for(int i=62;i>=0;--i){
        int b1 = (l>>i)&1ll;
        int b2 = (r>>i)&1ll;

        if(b1!=b2){
            cout<<(1ll<<(i+1))-1;
            return 0;
        }
    }

    cout<<0;

}