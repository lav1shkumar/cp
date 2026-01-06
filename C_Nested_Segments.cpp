#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
sort from big to small
a,b  -- c,d ,, a>=b so if d is smaller or equal to b
*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<pair<pair<int,int>,int>> q(n);
    for(int i=0;i<n;++i){
        int l,r;cin>>l>>r;
        q[i]={{l,r},i+1};
    }

    // l in asc and r ind desc
    sort(q.begin(),q.end(),[](auto &a,auto &b){
        if(a.first.first!=b.first.first) return a.first.first<b.first.first;
        else return a.first.second>b.first.second;
    });
    
    int maxr = q[0].first.second;
    int previdx = q[0].second;

    for(int i=1;i<n;++i){
        if(q[i].first.second<=maxr){
            cout << q[i].second<< " "<<previdx<<endl;
            return 0;
        }
        if(q[i].first.second > maxr){
            maxr = q[i].first.second;
            previdx = q[i].second;
        }
    }
    cout << "-1 -1\n";

}