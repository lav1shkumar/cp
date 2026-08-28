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

    string s;cin>>s;

    int n=s.size();

    int odd_a=0,odd_b=0,even_a=0,even_b=0;

    int ans_even=0,ans_odd=0;

    for(int i=0;i<n;++i){
        if(i&1){
            if(s[i]=='a'){
                odd_a++;
                ans_even+=even_a;
                ans_odd+=odd_a;
            }
            else{
                odd_b++;
                ans_even+=even_b;
                ans_odd+=odd_b;

            }
        }
        else{
            if(s[i]=='a'){
                even_a++;
                ans_even+=odd_a;
                ans_odd+=even_a;
            }
            else{
                even_b++;
                ans_even+=odd_b;
                ans_odd+=even_b;

            }

        }

    }

    cout<<ans_even<<" "<<ans_odd;

}