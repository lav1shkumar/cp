#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
<<<<<<< HEAD
pi = pj^i
pi^i = pj
p == 1 to n

x^i == y
y after x
=======
>>>>>>> 4dbee24 (Jan)




<<<<<<< HEAD
011111111

1 1 
2 3 = 1
3 2 = 1
4 5 = 1
5 4 = 1

then put 1 to the end
4 3 2 5 1 

1 
2 3
3 2
4 

1 3 2 4 , swap
4 3 2 1


=======
>>>>>>> 4dbee24 (Jan)
*/


void solve(){
<<<<<<< HEAD
    int n;cin>>n;
    vector<int> perm(n);
    for(int i=1;i<=n;++i) perm[i-1]=i;

    for(int i=1;i<(n-1);i+=2) swap(perm[i],perm[i+1]);
    swap(perm[0],perm[n-1]);

    for(int val:perm) cout<< val<< " ";
    cout<<endl;
=======
>>>>>>> 4dbee24 (Jan)

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