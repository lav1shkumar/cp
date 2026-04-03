#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
int m,s;

string mini,maxi;

int dp[101][901];

bool solvemin(int idx,int sum,string &str){
    if(idx==m){
        if(sum!=s) return false;
        mini=str;
        return true;
    }

    if(dp[idx][sum]!=-1) return dp[idx][sum];

    int l= idx!=0? 0:1;
    
    for(int i=l;i<=9;++i){
        str.push_back(i+'0');
        if(solvemin(idx+1,sum+i,str)) return dp[idx][sum]=true;
        str.pop_back();

    }

    return dp[idx][sum]=false;

}

bool solvemax(int idx,int sum,string &str){
    if(idx==m){
        if(sum!=s) return false;
        maxi=str;
        return true;
    }

    if(dp[idx][sum]!=-1) return dp[idx][sum];

    int l= idx!=0? 0:1;
    
    for(int i=9;i>=l;--i){
        str.push_back(i+'0');
        if(solvemax(idx+1,sum+i,str)) return dp[idx][sum]=true;
        str.pop_back();

    }

    return dp[idx][sum]=false;

}


int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>s;

    if(m==1 && s==0){
        cout<<"0 0"<<endl;
        return 0;
    }

    string str;
    memset(dp,-1,sizeof(dp));
    solvemin(0,0,str);
    str.clear();
    memset(dp,-1,sizeof(dp));
    solvemax(0,0,str);


    if(mini=="" || maxi==""){
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }

    cout<<mini<<" "<<maxi<<endl;

}

