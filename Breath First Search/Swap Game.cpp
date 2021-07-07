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
const int MM = 8e2+5; int mod = 1e9+7;//998244353

int grid[3][3], p[10];
int horzswap[6] = {0,1,3,4,6,7}, vertswap[6] = {0, 1, 2, 3, 4, 5};
int target = 0;
int main(){
    inputJunk
    p[0] = 1;
    for(int i =1;i<10;i++){
        p[i] = 9*p[i-1];
    }
    int ind = 0, compress = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin>>grid[i][j];
            compress+=grid[i][j]*p[ind];
            target+=(ind+1)*p[ind];
            ind++;
        }
    }
    //cout<<p[9]<<" "<<compress<<" "<<endl;
    vector<bool> v (p[9]*2, false);
    queue<pi> q;
    q.push({compress, 0});
    v[compress] = true;
    while(!q.empty()){
        int cur = q.front().f, vvv = q.front().s; q.pop();
        //cout<<cur<<" "<<vvv<<endl;
        vector<int> values;
        if(cur==target){
            cout<<vvv<<ell;
            return 0;
        }

        while(cur>1){
            int curk = cur%9;
            if(curk==0){curk+=9;cur-=9;}
            values.pb(curk);
            cur/=9;

        }
        if(values.size()==8)values.pb(1);
        //for(int x:values)cout<<x<<" ";cout<<endl;
        for(int i = 0;i<6;i++){
            swap(values[horzswap[i]], values[horzswap[i]+1]);
            int newval = 0;
            for(int i = 0;i<9;i++){
                newval+=p[i]*values[i];
            }
            //cout<<newval<<endl;
            //for(int x:values)cout<<x<<" ";cout<<endl;
            if(!v[newval]){
                v[newval] = true;
                q.push({newval, vvv+1});
            }
            swap(values[horzswap[i]], values[horzswap[i]+1]);
        }
        for(int i = 0;i<6;i++){
            swap(values[vertswap[i]], values[vertswap[i]+3]);
            int newval = 0;
            for(int i = 0;i<9;i++){
                newval+=p[i]*values[i];
            }
            //cout<<newval<<endl;
           // for(int x:values)cout<<x<<" ";cout<<endl;
            if(!v[newval]){
                    v[newval] = true;
                q.push({newval, vvv+1});
            }
            swap(values[vertswap[i]], values[vertswap[i]+3]);
        }
    }
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
