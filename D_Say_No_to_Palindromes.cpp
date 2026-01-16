#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
ways to make abc beautiful ---

abcabcabc..
bcabcabca..
cbacbabca..

acbacbabc..
bacbacbac..
cabcabcab..

3! == 6 ways only, any substring should follow this pattern

which pattern can be made in minimum operations?

how to get answer for q in logn max?
can i do prefix sums on mismatch, for all 6 patterns?

lets make 6 arrays, store mismatches and find the min prefix sum that will the query ans


*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;
    string s(n,' ');
    for(int i=0;i<n;++i) cin>>s[i];

    vector<pair<int,int>> q(m);
    for(int i=0;i<m;++i) cin>>q[i].first>>q[i].second;


    string pat[6] = {"abc","bca","cab","acb","bac","cba"};

    vector<vector<int>> pref(6,vector<int> (n));
    
    for(int i=0;i<6;++i){
        char c = pat[i][0];
        pref[i][0]= (s[0]!=c);
        for(int j=1;j<n;++j){
            char nc = pat[i][j%3];
            pref[i][j] = pref[i][j-1] + (nc!=s[j]);
        }
        // cout<<endl;
    }
    // now i have pref
    for(auto [l,r]:q){
        int mini = LLONG_MAX;
        l--,r--;
        for(int i=0;i<6;++i){
            int sum = pref[i][r] - ((l!=0)? pref[i][l-1] : 0);
            mini=min(mini,sum);
        }
        cout<<mini<<endl;
    }

}