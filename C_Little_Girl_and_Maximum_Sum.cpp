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

    int n,q;cin>>n>>q;

    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    vector<pair<int,int>> coor(q),temp;
    for(int i=0;i<q;++i) cin>>coor[i].first>>coor[i].second;

    vector<int> delta(n+1);
    for(auto [i,j]:coor){
        delta[--i]++;
        delta[j]--;
    }

    for(int i=1;i<n;++i) delta[i]+=delta[i-1];
    
    for(int i=0;i<n;++i){
        temp.push_back({delta[i],i});
    }

    sort(temp.rbegin(),temp.rend());
    sort(arr.begin(),arr.end());


    vector<int> vec(n);

    for(auto [f,idx]:temp){
        vec[idx] = arr.back();
        arr.pop_back();
    }

    vector<int> pref(n,0);
    pref[0]=vec[0];
    for(int i=1;i<n;++i) pref[i]=pref[i-1]+vec[i];

    int ans=0;
    for(auto [l,r]:coor){
        l--,r--;

        if(l==0) ans+=pref[r];
        else ans+=(pref[r]-pref[l-1]);
    }

    cout<<ans<<endl;



}