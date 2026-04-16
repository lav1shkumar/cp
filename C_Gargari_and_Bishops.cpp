#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
cond : no cell will be hit by both

so, i,j then same col dis odd or same row dis odd, rest --? same thing, will cover similar diag
can i bruteforce?

diagsum = need 2 arr



*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    vector<vector<int>> grid(n,vector<int> (n));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) cin>>grid[i][j];
    }

    auto v1 = grid;
    auto v2 = grid;

    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            v1[i][j]+=v1[i-1][j-1];
        }
    }

    for(int i=n-2;i>=0;--i){
        for(int j=n-2;j>=0;--j){
            v1[i][j]=v1[i+1][j+1];
        }
    }


    for(int i=1;i<n;++i){
        for(int j=0;j<n-1;++j){
            v2[i][j]+=v2[i-1][j+1];
        }
    }

    for(int i=n-2;i>=0;--i){
        for(int j=1;j<n;++j){
            v2[i][j]=v2[i+1][j-1];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            grid[i][j] = v1[i][j]+v2[i][j]-grid[i][j];
        }

    }

    // now i have diag sum
    int maxi=LLONG_MIN;
    
    auto s1 = grid;
    auto s2 = grid;

    for(int i=0;i<n;++i){
        for(int j=n-3;j>=0;--j){
            s1[i][j] = max(s1[i][j],s1[i][j+2]);
        }
    }

    for(int j=n-1;j>=0;--j){
        for(int i=n-3;i>=0;--i){
            s2[i][j] = max(s2[i][j],s2[i+2][j]);
        }
    }

    int e =-1, o=-1;
    int r1=1, c1=1, r2=1, c2=2;

    for(int i=0;i<n;++i){

        for(int j=0;j<n;++j){

            if ((i+j)%2 == 0) {
                if (grid[i][j] > e) {
                    e = grid[i][j];
                    r1 = i;
                    c1 = j;
                }
            } else {
                if (grid[i][j] > o) {
                    o = grid[i][j];
                    r2 = i;
                    c2 = j;
                }
            }
        }
    }

    cout <<e+o<<endl;
    cout <<r1+1<<" "<<c1+1<<" "<<r2+1<<" "<<c2+1<<endl;


}