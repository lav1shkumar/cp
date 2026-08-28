#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;

    vector<vector<int>> tree(n+1);

    for(int i=0;i<=n;++i){
        vector<int> t(1<<i);
        tree[i]=t;
    }

    for(auto &v:tree[n]){
        cin>>v;
    }

    bool flag=true;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<(1<<i);++j){
            if(flag) tree[i][j]=tree[i+1][2*j] | tree[i+1][2*j+1];
            else tree[i][j]=tree[i+1][2*j] ^ tree[i+1][2*j+1];
        }
        flag=!flag;
    }

    for(int i=0;i<m;++i){
        int idx,val;cin>>idx>>val;
        idx--;

        tree[n][idx]=val;

        idx/=2;

        bool flag=true;
        for(int i=n-1;i>=0;--i){
            if(flag) tree[i][idx]=tree[i+1][2*idx] | tree[i+1][2*idx+1];
            else tree[i][idx]=tree[i+1][2*idx] ^ tree[i+1][2*idx+1];

            flag=!flag;
            idx/=2;
        }

        cout<<tree[0][0]<<endl;


    }


}
