#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
no of subarrays, element sum == its size
length can be from 1 to n

n^2 way is to form subarray and check sum

if I inc len, sum can inc or stay same bcz of zero,
if Sum>len, then i should inc length or maybe decreasing can make sum<=len

wait ele 0 to 9
600005
6 6 6 6 6 11 -- prefix sum
pref(r)-pref(l-1) = sum of l to r == r-l+1
pref(r)-r  == pref(l-1)-(l-1)

these two must be equal
so at some idx i i need to find pref(i)-i
basically count them


1 1 1 1 1 == r-l+1
0 0 0 0 0 == 0

no of subarr where sum==0
*/


void solve(){
    int n;cin>>n;
    string s;cin>>s;

    int ans=0;
    unordered_map<int,int> mp;
    mp[0]=1;

    int pref=0;
    for(int i=0;i<n;++i){
        int v = (s[i]-'0')-1;
        pref+=v;
        // to make it zero we need pref==prevpref
        ans+=mp[pref];
        mp[pref]++;
    }

    cout<<ans<<endl;


}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();

}