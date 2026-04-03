#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

if a>b 
    a-b/b + 1

    b>a   a/b-a

    a/(b-a)|| 1

    a-xb , a/b
*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b;cin>>a>>b;

    int ans=0;
    while(a>0 && b>0){
        if(a>=b){
            ans+=a/b;
            a=a%b;
        }
        else{
            ans+=b/a;
            b=b%a;
        }

    }

    cout<<ans<<endl;



}