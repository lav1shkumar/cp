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

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    int x = 0, ans = 0;

    while(i < j){
        int need = a[j] - x;

        if(need > 0){
            int take = min(a[i], need);
            a[i] -= take;
            x += take;
            ans += take;
            if(a[i] == 0) i++;
        }

        if(x == a[j]){
            ans++;
            x = 0;
            j--;
        }
    }

    if(i == j){
        int v = a[i];
        if(v < x) ans += v;
        else if(v == x) ans += 1;
        else{
            int d = v - x;
            int opt = (d / 2) + 1 + (d % 2);
            ans += min(v, opt);
        }
    }

    cout << ans << '\n';
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}