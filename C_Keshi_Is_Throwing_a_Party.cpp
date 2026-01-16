#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
i can sort them in asc

if j>=i+1 left condition done
if j>=i-1 right condition

wait, ith person has i dollar
So, i+1 person is richer then i
1 can only arrange them in order 

1 3 5 6 7
so arr[i].second>=cnt
ans if cnt friends are poorer and we are looking for M
req = M-cnt-1
ans[i].first>=M-cnt-1

*/
vector<pair<int,int>> arr;
bool check(int M){
    int cnt=0;
    for(auto [a,b]:arr){
        if((b>=cnt && a>=(M-cnt-1))) cnt++;
    }
    return cnt>=M;
}

void solve(){
    int n;cin>>n;
    arr.assign(n,{});
    for(int i=0;i<n;++i) cin>>arr[i].first>>arr[i].second;
    // sort(arr.begin(),arr.end(),[](auto &a,auto &b){
    //     if(a.first!=b.first) return a.first<b.first;
    //     else return a.second>b.second;
    // });

    int l=1,r=n;
    int ans=1;
    while(r>=l){
        int mid=(l+r)/2;

        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
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