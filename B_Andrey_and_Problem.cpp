#include <bits/stdc++.h>
using namespace std;
#define int long double
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
    vector<int> p(n);

    for(int i=0;i<n;++i) cin>>p[i];

    sort(p.rbegin(),p.rend());

    int zero=1;
    int prev=0;

    int answer=0;

    for(int i=0;i<n;++i){
        
        int nprev = prev*(1-p[i])+zero*p[i];
        zero*=(1-p[i]);
 
        prev=nprev;

        answer=max(answer,nprev);

    }

    cout<<fixed;
    cout<<setprecision(12)<<answer;

}