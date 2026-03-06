#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

4-3  3
5-2  5
6-1  6


*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    vector<pair<int,int>> p(n);

    for(int i=0;i<n;++i) cin>>p[i].first>>p[i].second;

    sort(p.begin(),p.end());

    // this order enforced, now i need to manage bi's

    int ans=p[0].second;
    for(auto [a,b]:p){
        if(b>=ans){
            ans=b;
            continue;
        }
        else{
            ans=a;
        }
    }

    cout<<ans<<endl;


}