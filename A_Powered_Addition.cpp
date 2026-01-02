#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int prev=arr[0];
    int ans =0;

    for(int i=1;i<n;++i){
        if(arr[i]>=prev){
            prev=arr[i];
            continue;
        }
        int diff = prev-arr[i]; // this must be added
        // k ≥ log2(diff + 1)
        int k=ceil(log2(diff+1));
        ans=max(ans,k);
        
    }

    cout << ans << endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}