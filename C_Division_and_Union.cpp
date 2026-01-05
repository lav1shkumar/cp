#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
 
// Observations
/*
 
 
 
 
*/
 
 
void solve(){
    int n;cin>>n;
    vector<tuple<int,int,int>> q(n);
    vector<int> ans(n);
 
    for(int i=0;i<n;++i){
        int a,b;cin>>a;cin>>b;
        q[i]={a,b,i};
    }
    // now i have all the quer, 
    // i need to check weather two diff groups possible or not
    // 3,5  ... other a>5 || b<3 , i guess that's enough
    // if for any value count==0 then NO
 
    sort(q.begin(),q.end());
    // now i have the smallest value at first
    int max_r = get<1>(q[0]);
    int s = -1;
 
    for (int i = 1; i < n; i++) {
        int l = get<0>(q[i]);
        int r = get<1>(q[i]);
 
        if (l > max_r) {
            s = i;
            break;
        }
        max_r = max(max_r, r);
    }
 
    if (s == -1) {
        cout << -1 << "\n";
        return;
    }
 
    for (int i = 0; i < s; i++)
        ans[get<2>(q[i])] = 1;
    for (int i = s; i < n; i++)
        ans[get<2>(q[i])] = 2;
 
    for (int x : ans) cout << x << " ";
    cout <<endl;
    
 
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while(t--) solve();
 
}