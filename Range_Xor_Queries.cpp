#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
struct Fenwick{
    int n;
    vector<int> tree;

    Fenwick(int x){
        n=x;
        tree.assign(n+1,0);
    }


    void add(int val,int idx){

        for(int i=idx+1;i<n+1;i+=(i&-i)){
            tree[i]^=val;
        }


    }

    int pref(int r){
        int s=0;
        for(int i=r+1;i>=1;i-=(i&-i)){
            s^=tree[i];
        }

        return s;
    }

    int query(int l,int r){
        int t = pref(r);
        int s = l>0?pref(l-1):0;

        return t^s;

    }




};


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,q;cin>>n>>q;

    Fenwick fen(n);
    for(int i=0;i<n;++i){
        int x;cin>>x;
        fen.add(x,i);
    }

    for(int i=0;i<q;++i){
        int l,r;cin>>l>>r;
        l--,r--;
        cout<<fen.query(l,r)<<endl;

    }



}