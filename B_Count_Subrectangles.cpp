#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;cin>>n>>m>>k;

    vector<int> a(n),b(m);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) cin>>b[i];


    vector<int> c1(n),c2(m);

    int len=0;
    for(int i=0;i<n;++i){
        if(a[i]==1){
            len++;
            c1[len-1]++;
        }
        else len=0;
    }

    len=0;
    for(int i=0;i<m;++i){
        if(b[i]==1){
            len++;
            c2[len-1]++;
        }
        else len=0;
    }

    for(int i=n-2;i>=0;--i) c1[i]+=c1[i+1];
    for(int i=m-2;i>=0;--i) c2[i]+=c2[i+1];

    int ans=0;
    for(int i=1;i*i<=k;++i){

        if(k%i==0){
            int f1 = i, f2 = k/i;

            if(f1<=n && f2<=m) ans+=(c1[f1-1] * c2[f2-1]);

            if(f1!=f2 && f2<=n && f1<=m) ans+=(c1[f2-1] * c2[f1-1]);

        }

    }

    cout<<ans<<endl;


}