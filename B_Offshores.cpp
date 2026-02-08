#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
he can transfer x and will get y
if a bank have <x he cant transfer, we wanna minimize that


he can pick the one, whose mod with x is gratest, bcz that cant be transfered
then, start transferring... a[i]/x = n, transfer = n*y

wait also x>=y, so prioritize bank with big money?
pick the one with max diff = a[i] - (a[i]/x * y)



*/


void solve(){
    int n,x,y; cin>>n>>x>>y;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    vector<pair<int,int>> p;
    for(int i=0;i<n;++i) p.push_back({a[i]-((a[i]/x)*y),i});

    sort(p.rbegin(),p.rend());

    int idx=p[0].second;

    int ans=0;


    for(int i=0;i<n;++i){
        if(i==idx) ans+=a[i];
        else ans+= (a[i]/x)*y;
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