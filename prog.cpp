#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define vii vector<int>
#define vll vector<long long int>
#define pi pair<int,int>
#define pll pair<long long int, long long int>
#define vvl vector<vll>
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nl "\n"
#define debug(x) cerr << x << nl;
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9 + 7,inf = 1e18;//998244353
ll expo(ll x, ll y){ll res=1;x%=mod;while(y){if(y%2)res=(res*x%mod)%mod;x=(x*x)%mod;y/=2;}return res;}
ll inv(ll x) {return expo(x,mod-2);}
ll madd(ll a, ll b){a=a%mod;b=b%mod;return(((a + b) % mod)+mod)%mod;}
ll mmul(ll a, ll b){a=a%mod;b=b%mod;return(((a * b) % mod)+mod)%mod;}
ll msub(ll a, ll b){a=a%mod;b=b%mod;return(((a - b) % mod)+mod)%mod;}
ll mdiv(ll a, ll b){a=a%mod;b=b%mod;return(mmul(a, inv(b))+mod)%mod;}
ll gcd(ll a, ll b){if(b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return a/gcd(a,b) * b;}

string PerformOp(vector<string> &v){
    int n = v.size();
    vector<vector<int>> res;
    for(auto s:v){
        vector<int> x;
        for(ll i=1; i<s.size(); i++){
            x.push_back(s[i]-s[i-1]);
        }
        res.push_back(x);
    }

    set<vector<int>> st1;
    for(int i=1; i<n; ++i){
        st1.insert(res[i]);
    }

    if(st1.size() == 1){
        return v[0];
    }

    set<vector<int>> st2;
    st2.insert(res[0]);
    for(int i=1; i<n; ++i){
        st2.insert(res[i]);
        if(st2.size() > 1){
            return v[i];
        }
    }

}

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &i:v)cin >> i;

    cout << PerformOp(v);
    return 0;
}