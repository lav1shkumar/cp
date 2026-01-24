#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
i will try to make a decreasing sequence and the rest will have panelty?
8 2 3 1 1 7 4 3

8 7 4 3
2 3 1 1

longest dec seq? then remove it and count panelty?

8
8 7 4 3

only last element matters, so i can greedily add elements to two vectors by checking last one
if v can be inserted in both, insert in the lesser bast val
if cant in both, then insert in less value , similar

if either a or b then go for it


*/


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    int panelty=0;
    int a=LLONG_MAX;
    int b=LLONG_MAX;

    for(int i=0;i<n;++i){
        int v=arr[i];
        if(a>=v && b>=v){
            if(a>b){
                b=v;
            }
            else a=v;
        }
        else if(a>=v){
            a=v;
        }
        else if (b>=v)
        {
            b=v;
        }
        else{
            if(a>b){
                b=v;
            }
            else a=v;
            panelty++;
        } 
    }
    cout<<panelty<<endl;
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