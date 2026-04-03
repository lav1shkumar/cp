#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*

sum | sum | sum 

first of all, t%3==0

fixing a point r
2*sum| sum

how many l's possible? ---> nums can be neg or pos
can i use dp for 2*sum, pref sum?
can i use map? to find no of pref == sum, --? sum | sum | sum

i think yes


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

    vector<int> a(n);
    int t=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        t+=a[i];
    }

    if(t%3!=0){
        cout<<0<<endl;
        return 0;
    }
    
    int sum=t/3;

    vector<int> pref(n,0);
    pref[0]=a[0];

    for(int i=1;i<n;++i) pref[i]=pref[i-1]+a[i];

    unordered_map<int,int> mp;

    int ans=0;

    int p=0;
    for(int i=0;i<n-1;++i){

        if((t-pref[i]) == sum){
            // now we know its 2*sum | sum

            ans+=mp[sum];

        }
        
        mp[pref[i]]++;
    }

    cout<<ans<<endl;




}