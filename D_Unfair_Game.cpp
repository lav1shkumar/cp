#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
n = 2^d, and alice know if even or odd

if odd, n==1 only

alice can --> make n/2(even) or -1

bob == -1, alice won , n==0 ,,, or x

        a is div by 2^x
        a is not div by 2^x+1


zero can only occur if n==1 and acide did -1

repeats until number is zero 
a bitset at pos need 1 sub

12 == 6 - 3 - 2  - 1  - 0 etc 
moves = popcnt + msb

moves(a)>k
lets calc number  of int where alice wins moves(a)<=k and sub from n
if n=2^d , cost = d+1

cost = i+popcnt, i=msb
popcnt<k-i alice win

basically , icj for j=0 to i
use pascals triangle to calculate ncr

*/

int dp[35][35];

void run(){
    for(int i=0;i<=32;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
}

void solve(){
    int n,k;cin>>n>>k;

    int d=0;
    int temp=n;

    while(temp>1){
        temp>>=1;
        d++;
    }

    int a=0;

    if(d+1<=k)a++;
    for(int i=0;i<d;i++){
        int bits=k-i-1;
        if(bits<0)continue;
        if(bits>=i){
            a+=(1LL<<i);
        }else{
            for(int j=0;j<=bits;j++){
                a+=dp[i][j];
            }
        }
    }
    cout<<n-a<<endl;

}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    int t; cin >> t;
    while(t--) solve();

}