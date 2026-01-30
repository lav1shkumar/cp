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

    int n,a,b,k;cin>>n>>a>>b>>k;
    string s;cin>>s;

    vector<int> arr;
    int cnt=0;
    for(int i=0;i<n;++i){
        if(s[i]=='0') cnt++;
        if(cnt==b){
            cnt=0;
            arr.push_back(i+1);
        }
        if(s[i]=='1') cnt=0;
    }

    int mini = arr.size()-a+1;
    cout<<mini<<endl;
    for(int i=0;i<mini;++i) cout<<arr[i]<<" ";
    cout<<endl;

}