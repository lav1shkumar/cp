#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


// Observations
/*
k == 1 - (n-1) --  1 2 3 4 5 ---> k=1,2,3,4

store diff,  along with indices and sort in dec
use sweep line === itertaing from n-1 -- 1
if diff>k active check neibour
if nei also active, merge using dsu
track count

count = n(n+1)/2 no of subarr



*/
struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false; // already in same set

        // union by size
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int getSize(int x) {
        return size[find(x)];
    }
};


void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    vector<pair<int, int>> diff;
    for (int i = 0; i < n - 1; ++i) {
        diff.push_back({abs(arr[i]-arr[i+1]),i});
    }
    sort(diff.rbegin(),diff.rend());



    DSU dsu(n);
    vector<bool> a(n, 0);
    vector<int> res(n);
    int total = 0;
    int ptr = 0;

    auto calc =[&](int x) {
        return x*(x+1)/2;
    };

    for (int k=n-1;k>=1;--k) {
        while (ptr <diff.size() && diff[ptr].first>=k) {
            int idx =diff[ptr].second;
            a[idx] = true;
            total++; 

            if (idx>0 && a[idx - 1]) {
                int a =dsu.find(idx);
                int b =dsu.find(idx - 1);
                if (a!=b) {
                    total-=calc(dsu.size[a]);
                    total -=calc(dsu.size[b]);
                    dsu.unite(a,b);
                    total+=calc(dsu.getSize(a));
                }
            }


    
            if (idx <n-2 && a[idx +1]) {
                int a =dsu.find(idx);
                int b = dsu.find(idx+1);
                if (a!=b) {
                    total-=calc(dsu.size[a]);
                    total-=calc(dsu.size[b]);
                    dsu.unite(a,b);
                    total +=calc(dsu.getSize(a));
                }
            }
            ptr++;
        }
        res[k] = total;
    }

    for (int i=1;i<n;++i) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

}

int32_t main(){

#ifdef lav1sh
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();

}