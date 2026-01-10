#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
basically max subarray sum< max-min
taking 2 pointer from max to min
greedily pick the elements try to keep maxsum<bound

*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    
    int maxi=*max_element(arr.begin(),arr.end());
    int mini=*min_element(arr.begin(),arr.end());
    int bound = maxi-mini;

    // max subarray sum < bound
    sort(arr.rbegin(),arr.rend());
    vector<int> newarr;

    int i=0,j=n-1;
    int track = 0;
    int window = 0;
    
    while(j>=i){
        int a=max(arr[i],window+arr[i]);
        int b=max(arr[j],window+arr[j]);
        int c=max(track,a);
        int d=max(track,b);

        if(c<bound){
            newarr.push_back(arr[i]);
            i++;
            track=c;
            window=a;
        }
        else if(d<bound){
            newarr.push_back(arr[j]);
            j--;
            track=d;
            window=b;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    for(int val:newarr) cout<<val<<" ";
    cout<<endl;

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