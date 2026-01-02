#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/


void solve(){
    int n;
    cin>>n;

    vector<int> tea(n);
    vector<int> tester(n);
    vector<int> ans(n);
    vector<int> diff(n);
    vector<int> pref(n);

    for(int i=0;i<n;++i) cin>>tea[i];

    cin>>tester[0];
    pref[0]=tester[0];

    for(int i=1;i<n;++i){
        cin>>tester[i];
        pref[i]=pref[i-1]+tester[i];
    }


    for(int i=0;i<n;++i){

        int ub= i==0? tea[i]:tea[i]+pref[i-1];

        int ind=upper_bound(pref.begin()+i,pref.end(),ub)-pref.begin();
        if(ind==i) ans[i]+=tea[i];
        else{
            diff[i]+=1;
            if(ind!=n){
                diff[ind]-=1;
                int prefSum= i==0? pref[ind-1]:pref[ind-1]-pref[i-1];
                ans[ind]+=tea[i]-prefSum;
            }
        }
        //cout << ind << " ";
    }
    for(int i=1;i<n;++i){
        diff[i]=diff[i-1]+diff[i];
    }
    for(int i=0;i<n;++i){
        ans[i]+=diff[i]*tester[i];
        cout << ans[i] << " ";
    }
    cout << endl;





}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

}