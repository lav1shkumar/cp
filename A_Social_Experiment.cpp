#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
if n%3==0 then zero 
if n==11, 3 - 3, 1 - 2 ans - 1


if teams are odd or even 
3 group of 2 to --> 2 group of three and vice versa


*/


void solve(){
    int n;cin>>n;

    if(n==2){
        cout<<2<<endl;
        return;
    }
    if(n==3){
        cout<<3<<endl;
        return;
    }
    if(n&1){
        cout<<1<<endl;
        return;
    }
    else{
        cout<<0<<endl;
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