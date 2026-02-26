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

    int n,k; cin>>n>>k;

    vector<string> a(n);
    vector<vector<int>> one(n,vector<int>(n,0));
    vector<vector<int>> two(n,vector<int>(n,0));

    for(int i=0;i<n;++i) cin>>a[i];

    for(int i=0;i<n;++i){
        int len=0;
        for(int j=0;j<n;++j){
            if(a[i][j]=='.'){
                len++;
                if(len>=k){
                    one[i][j-k+1]+=1;
                    if(j+1 < n) one[i][j+1]-=1;
                }
            }
            else len=0;
        }
    }

    for(int i=0;i<n;++i){
        for(int j=1;j<n;++j){
           one[i][j]+=one[i][j-1];
        }
    }

    for(int j=0;j<n;++j){
        int len=0;
        for(int i=0;i<n;++i){
            if(a[i][j]=='.'){
                len++;
                if(len>=k){
                    two[i-k+1][j]+=1;
                    if(i+1<n) two[i+1][j]-=1;
                }
            }
            else len=0;
        }
    }

    for(int j=0;j<n;++j){
        for(int i=1;i<n;++i){
           two[i][j]+=two[i-1][j];
        }
    }

    int maxi=INT_MIN;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
           maxi=max(maxi,two[i][j]+one[i][j]);
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(two[i][j]+one[i][j]==maxi){
                cout<<i+1<<" "<<j+1<<endl;
                return 0;
           }
        }
    }




}