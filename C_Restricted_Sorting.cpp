#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
pick i and j, if diff >=k swap

non dec order -- target
diff increasing


2 1 5 4 3 
target - 1 2 3 4 5  -- 1 1 2 0 2 == 2

1 1 4 5 1 4
1 1 1 4 4 5   == 0 0 3 1 3 1  == 3 

1 4 2
1 2 4  -- 0 2 2

c should not be that easy though
yep wrong!

okay, abs(min-max) can also 
wait, it is 
when i cannot swap?
optimal swap will be with min or max

if the value is (max-val)>=k or (min-val)>=k , abs of both
max-k>=val or (val-min)>k == k+min<=val
if val is not in place, and cannot swap then false

element b/w these cant swap with min or max, so they must be at corrext pos
okay, bs

*/
bool check(int x,vector<int> &a,vector<int> &b){
    int ub = b[0]+x, lb =b.back()-x;

    for(int i=0;i<a.size();++i){
        if(a[i]!=b[i]){
            if(a[i]>lb && a[i]<ub) return false;
        }

    }
    return true;

}

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    
    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end());

    if(arr==sorted){
        cout<<-1<<endl;
        return;
    }


    int ans;
    int l=1,r=1e9;
    while(r>=l){
        int mid=(l+r)/2;

        if(check(mid,arr,sorted)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    cout<<ans<<endl;

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