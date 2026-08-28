#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
dp[i] == max possible score by choosing some subset of rectangles till i

*/

struct Line {
    int s,i;

    Line(int slope,int intercept){
        this->s=slope;
        this->i=intercept;
    }

};

struct Hull{
    vector<pair<int,Line>> v;

    void insert(int slope,int intercept){

        while(!v.empty()){
            auto a = v.back();

            if(slope!=a.second.s){
                int x = (a.second.i-intercept)/(slope-a.second.s);

                if(x>=v.back().first) v.pop_back();
                else break;
            }
            else{
                if(intercept<=a.second.i) return;
                v.pop_back();
            }
        }

        if(v.empty()){
            v.push_back({LLONG_MIN,Line(slope,intercept)});
        }
        else{
            auto a = v.back();
            int x = (a.second.i-intercept)/(slope-a.second.s);
            v.push_back({x,Line(slope,intercept)});
        }
    }


    int query(int x){
        if (v.empty()) return 0;

        auto t = *--upper_bound(v.begin(),v.end(),x,[](auto &x,auto &a){
            return x<a.first;
        });

        auto line = t.second;
        return x*line.s+line.i;
    }

};



int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    vector<tuple<int,int,int>> v;

    for(int i=0;i<n;++i){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({a,b,c});
    }

    sort(v.begin(),v.end());
    Hull hull;


    vector<int> dp(n+1,0);

    int ans=0;

    for(int i=0;i<n;++i){
        auto [x,y,a] = v[i];

        dp[i] = hull.query(y)-a+x*y;
        dp[i] = max(dp[i],-a+x*y);

        ans=max(ans,dp[i]);

        hull.insert(-x,dp[i]);
    }


    cout<<ans<<endl;
}