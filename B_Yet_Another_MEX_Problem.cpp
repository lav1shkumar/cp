#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
 0 2 1 3 == window of size k and remove an element, k==2
 i will try to remove min ele
there will only one element remaining
if that ele is zero, the mex=1

6 2
0 1 0 1 2 0
final len = 1
ans = 1 i can preserve zero


7 5
0 1 2 4 0 3 1 
will have 4 elements at last
0,1,2,3 == 4 ans okay remove duplicates too
0 0 1 1 2 3 4
0 1 2 3 4   == 0 1 2 3

*/


void solve(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    sort(arr.begin(),arr.end());

    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    int s=arr.size();k--;

    int mex=0;
    for(int i=0;i<arr.size()&&i<k;++i){
        if(arr[i]==mex) mex++;
    }

    cout<<mex<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}