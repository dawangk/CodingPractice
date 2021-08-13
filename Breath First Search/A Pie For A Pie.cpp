#include <bits/stdc++.h>
using namespace std;
//#include <ext/rope>
//using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug cout<<"HERE"<<endl;
#define ell "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<int, pi> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;
typedef vector<tripll> vtripll;

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 2e5+5; int mod = 1e9+7;//99824435

int n, d, depth[MM], fi[MM], se[MM];

struct cmpfi{
    bool operator()(int a, int b) const{
        return se[a]<se[b];
    }
};

struct cmpse{
    bool operator()(int a, int b) const{
        return fi[a]<fi[b];
    }
};


int main(){
    inputJunk
    //*
    freopen("piepie.in","r", stdin);
    freopen("piepie.out","w", stdout);
    //*/
    cin>>n>>d;
    for(int i = 0;i<2*n;i++){
        cin>>fi[i]>>se[i];fi[i] = -fi[i]; se[i] = -se[i];
        depth[i] = -1;
    }

    queue<int> q;
    multiset<int, cmpfi> sf;
    multiset<int, cmpse> ss;
    for(int i = 0;i<n;i++){
        if(se[i]==0){
            depth[i] = 1;
            q.push(i);
        }else{
            sf.insert(i);
        }
        if(fi[n+i]==0){
            depth[n+i] = 1;
            q.push(n+i);
        }else{
            ss.insert(n+i);
        }
    }

    while(!q.empty()){
        int cur = q.front();q.pop();

        if(cur<n){//bessie's pie
            while(true){
                auto it = ss.lower_bound(cur);
                if(it==ss.end()||fi[*it]>fi[cur]+d)break;
                depth[*it] = depth[cur]+1;
                q.push(*it);
                ss.erase(it);
            }
        }else{//elsie's pie
            while(true){
                auto it = sf.lower_bound(cur);
                if(it==sf.end()||se[*it]>se[cur]+d)break;
                depth[*it] = depth[cur]+1;
                q.push(*it);
                sf.erase(it);
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<depth[i]<<ell;
    }
}
/*CUSTOM TEST CASE 1
3 2
1 3
2 4
5 0
3 5
6 4
2 1
*/

/*CUSTOM TEST CASE 2
4 1
1 0
3 2
5 0
2 1
0 3
1 2
5 5
4 1
*/

/*CUSTOM TEST CASE 3
*/

/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iteratorsf
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
- INF setting problems
- push vs pb
- check if things are used properly
- read the PROBLEM (directed vs undirected graph)
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
