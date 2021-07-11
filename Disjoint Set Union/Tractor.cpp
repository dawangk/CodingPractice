#include <bits/stdc++.h>
using namespace std;
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
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e3+5; int mod = 1e9+7;//998244353

int n, grid[MM][MM];

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) {return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

bool valid(int dif){
    DSU d; d.init(n*n+5);
    //cout<<dif<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i!=n-1&&abs(grid[i][j]-grid[i+1][j])<=dif){
                d.unite(i*n+j, i*n+n+j);
            }
            if(j!=n-1&&abs(grid[i][j]-grid[i][j+1])<=dif){
                d.unite(i*n+j, i*(n)+j+1);
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            //cout<<d.size(i*n+j)<<endl;
            if(d.size(i*n+j)>=(n*n)/2){return true;}
        }
    }//cout<<"false"<<endl;
    return false;
}


int main(){
    inputJunk
    freopen("tractor.in","r", stdin);
    freopen("tractor.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int lo  = 0, hi = 1000005;
    while(lo<hi){
        int mid = (lo+hi+1)/2;
        if(!valid(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    cout<<lo+1<<ell;
}
/*CUSTOM TEST CASE 1
*/

/*CUSTOM TEST CASE 2
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
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
