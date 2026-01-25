#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
if sum>s no
i can inc sum by x only, sum+x, sum+2x , .....
x 2x 3x 
need % x == 0

*/


void solve(){
    int n,s,x;cin>>n>>s>>x;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    int sum = accumulate(arr.begin(),arr.end(),0ll);

    if(sum>s){
        cout<<"NO"<<endl;
        return;
    }
    int need = s-sum;
    if(sum==s || (need%x)==0){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;

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