#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
max = n*m  , count no of digits - 1 == possible zeroes

now brute force

81*2 = 162 == 2 zero = 100 = 100/2 = 50<=81 done

10050 * 12345 == 1240,67,250 == 8 zero poss 

                100000000  == mod == 0
                120000000
                124000000
                124060000
                124067000

                120600000

                100500000

to make zero we need some 2's and 5  comb
5*2 = 10 or 10

first 10000 then if 5 exist or 2 exist try to pick 5 or 2

4 30
120 - can we make 100
25 * 4 = 100

2^x * 5^y == max

we want 100, 2 zeroes
for 4 = x=2 and y=0;
need 2^x * 5^y == need y=2, bcz 2 zeroes - inside n = 2

need = 5^2 = 25 <=m 
now largest mul of need <=m

k = m-(m%need)
30 - 25%20 = 30 - 5 = 25


10050 * 12345 == 


*/


void solve(){
    int n,m;cin>>n>>m;


    int two=0,five=0;
    int tmp=n;
    while(tmp%2==0){
        two++;
        tmp/=2;
    }

    tmp=n;
    while(tmp%5==0){
        five++;
        tmp/=5;
    }

    int s = to_string(n*m).size();

    int ans = n*m;

    for(int i=1;i<s;++i){
        int a = max(0ll,i-two);
        int b = max(0ll,i-five);
        // need 2^a * 5^b right?

        int need = (1<<a) * pow(5,b);
        
        if(need>m) continue;
        //cout<<need<<" "<<i<<endl;

        int k = m-(m%need);
        ans= n*k;

    }

    cout<<ans<<endl;


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