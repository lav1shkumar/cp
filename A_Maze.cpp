#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
maybe put X on back edges type shit

i,j == i,j+1   i+1,j   i-1,j    i,j-1



*/
int n,m;
bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m) return true;
    return false;

}

vector<vector<bool>> vis;
vector<string> grid;

int cnt;
int dir[4][2]= {{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int i,int j){
    if(cnt==0) return;
    cnt--;

    vis[i][j]=1;

    for(auto [a,b]:dir){
        int r=i+a,c=b+j;

        if(valid(r,c) && grid[r][c]=='.' && !vis[r][c]){
            dfs(r,c);
        }

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

    int k;cin>>n>>m>>k;

    grid.assign(n," ");

    for(int i=0;i<n;++i) cin>>grid[i];



    int a,b;

    int t=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]!='.') continue;
            t++;
            a=i,b=j;
        }
    }

    vis.assign(n,vector<bool> (m,0));

    cnt = t-k;

    dfs(a,b);


    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]!='.' || vis[i][j]) continue;
            
            if(k==0) break;

            grid[i][j]='X';
            k--;
        }
    }

    for(int i=0;i<n;++i) cout<<grid[i]<<endl;
}