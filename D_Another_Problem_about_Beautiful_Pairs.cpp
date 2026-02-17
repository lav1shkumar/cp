#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
basically if val is some x, i need to find 1 at x-val pos, 2 at x-2val pos

optimize: problem is the inner loop, for val 1 , 2 , for smaller values

lets say for like, val<=100 i can do it ig



*/

void solve(){
    int n;cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];


    int cnt=0;
    for(int i=0;i<n;++i){
        int val=a[i];

        for(int j=1;j<101;++j){
            int t = i - j*val;
            if(t<0) break;
            if(a[t]==j) cnt++;

        }


        if(val>100){
            for(int pos=i+val,factor=1;pos<n;pos+=val,factor++){
                if(a[pos]==factor) cnt++;
            }
        }




    }

    cout<<cnt<<endl;

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