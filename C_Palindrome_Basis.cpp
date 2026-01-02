#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/
vector<vector<int>> dp;
bool isPalindrome(int x) {

    int original = x;
    long long rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev == original;
}

int count(int i,int sum,vector<int> &palindromes){
    if(sum==0) return 1;
    if(i==palindromes.size()) return 0;

    if(dp[i][sum]!=-1) return dp[i][sum];

    int pick = 0;
    if(sum-palindromes[i]>=0) pick = count(i,sum-palindromes[i],palindromes);

    int skip = count(i+1,sum,palindromes);

    return dp[i][sum]=(pick+skip)%MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    int n=0;
    vector<int> q(t);
    for(int i=0;i<t;++i){
        cin>>q[i];
        n=max(n,q[i]);
    }

    vector<int> palindromes;
    for(int i=1;i<=n;++i){
        if(isPalindrome(i)) palindromes.push_back(i);
    }
    
    dp.assign(palindromes.size(),vector<int> (n+1,-1));

    for(int i=0;i<t;++i){
        cout<<count(0,q[i],palindromes)<<endl;
    }

}