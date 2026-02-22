#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

10101001 == make all 0

1010 =  1101 

100 - 111 010 

all ones one zero form should be achieveable
order doesnt matter here


lets say xor==0
we can always pick indices with 1
if n is odd, even number flip
same no of zero and 1 == possible

ones even, or zeroes odd
*/


void solve(){

    int n;cin>>n;
    string s;cin>>s;

    int ones=0,zeros=0;

    for(int i=0;i<n;++i){
        if(s[i]=='1') ones++;
        else zeros++;
    }


    if(ones%2==0){
        cout<<ones<<endl;
        for(int i=0;i<n;++i){
            if(s[i]=='1') cout<<i+1<<" ";
 
        }
        if(ones!=0) cout<<endl;
    }

    else if(zeros&1){
        cout<<zeros<<endl;
        for(int i=0;i<n;++i){
            if(s[i]=='0') cout<<i+1<<" ";
 
        }
        if(zeros!=0) cout<<endl;
    }

    else{
        cout<<-1<<endl;
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