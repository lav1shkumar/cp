#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

x + y > z

all pairs poss - invalid pairs

how to find invalid pairs? : 

can i pick x and y and see the valid z's?
x/2*x/2 -- nah


x+y <= z 
can i binary search?
x+y i can do i+b++ and i+c--


*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d;cin>>a>>b>>c>>d;

    vector<int> sum(2*d+5,0);

    for(int i=a;i<=b;++i){
        sum[i+b]++;
        sum[i+c+1]--;
    }

    for(int i=1;i<=2*d+4;++i){
        sum[i]+=sum[i-1];
    }

    int ans=0;

    for(int i=0;i<=2*d+4;++i){
        if(sum[i]>0){
            // c to d
            // want z < i
            // c .... i .... d
            int z = min(i-1,d);

            int count = z-c+1;

            if(count>0) ans+=count*sum[i];

        }

    }

    cout<<ans<<endl;

}
