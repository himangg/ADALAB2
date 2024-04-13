
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

class vertex{
public:
    int number;
    bool visited= false;
    bool pathVisited= false;
    int level=0;
    vector<int> adj={};
    vertex(int vNumber){
        this->number=vNumber;
    }
    void addEdge(int vNumber){
        this->adj.push_back(vNumber);
    }
};

void dfs(vector<int>& cyclicVertexes,vector<vertex>& vertexes,int source){
    vertexes[source].visited=true;
    vertexes[source].pathVisited=true;
    for(int i=0;i<vertexes[source].adj.size();i++){
        if(!vertexes[vertexes[source].adj[i]].visited) {
            dfs(cyclicVertexes,vertexes,vertexes[source].adj[i]);
        }
        else if(vertexes[vertexes[source].adj[i]].pathVisited){
            cyclicVertexes.push_back(vertexes[source].adj[i]);
        }
    }
    vertexes[source].pathVisited= false;
}

void bfs(vector<int>& ans,vector<int>& cyclicVertexes,vector<vertex>& vertexes,int source){
    vector<int> notVisited={source};
    ans[source]=1;
    int j=0;
    while(j<notVisited.size()){
        for (int i = 0; i < vertexes[notVisited[j]].adj.size(); i++) {
            if (ans[vertexes[notVisited[j]].adj[i]] == 0) {
                ans[vertexes[notVisited[j]].adj[i]] = 1;
                notVisited.push_back(vertexes[notVisited[j]].adj[i]);
            } else if (ans[vertexes[notVisited[j]].adj[i]] == 1) {
                ans[vertexes[notVisited[j]].adj[i]] = 2;
                notVisited.push_back(vertexes[notVisited[j]].adj[i]);
            }
        }
        j++;
    }
}

void cyclicBfs(vector<int>& ans,vector<int>& cyclicVertexes,vector<vertex>& vertexes,int source){
    vector<int> notVisited={source};
    ans[source]=-1;
    int j=0;
    while(j<notVisited.size()){
        for (int i = 0; i < vertexes[notVisited[j]].adj.size(); i++) {
            if(ans[vertexes[notVisited[j]].adj[i]] != -1) {
                ans[vertexes[notVisited[j]].adj[i]] = -1;
                notVisited.push_back(vertexes[notVisited[j]].adj[i]);
            }
        }
        j++;
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vertex> vertexes={};
    vector<int> cyclicVertexes={};
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        vertex v=vertex(i);
        vertexes.push_back(v);
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u-=1;
        v-=1;
        vertexes[u].addEdge(v);
    }
    dfs(cyclicVertexes,vertexes,0);
    bfs(ans,cyclicVertexes,vertexes,0);
    for(int i=0;i<cyclicVertexes.size();i++){
        cyclicBfs(ans,cyclicVertexes,vertexes,cyclicVertexes[i]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
