#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int gif(float n){
    return (n/1);
}

int lif(float n){
    if(n-gif(n)==0.0){
        return (n);
    }
    return ((n/1)+1);
}

int countNegative(vector<ll> v){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            count++;
        }
    }
    return count;
}

bool containZero(vector<ll> v){
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            return true;
        }
    }
    return false;
}

vector<ll> findDivisors(ll n) {
    vector<ll> divisors1={};
    vector<ll> divisors2={};
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors1.push_back(i);
            if (i != n / i) {
                divisors2.push_back(n / i);
            }
        }
    }
    for(ll i=divisors2.size()-1;i>=0;i--){
        divisors1.push_back(divisors2[i]);
    }
    return divisors1;
}

void displayVector(vector<ll> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll binarySearch(vector<ll> v, ll target,ll start, ll end){
    if(end-start==0){
        return start;
    }
    ll index = (start+end)/2;
    if(v[index]==target){
        return index;
    }
    else if(v[index]<target){
        return binarySearch(v,target,index+1,end);
    }
    else{
        return binarySearch(v,target,start,index-1);
    }
}

bool compareAbsolute(int a, int b) {
    return abs(a)<=abs(b);
}

void solve(){
    ll q;
    cin>>q;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<q;i++){
        ll m,x;
        cin>>m>>x;
        v.push_back(make_pair(m,x));
    }
    vector<vector<ll>> dp={};
    for(ll i=0;i<2;i++){
        vector<ll> temp={};
        for(ll j=0;j<1024;j++){
            temp.push_back(0);
        }
        dp.push_back(temp);
    }
    dp[0][0]++;
    for(ll i=0;i<q;i++){
        if(v[i].first==1){
            if(i==0){
                dp[0][v[0].second]++;
            }
            else{
                for(ll j=0;j<1024;j++){
                    dp[1][j]+=dp[0][j];
                    dp[1][j|v[i].second]+=dp[0][j];
                }
                for(ll j=0;j<1024;j++){
                    dp[1][j]=dp[1][j]%MOD;
                }
            }
        }
        else{
            if(i==0){
                if(v[i].second==0){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
            else {
                for (ll j = 0; j < 1024; j++) {
                    dp[1][j] += dp[0][j];
                }
                cout<<dp[1][v[i].second]%MOD<<endl;
            }
        }
        if(i>0) {
            for (int j = 0; j < 1024; j++) {
                dp[0][j] = dp[1][j];
                dp[1][j]=0;
            }
        }
    }
}

int main() {
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
