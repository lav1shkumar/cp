#include <bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
const int MOD = 1e9+7;


// Observations
/*
for some point x
Totalcost = |x1-x|+cost[x1], max of all this
max will be:
            max distance from x and +its cost
            maybe minimizing max distance have greater cost or something
            wait can i do binary search on x?

i have to min the max time
    : for a person in time T == t-cost[i] consumed
                            possible range = x -T to x+T ,, left or right
                            once i know max time, i can try to minimize
    

*/
ld ans;
bool check(ld t,vector<int> &arr,vector<int> &cost){
    int n=cost.size();
    ld L = 0;
    ld R=1e8+1;
    for(int i=0;i<n;++i){
        ld c = max(t-(ld)cost[i],(ld)0);
        ld l = (ld)arr[i]-c;
        ld r = (ld)arr[i]+c;

        L=max(L,l);
        R=min(R,r);

        if(R<L) return false;
    }
    // best will be the midpoint
    ans=(L+R)/2;
    return true;
}

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    vector<int> cost(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    for(int i=0;i<n;++i) cin>>cost[i];


    ld l=0,r=1e9+1;
    // minimize the time here
    for(int i=0;i<=50;++i){
        ld mid=(l+r)/2;
        if(check(mid,arr,cost)) r=mid;
        else l=mid;
    }
    cout <<setprecision(16)<<ans<<endl;
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