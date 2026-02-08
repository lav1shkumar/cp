#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
using ll = long long;


// Observations
/*
i can do bitwise check, all the 0 bits can be assigned to first and last, rest in the mid part

0 1 0 0 fine
1 0 0 0 wrong

3c2 * 2 fact pick and arrange

wait fix first two pos
min and should be there

*/
const int N = 1e6;
int fact[N];

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>> arr[i];

    int min_and=arr[0];
    for(int val:arr) min_and&=val;

    int equal=0;
    for(int val:arr){
        if(val==min_and) equal++;
    }

    if(equal<=1){
        cout<<0<<endl;
        return;
    }

    int ans = (equal*(equal-1))%MOD;
    ans = (ans*fact[n-2])%MOD;

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
    
    fact[0]=1;
    for(int i=1;i<N;++i){
        fact[i]=(fact[i-1]*i)%MOD;
    }

    int t; cin >> t;
    while(t--) solve();

}