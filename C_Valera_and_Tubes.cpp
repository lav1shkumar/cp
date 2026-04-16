#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
so r>=2,
can i make like k-1 tubes of len 2 then rest goes to last




*/



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,int>>> tubes;
    for(int i=0;i<n;++i){

        if(i&1){
            for(int j=m-1;j>=0;--j){
                if(tubes.size()<k){
                    if(!tubes.empty() && tubes.back().size()<2) tubes[tubes.size()-1].push_back({i+1,j+1});
                    else{
                        tubes.push_back({{i+1,j+1}});
                    }
                }
                else{
                    tubes[k-1].push_back({i+1,j+1});
                }
                
            }
        }
        else{
            for(int j=0;j<m;++j){
                if(tubes.size()<k){
                    if(!tubes.empty() && tubes.back().size()<2) tubes[tubes.size()-1].push_back({i+1,j+1});
                    else{
                        tubes.push_back({{i+1,j+1}});
                    }
                }
                else{
                    tubes[k-1].push_back({i+1,j+1});
                }

            }
        }


    }


    for(int i=0;i<k;++i){
        cout<<tubes[i].size()<<" ";
        for(int j=0;j<tubes[i].size();++j) cout<<tubes[i][j].first<<" "<<tubes[i][j].second<<" ";

        cout<<endl;
    }


}