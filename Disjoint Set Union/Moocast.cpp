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

int n; pi coord[MM]; int dists[MM][MM];

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

int finddis(pi a, pi b){
    return abs(a.f-b.f)*abs(a.f-b.f)+abs(a.s-b.s)*abs(a.s-b.s);
}
bool valid(int dist){
    //cout<<"dfasdfas"<<dist<<endl;
    DSU d; d.init(n+1);
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(dists[i][j]<=dist){
                d.unite(i, j);
                //cout<<i<<" "<<j<<endl;
            }
        }
    }

    //cout<<d.size(0)<<endl;
    if(d.size(0)==n)return true;
    return false;
}

int main(){
    inputJunk
    freopen("moocast.in","r", stdin);
    freopen("moocast.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        int a,b;cin>>a>>b;coord[i] = {a, b};
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            dists[i][j] = finddis(coord[i], coord[j]);
        }
    }
    int lo = 0, hi = 1000000000;

    while(lo<hi){
        int mid = (lo+hi+1)/2;
        if(valid(mid)){
            hi = mid-1;
        }else{
            lo = mid;
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
