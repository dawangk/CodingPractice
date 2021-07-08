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
const int MM = 3e2+5; int mod = 1e9+7;//998244353

int m, n, l, step[MM][MM]; vi members, regions[MM], adj[MM]; queue<int> q[MM];

bool valid(int a, int b, int c, int d){
    if(a==c&&b==d)return true;
    if(a==d&&b==c)return true;
    return false;
}

int main(){
    inputJunk
    cin>>m>>n>>l;
    for(int i = 0;i<l;i++){
        int a; cin>>a;
        members.pb(a);
    }
    for(int i = 1;i<=m;i++){
        int mm; cin>>mm;
        for(int j = 0;j<mm;j++){
            int a; cin>>a;
            regions[i].pb(a);
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            step[i][j] = INF;
        }
    }
    for(int i = 0;i<l;i++){
        int curtown = members[i];
        for(int j = 1;j<=m;j++){
            for(int k:regions[j]){
                if(k==curtown){
                    q[curtown].push(j);
                    step[curtown][j] = 0;
                    break;
                }
            }
        }
    }

    for(int i =1;i<=m;i++){
        for(int j= i+1;j<=m;j++){
            if(i==j)continue;
            bool f = false;
            for(int x = 0;x<regions[i].size();x++){
                for(int y = 0;y<regions[j].size();y++){
                    if(valid(regions[i][x], regions[i][(x+1)%regions[i].size()], regions[j][y], regions[j][(y+1)%regions[j].size()])){
                        adj[i].pb(j);
                        adj[j].pb(i);
                        f = true; break;
                    }
                }
                if(f)break;
            }
        }
    }
    /*for(int i = 0;i<l;i++){
        while(!q[members[i]].empty()){
            cout<<q[members[i]].front()<<" ";
            q[members[i]].pop();
        }cout<<endl;
    }*/
/*
    for(int i = 1;i<=m;i++){
        cout<<i<<"    ";
        for(int x: adj[i]){
            cout<<x<<" ";
        }cout<<endl;
    }*/

    for(int i = 0;i<l;i++){
        int curtown = members[i];
        while(!q[curtown].empty()){
            int cur = q[curtown].front(); q[curtown].pop();
            for(int x: adj[cur]){
                if(step[curtown][x]==INF){
                    step[curtown][x] = step[curtown][cur]+1;
                    q[curtown].push(x);
                }
            }
        }
    }
    int minsteps = INF, mintown = -1;
    for(int i= 1;i<=m;i++){
        int steps = 0;
        for(int j = 0;j<l;j++){
            steps+=step[members[j]][i];
        }
        //cout<<i<<" "<<steps<<endl;
        if(steps<minsteps){
            minsteps = steps;
            mintown = i;
        }
    }

    cout<<minsteps<<ell<<mintown<<ell;
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
