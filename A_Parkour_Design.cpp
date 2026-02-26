#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

can i reach to x and y from 0,0

a,b,c == 2a + 3B + 4c = x
            a-c=y
      
a=c+y

2(c+y) + 3b + 4c = x
2c + 2y + 3b + 4c = x
6c + 2y + 3b = x
3(2c + b) = x - 2y

*/


void solve(){
    int x,y;cin>>x>>y;

    int val = x-2*y;

    if(val<0 || val%3!=0){
        cout<<"NO"<<endl;
        return;
    }

    int X = val/3;

    if(X/2 >= -y){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;



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