#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
-2 1 4 7 10 == 3 3 

1 3 5 9 == 2 2 4 == one only possible
// diff = 2 2 4 5 then its not possible, what should i do here??

-2 10

if we have >=2 n, then we have restriction for sure, 
if all equal then 2

alright, n==1 ans==-1
else 2 if already ap, else 1 if one of them differs


3 4 4 5 == 1 0 1
3 3 3 4 == 0 0 1

i can only decrease it that too in half, 1/2==0 so not possible

so basically, unique one should have freq of 1 and should be double of rest

2 4 == 
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

    map<int,int> mp;
    for(int i=0;i<n;++i) cin>>a[i];

    if(n==1){
        cout<<-1<<endl;
        return 0;
    }

    sort(a.begin(),a.end());

    for(int i=1;i<n;++i) mp[a[i]-a[i-1]]++;

    if(mp.size()>2){
        cout<<0<<endl;
    }

    else{
        int diff = a[1]-a[0];
        if(mp.size()==1){
            if(diff==0){
                cout<<1<<endl<<a[0]<<endl;
                return 0;
            }
            if(n>2 || diff&1){
                cout<<2<<endl;
                cout<<a[0]-diff<<" "<<a[n-1]+diff<<endl;
            }
            else{
                cout<<3<<endl;
                cout<<a[0]-diff<<" "<<a[0]+diff/2<<" "<<a[n-1]+diff<<endl;
            }
        }

        else{
            auto [k1,v1] = *mp.begin();
            auto [k2,v2] = *prev(mp.end());

            if(v2!=1 || 2*k1!=k2){
                cout<<0<<endl;
                return 0;
            }
            else{
                cout<<1<<endl;
                for(int i=1;i<n;++i){
                    if(a[i] - a[i-1] == k2){
                        cout<<a[i-1]+k1<<endl;
                        return 0;
                    }
                }
                
            }

        }






    }

}