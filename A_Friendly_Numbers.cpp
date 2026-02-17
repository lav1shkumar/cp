#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

y = x+d(y),  dy>0 so y>x

any range thing?


dy grows slower than y
max dy = 999999999 = around 81
y-x can be atmost 81

x+1 to x+90 we cqan search


*/
int sumD(int x){
    int ans=0;
    while(x!=0){
        ans+=x%10;
        x/=10;
    }

    return ans;

}

void solve(){
    int x;cin>>x;


    int cnt=0;

    for(int i=1;i<90;++i){

        int y=x+i;

        if(y-x==sumD(y)) cnt++;

    }

    cout<<cnt<<endl;


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