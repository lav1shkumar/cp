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

    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

    auto valid = [](int a,int b){
        if(a>=0 && a<3 && b>=0 && b<3) return true;
        return false;
    };

    int grid[3][3];

    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j) cin>>grid[i][j];
    }


    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            int t=0;

            for(auto [a,b]:dir){
                int r=a+i;
                int c=b+j;
                if(valid(r,c)) t+=grid[r][c];
            }

            t+=grid[i][j];

            if(t&1) cout<<0;
            else cout<<1;


        }
        cout<<endl;
    }







}