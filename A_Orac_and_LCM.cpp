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

    int n;cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    int N=2e5+1;
    int pf[N];
    int a[N];
    int b[N];
    for(int i=0;i<N;++i){
        pf[i]=i;
        a[i]=b[i]=LLONG_MAX;
    }


    for(int i=2;i*i<N;++i){
        if(pf[i]!=i) continue;

        for(int j=i*i;j<N;j+=i){
            if(pf[j]==j) pf[j]=i;
        }
    }

    unordered_map<int,int> cnt;

    for(int i=0;i<n;++i){
        int v=arr[i];

        unordered_map<int,int> mp;

        while(v>1){
            int f=pf[v];
            mp[f]++;
            v/=f;
        }

        for(auto [k,v]:mp){
            cnt[k]++;
            if(a[k]>v){
                b[k]=a[k];
                a[k]=v;
            }
            else if(b[k]>v) b[k]=v;
        }
    }
    int ans=1;
    for(int i=0;i<N;++i){
        if(cnt.find(i)==cnt.end()) continue;

        if(cnt[i]==n) ans*=pow(i,b[i]);
        else if(cnt[i]==n-1) ans*=pow(i,a[i]);
    }

    cout<<ans<<endl;

}