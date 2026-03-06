#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n,m;cin>>n>>m;

    vector<int> x(n),y(m);

    for(int i=0;i<n;++i) cin>>x[i];
    for(int i=0;i<m;++i) cin>>y[i];

    vector<int> cnt(m+n+1,0);
    vector<int> check(m+n+1,0);

    for(int v:x) cnt[v]++;

    for(int i=1;i<=(m+n);++i){
        for(int f=1;f*i<=(m+n);++f){
            check[i*f]+=cnt[f];
        }
    }

    int alice=0,bob=0,both=0;

    for(int i=0;i<m;++i){
        int c=check[y[i]];

        if(c!=0 && c!=n) both++;
        else if(c==0) bob++;
        else alice++;

        //cout<<c<<" ";
    }

    for(int i=0;i<m+1;++i){
        if(both){
            both--;
            continue;
        }
        if(i&1){
            if(bob){
                bob--;
                continue;
            }
            else{
                cout<<"Alice"<<endl;
                return;
            }
        }
        else{
            if(alice){
                alice--;
                continue;
            }
            else{
                cout<<"Bob"<<endl;
                return;
            }
        }

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