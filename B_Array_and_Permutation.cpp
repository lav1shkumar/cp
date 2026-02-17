#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
7
1 3 2 7 5 4 6
2 2 7 7 7 5 6


7
3 7 4 2 1 6 5
3 3 4 4 5 6 5


3 3 4 4 5 5 5 , now we can make 5 to 6

if number moves two pos, mid pos is locked
we need to check: if num exist any side? if yes then between them all the values must be same

okay, basically i can check for a+1 and a-1 too in that case

values cant jump, and cuz its a permutation only one val exist
unique vals should have continuous block 5 5 5 , 6 6 6 , 6 5 6 is No
i need to also check the order of these values, if pos at i-1 comes after i, then No

*/


void solve(){
    int n;cin>>n;

    vector<int> p(n);
    vector<int> a(n);

    for(int i=0;i<n;++i) cin>>p[i];
    for(int i=0;i<n;++i) cin>>a[i];

    vector<int> pos(n+1);

    for(int i=0;i<n;++i) pos[p[i]]=i;


    vector<int> order;
    vector<bool> check(n+1,0);

    order.push_back(a[0]);
    check[a[0]]=1;

    for(int i=1;i<n;++i){
        if(a[i]!=a[i-1]){
            if(check[a[i]]){
            
                cout<<"NO"<<endl;
                return;

            }

            check[a[i]]=1;
            order.push_back(a[i]);

        }


    }

    for(int i=0;i<order.size()-1;++i){

        int a=order[i];
        int b=order[i+1];

        if(pos[a]>pos[b]){
            cout<<"NO"<<endl;
            return;
        }


    }

    cout<<"YES"<<endl;




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