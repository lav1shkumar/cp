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

    int a,b;
    cin>>a>>b;

    if(a>b) swap(a,b);

    

    for(int x1=1;x1<a;++x1){

        int d = a*a - x1*x1;
        int y1 = round(sqrt(d));


        if(y1*y1!=d || y1<=0) continue;

        if((y1*b)%a!=0 || (x1*b)%a!=0) continue;

        int x2 = -y1*b/a;
        int y2 = x1*b/a;

        if(y1==y2 || x1==x2) continue;

        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<x1<<" "<<y1<<endl;
        cout<<x2<<" "<<y2<<endl;

        return 0;
    }

    cout<<"NO"<<endl;


}