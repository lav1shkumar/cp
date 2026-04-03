#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

x and y must be unique throughoutly

i need to think the optimal pair

(x1-x2)^2 + (y1-y2)^2 = not be a perfect square
   s1      +    s2    = not a perfect squre

x and y<=100 so, s1,s2 can be 10000 at max
0,n and 0,m max distance or 0,0 and n,m

n^2 + m^2 == 2*10^4 == we good
i need to find pairs

can i pick diagonals??

at max i can have like, min(x,y)+1 pairs on diagonals, dis is root 2
and any int mul of root 2, doesnt make it int so we good
also optimal, bcz we can choose, 0,0 , 1,1 , 2,2 .... 

wait 0,0 not allowed x+y> 0
so go for 0,1 or 1,0 first whatever is bigger ig

wait when both are equal i also need to check for x,0 pt if i am tasking 0,1 first


*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x,y;cin>>x>>y;

    int k=min(x,y)+1;

    cout<<k<<endl;

    for(int i=0;i<k;++i) cout<<i<<" "<<k-i-1<<endl;
}