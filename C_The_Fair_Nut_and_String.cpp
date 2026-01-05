#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
i need to find splits and its size
split consists of aaaa
split position is at b
first of all -- ++number of a, singleton
then count the streak, is found b, ans*=strean and streak==0

aaabbaabbaa   
3    2    2
3+6+12

abbaa
1   2
1+2 == 3
a = 3,b=2 actually 1

there are 3 splits means sizeof 1,2,3

nope, its a dp sort of problem, is there is b those a i can pick to form sequence
if i can pick some a's , then cant+=can++;

abbaa === 1 , 2
can=1
cant=can++ = 2
cant = 2+2 = 4

*/



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();

    int can=0;
    int cant=0;

    for(char c:s){
        if(c=='a'){
            cant=(cant+can+1)%MOD;
        }
        else if(c=='b'){
            can=(can+cant)%MOD;
            cant=0;
        }
    }

    cout<<(can+cant)%MOD<<endl;


}