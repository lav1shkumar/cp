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

    int cnt=0;
    for(char c:s){
        if(isupper(c)) cnt++;
        else cnt--;
    }

    if(cnt>0){
        for(char &c:s) c=toupper(c);
        cout<<s<<endl;
        return 0;
    }
    for(char &c:s) c=tolower(c);
    cout<<s<<endl;


    

}