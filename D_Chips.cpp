#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
ig (n-2)/2 * 4 is upper bound, cuz cant be symmatrical
i need to iterate starting 1 to n/2

if odd then?




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

    unordered_map<int,int> row,col;
    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        row[a]=1;
        col[b]=1;
    }

    int cnt=0;

    unordered_map<int,int> u,d,l,r;


    for(int i=2;i<n;++i){
        int up=i;
        int down=n-i+1;

        if(!col[up] && !l[up] && !r[down] && !u[up]){
            u[up]=1;
            cnt++;
        }

        if(!col[down] && !l[up] && !r[down] && !d[down] && !u[down]){
            d[down]=1;
            cnt++;
        }


        if(!row[down] && !u[down] && !r[down] && !d[up]){
            l[down]=1;
            cnt++;
        }

        if(!row[up] && !u[down] && !l[up] && !d[up]){
            r[up]=1;
            cnt++;
        }

        //cout<<cnt<<" ";
        
    }

    cout<<cnt;
}