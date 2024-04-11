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
    ll number;
    bool visited= false;
    ll distance=1e15;
    vector<pair<ll,ll>> adj={};
    vertex(ll vnumber){
        this->number=vnumber;
    }
    void addEdge(ll vnumber,ll weight){
        this->adj.push_back(make_pair(vnumber,weight));
    }
    bool operator<(const vertex& other) const {
        return number < other.number;
    }
    bool operator>(const vertex& other) const {
        return number > other.number;
    }
    bool operator==(const vertex& other) const {
        return number == other.number;
    }
};

void dijkstra1(vector<vertex>& vertexes,const vertex& source){
    priority_queue<pair<ll,vertex> , vector<pair<ll,vertex>> , greater<>> pq;
    vertexes[source.number].distance=0;
    pq.push(make_pair(0,vertexes[source.number]));
    while(!pq.empty()){
        ll dist=pq.top().first;
        vertex v=pq.top().second;
        pq.pop();
        for(ll i=0;i<v.adj.size();i++){
            if(dist+v.adj[i].second < vertexes[v.adj[i].first].distance){
                vertexes[v.adj[i].first].distance=dist+v.adj[i].second;
                pq.push(make_pair(vertexes[v.adj[i].first].distance,vertexes[v.adj[i].first]));
            }
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vertex> vertexes1={};
    vector<vertex> vertexes2={};
    for(ll i=0;i<n;i++){
        vertex v=vertex(i);
        vertexes1.push_back(v);
    }
    for(ll i=0;i<n;i++){
        vertex v=vertex(i);
        vertexes2.push_back(v);
    }

    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u-=1;
        v-=1;
        vertexes1[u].addEdge(v,w);
        vertexes2[v].addEdge(u,w);
    }

    vector<ll> ans={};
//    for(ll i=0;i<1;i++){
    dijkstra1(vertexes1,vertexes1[0]);
    for(ll j=0;j<n;j++){
        ans.push_back(vertexes1[j].distance);
    }
//    }

    for(ll i=1;i<n;i++){
        vertexes2[0].addEdge(i,ans[i]);
    }

    vector<ll> ans1={};
//    for(ll i=0;i<1;i++){
    dijkstra1(vertexes2,vertexes2[0]);
    for(ll j=0;j<vertexes2.size();j++){
        ans1.push_back(vertexes2[j].distance);
    }
//    }

    for(ll i=1;i<n;i++){
        if(ans1[i]!=1e15) {
            cout <<min(ans1[i],ans[i])<<' ';
        }
        else{
            cout<<-1<<' ';
        }
    }
    cout<<endl;
}

int main() {
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
