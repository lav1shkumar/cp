#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
i can use fentree to keep how many 0 and ones in the range
1 ftree for 0 one for 1


not req
i can do bs on ans, make tmp array and use pref sum to find a range if exist
tc = nlogn

*/
int n,m,q;
vector<pair<int,int>> arr;
vector<int> queries;


bool check(int x){
    vector<int> tmp(n);
    vector<int> pref(n);
    for(int i=0;i<x;++i) tmp[queries[i]]++;
    pref[0]=tmp[0];
    for(int i=1;i<n;++i) pref[i]=pref[i-1]+tmp[i];
    for(auto [l,r]:arr){
        int req = ((r-l+1)/2)+1;
        int ones;
        if(l==0) ones=pref[r];
        else ones=pref[r]-pref[l-1];
        if(ones>=req) return true;
    }
    return false;

}

void solve(){
    cin>>n>>m;
    arr.assign(m,{});
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        arr[i]={--u,--v};
    }
    cin>>q;
    queries.assign(q,0);
    for(int i=0;i<q;++i){
        int t;cin>>t;
        queries[i]=--t;
    }

    int l=0,r=q;
    int ans=-1;
    while(r>=l){
        int mid=(l+r)/2;

        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}