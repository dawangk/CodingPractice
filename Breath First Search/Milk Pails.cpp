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
const int MM = 1e2+5; int mod = 1e9+7;//998244353

int x, y, k, m;
int step[MM][MM];
int ans = 0;

int main(){
    inputJunk
    freopen("pails.in","r", stdin);
    freopen("pails.out","w", stdout);
    cin>>x>>y>>k>>m;
    queue<pi> q;
    ans = m;
    q.push({0, 0});
    for(int i =0;i<=100;i++){
        for(int j = 0;j<=100;j++){
            step[i][j] = -1;
        }
    }
    step[0][0] = 0;
    while(!q.empty()){
        int cur1 = q.front().f, cur2 = q.front().s; q.pop();
        if(step[cur1][y]==-1){
            step[cur1][y]=step[cur1][cur2]+1;
            q.push({cur1, y});
        }
        if(step[x][cur2]==-1){
            step[x][cur2]=step[cur1][cur2]+1;
            q.push({x, cur2});
        }
        if(step[cur1][0]==-1){
            step[cur1][0]=step[cur1][cur2]+1;
            q.push({cur1, 0});
        }
        if(step[0][cur2]==-1){
            step[0][cur2]=step[cur1][cur2]+1;
            q.push({0, cur2});
        }
        int sum = cur1+cur2;
        if(step[max(0,sum-y)][min(sum, y)]==-1){
            step[max(0,sum-y)][min(sum, y)]=step[cur1][cur2]+1;
            q.push({max(0,sum-y), min(sum, y)});
        }
        if(step[min(sum, x)][max(0, sum-x)]==-1){
            step[min(sum, x)][max(0, sum-x)]=step[cur1][cur2]+1;
            q.push({min(sum, x), max(0, sum-x)});
        }
    }

    for(int i =0;i<=100;i++){
        for(int j = 0;j<=100;j++){
            if(step[i][j]==-1)continue;
            if(step[i][j]<=k){
                ans = min(ans, abs(m-i-j));
            }
        }
    }
    cout<<ans<<ell;
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
