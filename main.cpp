#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*




*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;

    int plus=0,minus=0;
    for(int i=0;i<n;++i){
        char tmp;
        cin>>tmp;
        if(tmp=='+') plus++;
        else minus++;
    }

    int a = max(plus,minus);
    int b = min(plus,minus);
    plus=a;
    minus=b;

    int q;cin>>q;

    vector<pair<int,int>> controller(n);
    for(int i=0;i<n;++i){
        cin>>controller[i].first;
        cin>>controller[i].second;
    }

    for(int i=0;i<q;++i){
        int a = min(controller[i].first,controller[i].second);
        int b = max(controller[i].first,controller[i].second);

        if(plus==minus){
            cout<< "YES" <<endl;
            continue;
        }
        else{
            if(a*plus>b*minus) {
                cout<< "NO" <<endl;
                continue;
            }
            else{
                int diff = abs(b*minus-a*plus);
                int delta = abs(a-b);

                if(diff%delta==0 && diff/delta<=a+b){
                    cout<< "YES" <<endl;
                    continue;
                }
                else{
                    cout<< "NO" <<endl;
                    continue;
                }


            }

        }

    }





}