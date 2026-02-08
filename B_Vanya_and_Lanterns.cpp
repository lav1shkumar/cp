#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int MOD = 1e9+7;


// Observations
/*
0  3   5   8   10
max diff/2?


*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,l;cin>>n>>l;

    vector<int> arr;
    for(int i=0;i<n;++i){
        int n;cin>>n;
        arr.push_back(n);
    }
    sort(arr.begin(),arr.end());

    ld max_diff=0;

    for(int i=1;i<n;++i){
        ld d = arr[i]-arr[i-1];
        max_diff=max(max_diff,d/2);
    }
    max_diff=max(max_diff,(ld)arr[0]);
    max_diff=max(max_diff,(ld)(l-arr[n-1]));

    cout<<setprecision(16)<<max_diff<<endl;
}