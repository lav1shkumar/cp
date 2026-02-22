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

    int n,k;cin>>n>>k;
    int x,a,b,c; cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0]=x;

    for(int i=1;i<n;++i){
        arr[i] = ((a*arr[i-1]) + b) % c;

    }

    // count 
    vector<int> pref(n,0),suff(n,0);

    pref[0]=arr[0];
    for(int i=1;i<n;++i){
        if(i%k==0){
            pref[i]=arr[i];
        }
        else pref[i]=pref[i-1] | arr[i];
    }

    suff[n-1]=arr[n-1];
    for(int i=n-2;i>=0;--i){
        if((i+1)%k==0){
            suff[i]=arr[i];
        }
        else suff[i]=suff[i+1] | arr[i];

    }

    int XOR=pref[k-1];


    for(int i=k;i<n;++i){
        int l=i-k+1;
        int Or = pref[i]-suff[l];

        XOR^=Or;
    }


    cout<<XOR<<endl;

}