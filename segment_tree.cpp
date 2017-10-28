//segment tree range query point update for sums
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
#include <string.h>
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
#define pv(a) for(int i=0; i<a.size(); i++) { cout << a[i] <<" "; } cout << endl;
#define rall(a) a.rbegin(),a.rend()
#define mp make_pair
#define ff first
#define md 1000000007
#define ss second
#define sc(a) scanf("%d",&a)
#define bl 1
#define wh 0

int getmid(int s, int e) {
    return s + (e -s)/2;
}

int binop(int a,int b)
{
    //defined it as sum here
    return a+b;
}

int getop(int *st, int node, int cs, int ce, int l, int r) {
    // st is the tree
    // cs is the current start
    // ce is the current end
    // l is start of range
    // r is end of range
    if(l<=cs && r>=ce)
        return st[node];
    if(cs>r || ce<l)
        return 0;
    int mid = getmid(cs, ce);
    return binop(getop(st, node*2+1, cs, mid, l, r),getop(st, node*2+2,mid+1,ce,l,r));
}

int getoputil(int *st, int n, int l, int r)
{
    return getop(st,0,0,n-1,l,r);
}

int consttree(int arr[],int l, int r, int *st, int node)
{
    if(l==r)
    {
        st[node]=arr[l];
        return arr[l];
    }
    int mid = getmid(l,r);
    st[node] = binop(consttree(arr, l, mid, st, node*2+1),consttree(arr,mid+1,r,st,node*2+2));
    return st[node];
}

int *constutil(int arr[],int n) {
    int i = 1;
    for(;i<n;i<<=1)
    {}
    i<<=1;
    int *st = new int[i-1];
    consttree(arr,0,n-1,st,0);
    return st;
}

void updateutil(int *st,int cs,int ce,int i,int diff, int node)
{
    //cs is current start
    //ce is current end
    //i is elem that has been altered
    //diff is difference b/w vals
    //node is current node
    if(i < cs || i > ce)
    {
        return;
    }
    st[node] +=diff;
    if(cs!=ce)
    {
    int mid = getmid(cs,ce);
    updateutil(st, cs, mid, i, diff, node*2+1);
    updateutil(st,mid+1, ce, i, diff, node*2+2);
    }
    
}

void update(int arr[],int *st,int n,int i,int newval)
{
    if(i<0 || i>n)
        return;
    int diff = newval - arr[i];
    arr[i]=newval;
    updateutil(st,0,n-1,i,diff,0);
}


int main() {
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    
    int n = 10;
    
    int *tree = constutil(arr, n);
    
    //l and r are 0 indexed and l and r are inclusive
    
    printf("sum of %d to %d is %d",3,6,getoputil(tree, n, 3, 6));
    
    //pos to be updated is zero indexed as well
    
    update(arr,tree,n,0,10);
    
    printf("sum of %d to %d is %d",0,0,getoputil(tree, n, 0, 0));
    
    
    
    return 0;
}
