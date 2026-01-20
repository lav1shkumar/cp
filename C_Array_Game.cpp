#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
4 3
7 4 15 12

curr min == 4
can we reduce it?
i can do n square
do diff from 7 to all = 3 8 5
            4           11 8
            15          3

            int 2 op i can pick 7 and 4,
            wait if i pick same pair 2 times append, then i can pick two same appended value and make 0

            in k==3, ans=0;
            k==2? min diff = pick the diff that is closest to the number, if same ans=0 rest the diff between them
            k==1?? ans = min diff over all pairs or min element



*/


void solve(){
    int n,k;cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    if(k>=3){
        cout<<0<<endl;
        return;
    }

    int mini = LLONG_MAX;
    for(int v:arr) mini=min(mini,v);

    vector<int> diff;
    int minidiff=LLONG_MAX;
    for(int i=0;i<n;++i){
        int v=arr[i];
        for(int j=i+1;j<n;++j){
            int delta = abs(v-arr[j]);
            minidiff=min(minidiff,delta);
            diff.push_back(delta);
        }
    }

    if(k==1){
        cout<<min(minidiff,mini)<<endl;
        return;
    }
    
    int mindelta=LLONG_MAX;
    sort(diff.begin(),diff.end());
    for(int v:arr){
        // find closest
        int idx = lower_bound(diff.begin(),diff.end(),v)-diff.begin(); // equal or >
        // check at idx and idx-1
        int b = LLONG_MAX, a=LLONG_MAX;
        if(idx>=0 & idx<diff.size()) a = abs(v-diff[idx]);
        if(idx>=1) b=abs(v-diff[idx-1]);
        mindelta=min({mindelta,a,b});
    }

    cout<<min({mini,minidiff,mindelta})<<endl;

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