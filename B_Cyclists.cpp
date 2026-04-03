#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
3 2 2 6

1 2 3

2 1 2





*/


void solve(){
    int n,k,p,m;cin>>n>>k>>p>>m;
    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;++i){
        int a;cin>>a;
        int j=0;
        if(i==p-1) j=1;

        arr[i]={a,j};
    }   

    int count=0;

    while(1){
        int found = -1;
        for(int i=0;i<k;++i){
            if(arr[i].second){
                found=i;
            }
        }

        if(found==-1){
            int c=LLONG_MAX;
            // get smaller one
            for(int i=0;i<k;++i){
                if(arr[i].first<c){
                    c=arr[i].first;
                    found=i;
                }

            }

        }

        if(m>=arr[found].first){
            m-=arr[found].first;


            if(arr[found].second) count++;

            auto e = arr[found];
            arr.erase(arr.begin()+found);
            arr.push_back(e);

        }
        else break;

    }


   cout<<count<<endl;


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