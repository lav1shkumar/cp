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

    int x,a,b,c; cin>>x>>a>>b>>c;

    vector<int> arr(n);
    arr[0]=x;

    for(int i=1;i<n;++i){
        arr[i] = ((a*arr[i-1]) + b) % c;

    }

    deque<int> mn;
   
    for(int i=0;i<k;++i){
        while(!mn.empty() && arr[mn.back()]>=arr[i]) mn.pop_back();
        mn.push_back(i);
    }


    int XOR=arr[mn.front()];

    for(int i=k;i<n;++i){
        int l=i-k;

        while(!mn.empty() && arr[mn.back()]>=arr[i]) mn.pop_back();
        mn.push_back(i);

        if(mn.front()==l) mn.pop_front();

        XOR^=arr[mn.front()];

    }

    cout<<XOR<<endl;


}