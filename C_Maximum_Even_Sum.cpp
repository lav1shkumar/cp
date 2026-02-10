#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
b % k ==0 , means 0 to b

a * k + b / k == max even

a + b == even, so both even or odd
we can make a even if odd, but can do same with b


if(a is even and b is odd)  -1

if both even = a*b+1, this will be odd -- a*(b/2)+ 2
if (a odd and b even ) wanna make a even, can try 2 and 4 and 6 8 etc, if mod 4==0 then possible,
bcz b/2 will be even else not
if both odd --- a*b+1


alright



*/


void solve(){
    int a,b;cin>>a>>b;

    if(a%2==0 && b%2==1){
        cout<<-1<<endl;
        return;
    }

    if(a%2==0 && b%2==0){
        cout<<a*(b/2)+2<<endl;
        return;
    }

    if(a%2==1 && b%2==1){
        cout<<a*b+1<<endl;
        return;
    }

    if(a%2==1 && b%2==0){
        if(b%4==0){
            cout<<a*(b/2)+2<<endl;
            return;
        }
        else{
            cout<<-1<<endl;
        }

    }



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