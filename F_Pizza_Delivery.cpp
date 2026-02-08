#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
can go to: x+1,y+1,y-1 ,, cant go back to x

graph sortof problem, 
cant go to x+1, if before going through all coor having x
PROBLEM IS THE SAME X DIFF Y'S  
i need to find y that has min abs diff
wait that's not correct



*/


void solve(){
    int n,ax,ay,bx,by;cin>>n>>ax>>ay>>bx>>by;
    vector<pair<int,int>> coor(n);
    vector<int> Y(n);
    for(int i=0;i<n;++i) cin>>coor[i].first;
    for(int i=0;i<n;++i) cin>>coor[i].second;

    sort(coor.begin(),coor.end());



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