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

    unordered_map<int,pair<int,int>> mp;
    int arr[6] = {4,8,15,16,23,42};

    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            mp[arr[i]*arr[j]] = {arr[i],arr[j]};
        }
    }

    int ans[6];

    cout<<"? 1 2"<<endl;
    int x; cin>>x;

    cout<<"? 2 3"<<endl;
    int y; cin>>y;

    auto [a,b] = mp[x];
    auto [c,d] = mp[y];

    int mid;
    if(a==c || a==d) mid=a;
    if(b==c || b==d) mid=b;

    ans[1]=mid;
    ans[0]=x/mid;
    ans[2]=y/mid;

    cout<<"? 4 5"<<endl;
    cin>>x;
    cout<<"? 5 6"<<endl;
    cin>>y;

    tie(a,b)=mp[x];
    tie(c,d)=mp[y];

    if(a==c || a==d) mid=a;
    if(b==c || b==d) mid=b;


    ans[4]=mid;
    ans[3]=x/mid;
    ans[5]=y/mid;


    cout<<"! ";
    for(int i=0;i<6;++i){
        cout<<ans[i]<<" ";
    }
    
    cout.flush();

}