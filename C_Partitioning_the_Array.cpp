#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
10
1 7 5 1 4 3 1 3 1 4 -- possible k=1,2,5
ans = 2



if(a%m==b%m) what that means?
a%m=b%m == a%m-b%m=0 == (a-b)%m = 0
accumulate all diff
their gcd >=2, got it

1 not possible, no common divisor
1 7 | 5 1 | 4 3 | 1 3 | 1 4  ==> is there a possiblity?
1==5==4==1==1 && 7==1==3==3==4 when %m
4 3 0 0 ,, 4 1 3 0 gcd will be same
now gcd of this with all column should be >=2;

1 7 5 1 4 | 3 1 3 1 4
diff = 2 6 2 0 0 == gcd==2
+1 for size 10.

6
1 3 1 1 3 1 == 6 == 1,2,3,6
ans == 1,2,
1 3  1 1  3 1
0 , 2 == 2
2 , 2 == 2 

1 3 1  1 3 1
0 0 0
0 0 0

*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    // have to go through the divisors of n
    // for 10 == 1,2,5,10 == 1,10 and 5,2 pairs go till root n, find div and grab pair
    vector<int> divisor;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divisor.push_back(i);
            if(i * i != n) divisor.push_back(n / i);
        }
    }
    // now i need gcd of i+i+div ele
    int ans = 0;
    for(int div:divisor){
        if(div==n){
            ans++;
            continue;
        }
        // there will be div no of columns
        int gcd_all=0;
        for(int c=0;c<div;++c){
            int num=arr[c];
            int gcd_c=0;
            for(int i=div+c;i<n;i+=div){
                gcd_c=gcd(gcd_c,abs(num-arr[i]));
                //cout<<gcd_c<<" "<<abs(num-arr[i])<<" "<<endl;
            }
            
            gcd_all=gcd(gcd_all,gcd_c);
        }
    
        if(gcd_all>=2 || gcd_all==0) ans++;

    }
    
    cout<<ans<<endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}