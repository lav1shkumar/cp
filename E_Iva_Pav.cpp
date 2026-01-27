#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
find r where ans of range > k


 1 & 1 = 1
 1 & 0 = 1 
 monotonic

 if l to r >=k then l to r-i will alse we >=k
 i can use segtree or sparsh table then binary search

 if k has some bits on, 011101010
 i need to find first element that has some bit off without any extra bit on

 i can store these bits prefix sum, for len 4 is no of ith bit is 3 then included in ans, else not

 10^9 max 30 bits




*/


void solve(){
    int n;cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    vector<vector<int>> pref(32,vector<int> (n,0));

    for(int i=0;i<32;++i){
        pref[i][0] = (arr[0]&(1ll<<i))? 1 : 0;
        for(int j=1;j<n;++j) pref[i][j] = pref[i][j-1] + ((arr[j]&(1ll<<i))?1:0);
    }

    int q;cin>>q;

    for(int i=0;i<q;++i){
        int k,l;cin>>l>>k;
        l--;

        int a=l,b=n-1;
        int ans=-1;
        while(b>=a){
            int mid = (a+b)/2;
            int val=0;
            for(int i=0;i<32;++i){
                int s = pref[i][mid] - ((l>0)?pref[i][l-1]:0);
                if(s==(mid-l+1)) val+=(1ll<<i);
            }

            if(val>=k){
                ans=mid;
                a=mid+1;
            }
            else b=mid-1;
        }
        cout<< ((ans==-1)? ans : ans+1) <<" ";

    }
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