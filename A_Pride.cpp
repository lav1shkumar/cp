#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
2 2 3 4 6 ,, pick two adjacent and do gdc == replace one of them with gcd
coprimes gcd == 1, no common factor other than 1 , composite too 10,21
if gcd of all num is not 1, then -1



*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    // not possible
    int g=arr[0];
    for(int i=1;i<n;++i) g=gcd(g,arr[i]);
    if(g!=1){
        cout<<-1<<endl;
        return 0;
    }

    int c=INT_MAX;
    int ones=0;
    for(int i=0;i<n;++i){
        int g=arr[i];
        if(g==1) ones++;
        for(int j=i+1;j<n;++j){
            g=gcd(g,arr[j]);
            if(g==1){
                int op=j-i;
                c=min(c,op);
                break;
            }
        }
    }
    if(ones!=0) cout<< (n-ones)<<endl;
    else{
        cout<<(n-1)+c<<endl;
    }


}