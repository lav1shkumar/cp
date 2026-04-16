#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 676767677;


// Observations
/*

we have 1 and -1, minimize partitions that equalize sum

1 -1 1 -1 1 -1 1
   |  |  |  | sum | 
   look at total

1 -1 1 -1 1 -1 1 -1 1 == ans = 1

x==y , 1 1 1 -1 -1 -1 == ans= 1
    
       1 1 1 1 1 -1 -1 -1 

       1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 

basically abs(x-y)-1; and print 1111 -1-1-1

*/


void solve(){
    int x,y;cin>>x>>y;

    int mini = max(1ll,abs(x-y));

    int div=0;
    for(int i=1;i*i<=mini;++i){
        if(mini%i==0){
            div++;

            if(i*i!=mini) div++;
        }

    }

    cout<<div<<endl;

    while(x--) cout<<1<<" ";
    while(y--) cout<<-1<<" ";

    cout<<endl;

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