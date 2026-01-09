#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
sum of digits max = 9*8 = 72 == 80
can i generate these three numbers using digit dp?
digsum of these 3 numbers == digsum of n, that i can enforce
but a+b+c = n, wait i can check this too
b,t,w a,b,c<=n ,, tight bound


wait

digit sum == 4,12,10 === 4+1+2+1+0 == 2+6
got it, the num of a+b+c should contain no carry

a = 12 , b=4, c=10 , 2,2+4+0== 26

so for every i == ai+bi+ci<=9 and ==n[i];


*/
vector<int> cnt;
void run(){
    for(int i=0;i<10;++i)
    for(int j=0;j<10;++j)
    for(int k=0;k<10;++k){
        if(i+j+k<=9) cnt[i+j+k]++;
    }

}

void solve(){
    int n;cin>>n;
    string num=to_string(n);

    int ans = 1;
    for(char c:num){
        ans*=cnt[c-'0'];
    }
    cout<<ans<<endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cnt.assign(10,0);
    run();
    int t; cin >> t;
    while(t--) solve();

}