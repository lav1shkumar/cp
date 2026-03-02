#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

a + x == y or a ^ x = y

4 0 1
1 2 3 4

bob = 3
a = y^x = 3^1,2,3,4


check for y element only,
y^d = y
d=y^y
its 7 for xor, and -3 for add
d will only be pos?

wait, addition will only inc the value, we need xor to dec but
where to do xor?

both can be prefixed


001 010 011 100 , 100 to 001, flip 1st and y bit

start = 011

if need> then sum, else xor

xor parity = 1 and 0 = 1, else 0
sum parity = odd + even = 1(odd)  similar
target is odd or even vs start


*/


void solve(){
    int n,x,y; cin>>n>>x>>y;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    int odd=0;
    for(int i=0;i<n;++i){
        if(arr[i]&1) odd++;
    }

    if((x&1) && (y&1)){
        if(odd%2==0){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    else if((x%2==0) && (y%2==0)){
        if(odd%2==0){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    else{
        if(odd&1) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
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