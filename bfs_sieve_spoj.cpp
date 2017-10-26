//Solution to problem SPOJ problem Prime Path http://www.spoj.com/problems/PPATH/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007
#define N 10001

using namespace std;
vector<list<int> > graph(N);

int bfs(int s, int e, vector<bool> is_prime) {
    
    vector<bool> vis(N,false);
    vector<int> dis(N,INFINITY);
    vector<int> parent(N,-1);
    
    std::queue<int> que;
    que.push(s);
    dis[s]=0;
    vis[s]=1;
    while(!que.empty()) {
        int curr=que.front();
        que.pop();
        for(auto iter=graph[curr].begin(); iter!=graph[curr].end(); ++iter) {
            if(!vis[*iter]) {
                    dis[*iter]=dis[curr]+1;
                    que.push(*iter);
                    vis[*iter]=1;
                    parent[*iter]=curr;
                }
        }
    }

    
    return dis[e];
    
    
}

int main() {
    
    vector<bool> is_prime(N,true);
    
    is_prime[1]=true;
    is_prime[2]=true;
    
    for(int i=2; i<sqrt(N); i++) {
        if(is_prime[i]) {
            for(int j=i+i; j<N; j+=i){
                is_prime[j]=false;
            }
        }
    }
    
    
    for(int i=1000; i<10000; i++) {
        if(is_prime[i]) {
        for(int j=0; j<10; j++) {
            int num1 = (i%1000) + j*1000;
            int num2 = (i/1000)*1000 + j*100 + i%100;
            int num3 = (i/100)*100 + j*10 + i%10;
            int num4 = (i/10)*10 + j;
            
            if(num1 != i && is_prime[num1] && num1>999){
                graph[i].push_back(num1);
            }
            if(num2 != i && is_prime[num2] && num2>999) {
                graph[i].push_back(num2);
            }
            if(num3 != i && is_prime[num3] && num3>999) {
                graph[i].push_back(num3);
            }
            if(num4 !=i && is_prime[num4] && num4>999) {
                graph[i].push_back(num4);
            }
        }
        }
    }
    
    int lim;
    cin >> lim;
    
    fore(i,0,lim){
        int a,b;
        cin >> a >> b;
        int ans = bfs(a,b,is_prime);
        if(ans!=INFINITY)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }
    
    
    return 0;


}
