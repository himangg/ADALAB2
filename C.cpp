#include <bits/stdc++.h>
#define ll long long
#include <limits>
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

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

int dfs(int v,vector<int>& depth,vector<vector<int>>& adj){
    if(depth[v]!=-1){
        return depth[v];
    }
    int mx=1;
    for(int i=0;i<adj[v].size();i++){
        if(depth[adj[v][i]]==-1){
            if(adj[v][i]<v) {
                mx=max(mx,(1 + dfs(adj[v][i], depth, adj)));
            }
        }
        else{
            mx=max(mx,(1+depth[adj[v][i]]));
        }
    }
    depth[v]=mx;
    return mx;
}

void solve(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g.addEdge(x-1,y-1);
    }
    vector<vector<int>> adj=g.adj;
    vector<int> depth(n,-1);
    int ans=1;
    for(int i=0;i<n;i++){
        int endPoint=i;
        int noOfAdj=adj[endPoint].size();;
        int deep=dfs(endPoint,depth,adj);
        if(ans<noOfAdj*deep){
            ans=noOfAdj*deep;
        }
    }
    cout<<ans;
}

int main() {
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
