#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
total pos pairs are, kc2, then i can subtract overcounted

kc2 = k*k-1/2

overcounted = is 1 is coming twice, then overcounted = 2-1, count-1


*/


void solve(){
    int a,b,k;cin>>a>>b>>k;

    vector<int> x(k),y(k);
    for(int i=0;i<k;++i) cin>>x[i];
    for(int i=0;i<k;++i) cin>>y[i];

    int total = k*(k-1)/2;

    unordered_map<int,int> mp1,mp2;
    for(int i=0;i<k;++i){
        mp1[x[i]]++;
        mp2[y[i]]++;
    }

    for(int i=1;i<=a;++i){
        int d = mp1[i];
        if(d==0) continue;

        total-=(d*(d-1)/2);
    }

    for(int i=1;i<=b;++i){
        int d = mp2[i];
        if(d==0) continue;

        total-=(d*(d-1)/2);

    }

    cout<<total<<endl;





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