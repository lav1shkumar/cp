#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

999999937 == prime > 10^8 so i can use it


*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;cin>>n>>k;

    if(n==1){
        if(k==0){
            cout<<1;
            return 0;
        }
        else cout<<-1;
        return 0;
    }

    int prime = 999999937;
    int prime2 = 310248241;
    int p = n/2;

    if(k<p){
        cout<<-1;
        return 0;
    }

    vector<int> a(n);

    for(int i=0;i<n;++i){
        a[i]=i+1;
    }


    k-=(p-1);

    if(k<=n){
        a[k-1]=prime;
    }
    if(2*k<=n){
        a[2*k-1]=prime2;
    }

    if(n&1){
        a[n-3]=k;
        a[n-2]=2*k;
    }
    else{
        a[n-2]=k;
        a[n-1]=2*k;
    }

    for(int v:a) cout<<v<<" ";


}