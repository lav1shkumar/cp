#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




if size less than 3
1 == 1 1 1 = 1
2 == 1 2 2 = 2
3 == 3 2 1 = 6


if n odd = n*n-1*n-2 parwise gcd == 1 for 3, no common
if even:
        or n*n-1*n-3 if n%3!=0 or n-1*n-2*n-3 / n-1*n-2*n-5 maybe
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

    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    if(n==2){
        cout<<2<<endl;
        return 0;
    }

    if(n&1){
        cout<<n*(n-1)*(n-2)<<endl;
    }

    else{
        if(n%3!=0){
            cout<<n*(n-1)*(n-3)<<endl;
        }

        else{
            int maxi = max((n-1)*(n-2)*(n-3),(n-1)*(n-2)*(n-5));
            cout<<maxi<<endl;
        }

    }

}