#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T> 
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;



#define int long long

// Observations
/*




*/


void solve(){
    int n;
    cin>>n;

    ordered_set<int> s;
    
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i].first;
        cin>>arr[i].second;
        s.insert(arr[i].second);

    }

    sort(arr.begin(),arr.end());

    int ans = 0;

    for(int i=0;i<n;++i){
        int ub = arr[i].second;
        s.erase(ub);
        ans+= s.order_of_key(ub);
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