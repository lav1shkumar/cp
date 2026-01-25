#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
score = x*no of levels com

to go next lvl : bi strikes, sword can strike once

basically: pick x , avl swords = >=x str
now pref sum of b is how many sword i need to reach ith lvl,
i need to max both

can i bs on x?
if 5 sword can do 3 lvl, then >4 can also

sword kam == x jyada

what is optimal here?
    no of sword need to complete till i lvl = pref[i], i need to pick max x, pick



score == 3
4 3 1
2 1 1

5 4 4 4 4 1
2 2 4 1 2 2
2 4 8 9 11 13
score = 8

*/


void solve(){
    int n;cin>>n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> pref(n);

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];

    pref[0]=b[0];
    for(int i=1;i<n;++i) pref[i]=pref[i-1]+b[i];


    sort(a.rbegin(),a.rend());

    int ans=0;

    for(int i=0;i<n;++i){
        int need = pref[i];
        if(need<=n){
            int x = a[need-1]; // x should be i
            ans=max(ans,x*(i+1));
        }
        else break;
    }
    cout<<ans<<endl;
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