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

    int n,k;cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;++i) cin>>a[i];

    unordered_map<int,int> freq;
    unordered_map<int,set<int>> sets;

    int max_f=0;

    for(int i=0;i<k;++i){
        int f = freq[a[i]]++;
    
        if(f!=0){
            sets[f].erase(a[i]);
        }
        sets[f+1].insert(a[i]);

        max_f = max(max_f,freq[a[i]]);
    }

    cout<<*sets[max_f].begin()<<" ";

    for(int r=k;r<n;++r){
        int l=r-k;

        if(a[l]==a[r]){
            cout<<*sets[max_f].begin()<<" ";
            continue;
        }

        // add
        int f = freq[a[r]]++;
    
        if(f!=0){
            sets[f].erase(a[r]);
        }
        sets[f+1].insert(a[r]);
        max_f = max(max_f,freq[a[r]]);

        //remove
        f = freq[a[l]];
        freq[a[l]]--;
        sets[f].erase(a[l]);

        if(max_f==f && sets[f].empty()) max_f--;
        
        if(f-1>0){
            sets[f-1].insert(a[l]);
        }

        cout<<*sets[max_f].begin()<<" ";
    }

}