#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
pick the biggest one and make it 1
if its 1 make it 2


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

    vector<int> arr(n);

    for(int i=0;i<n;++i) cin>>arr[i];

    int maxi=INT_MIN;
    for(int v:arr) maxi=max(maxi,v);

    for(int &v:arr){
        if(v==maxi){
            if(maxi==1) v=2;
            else v=1;
            break;
        }
    }

    sort(arr.begin(),arr.end());
    for(int v:arr) cout<<v<<" ";

}