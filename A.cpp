#include <bits/stdc++.h>
#define ll long long
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

void solve() {
    ll n;
    cin>>n;
    vector<ll> x;
    vector<vector<ll>> y;
    ll sumx=0,sumy=0;
    for(ll i=0;i<n;i++){
        ll tem;
        cin>>tem;
        sumx+=tem;
        x.push_back(tem);
    }
    for(ll i=0;i<n;i++){
        ll tem;
        cin>>tem;
        sumy+=tem;
        y.push_back({x[i],tem});
    }
    sort(y.begin(), y.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[1] > b[1];
    });

    ll min_container=0;
    ll i=0;
    ll sumt=0;
    for(int i=0;i<n;i++){
        sumt+=y[i][1];
        if(sumt>=sumx){
            min_container=i+1;
            break;
        }
    }

    vector<vector<int>> dp={};
    for(int i=0;i<min_container+1;i++){
        vector<int> temp={};
        for(int j=0;j<sumy+1;j++){
            temp.push_back(-1);
        }
        dp.push_back(temp);
    }

    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=min_container;j>=1;j--){
            for(int k=sumy;k>=y[i][1];k--){
                if (dp[j - 1][k - y[i][1]] != -1) {
                    if(dp[j - 1][k - y[i][1]] + y[i][0]>dp[j][k]){
                        dp[j][k]=dp[j - 1][k - y[i][1]] + y[i][0];
                    }
                }
            }
        }
    }

    int mx=0;
    for(int i=sumx;i<=sumy;i++){
        if(dp[min_container][i]>mx){
            mx=dp[min_container][i];
        }
    }
    cout<<min_container<<' '<<sumx-mx;
}

int main() {
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
