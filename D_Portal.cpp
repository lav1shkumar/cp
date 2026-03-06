#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
1 | 2 4 5 3|

|1 4 2 3| 


1 2 | 3 5 | 4

1 3 4 | 6 | 5  2

*/


void solve() {
    int n,x,y;
    cin >>n>>x>>y;
    vector<int> p(n);
    for (int i=0;i<n;++i) cin>>p[i];

    vector<int> M,S;
    for (int i=0;i<n;++i) {
        if (i>=x && i<y) M.push_back(p[i]);
        else S.push_back(p[i]);
    }


    auto it = min_element(M.begin(), M.end());
    rotate(M.begin(), it, M.end());

    int idx = S.size(); 
    for (int i =0;i<S.size();++i) {
        if (S[i]>M[0]) {
            idx = i;
            break;
        }
    }


    for (int i=0;i<idx;++i) cout << S[i] << " ";

    for (int v:M) cout<<v<<" ";

    for (int i=idx;i<S.size();++i) cout<<S[i]<<" ";
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