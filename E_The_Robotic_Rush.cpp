#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,m,k;cin>>n>>m>>k;

    vector<int> a(n),b(m);

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) cin>>b[i];

    string s;cin>>s;

    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pql,pqr;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    for(int i=0;i<n;++i){
        int idx = lower_bound(b.begin(),b.end(),a[i])-b.begin();
        if(idx!=m){
            pqr.push({b[idx]-a[i],i});
        }
        idx--;

        if(idx!=-1){
            pql.push({a[i]-b[idx],i});
        }

    }

    unordered_set<int> st;

    int r=0,l=0;
    int cnt=n;
    for(char c:s){
        if(c=='R'){
            r++;
            while(!pqr.empty() && pqr.top().first+l<=r){
                auto [c,i] = pqr.top();
                pqr.pop();
                if(st.count(i)) continue;
                cnt--;
                st.insert(i);
            }
        }
        if(c=='L'){
            l++;
            while(!pql.empty() && pql.top().first+r<=l){
                auto [c,i] = pql.top();
                pql.pop();
                if(st.count(i)) continue;
                cnt--;
                st.insert(i);
            }
        }

        cout<<cnt<<" ";

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