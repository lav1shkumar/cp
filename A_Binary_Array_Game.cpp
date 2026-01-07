#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
if there's a zero bob can make whole array 1 hence he win
alice need to remove all zeroes in her move
making 1,1

there should be 1 in start and end

11100001010101 == 10 == 1
11111111 == 1
ans so on

0111120000010 == 01 == 1
*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    if(arr[0]==1||arr[n-1]==1) cout << "Alice"<<endl;
    else cout<<"Bob"<<endl;



}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}