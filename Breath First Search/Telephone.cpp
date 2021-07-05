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
const int MM = 5e4+5; int mod = 1e9+7;//998244353

int n, k, breed[MM]; char grid[55][55];
int dist[55][MM];
int main(){
    inputJunk

    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>breed[i];
    }

    for(int i= 1;i<=k;i++){
        for(int j = 1;j<=k;j++){
            char c; cin>>c;
            grid[i][j] = c;
        }
        grid[i][0] = grid[i][breed[n]];
    }
    breed[n] = 0;


    deque<pi> q;
    q.pb({breed[1],1});

    for(int i = 0;i<=k;i++){
        for(int j = 0;j<=n;j++){
            dist[i][j] = -1;
        }
    }
    dist[breed[1]][1] = 0;
    while(!q.empty()){
        int curbreed = q.front().f, loc = q.front().s;q.pop_front();
        //cout<<curbreed<<" "<<loc<<endl;
        if(loc-1>=1&&dist[curbreed][loc-1]==-1){
            dist[curbreed][loc-1] = dist[curbreed][loc]+1;
            q.pb({curbreed, loc-1});
        }

        if(loc+1<=n&&dist[curbreed][loc+1]==-1){
            dist[curbreed][loc+1] = dist[curbreed][loc]+1;
            q.pb({curbreed, loc+1});
        }

        if(grid[curbreed][breed[loc]]=='1'&&dist[breed[loc]][loc]==-1){
            //cout<<" "<<curbreed<<" "<<loc<<endl;
            //cout<<curbreed-1<<" "<<breed[loc]-1<<endl;
            //cout<<breed[loc]<<" "<<loc<<endl;
            //cout<<dist[breed[loc]][loc]<<" "<<dist[curbreed][loc]<<endl;
            q.push_front({breed[loc], loc});
            dist[breed[loc]][loc] = dist[curbreed][loc];
        }
    }
    /*
    for(int i = 0;i<=k;i++){
        for(int j = 0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }cout<<ell;
    }*/
    cout<<dist[0][n]<<ell;
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
- upperbound and lowerbound returns iterators
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
