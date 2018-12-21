#include<iostream>
#include<vector>
#define LL long long
using namespace std;
 
const int N = 5000000;
const int M = 10000;
 
int n,m,tot,ans,vis[N],id[N],in[M],num[M];
int head[M],nxt[N],to[N],f[M],itr[M];
vector<int> que[M],vout;
 
inline int read() {
    char c=getchar(); int f=1,ret=0;
    while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
    return ret * f;
}
 
int gcd(int a, int b) {
    return b? gcd(b, a%b): a;
}
 
inline void AddEdge(int u, int v) {
    static int E = 1; in[u]++; 
    to[++E] = u; nxt[E] = head[v]; head[v] = E;
}
 
void solve(int w) { 
    f[w] = que[w].size() + (itr[w]?f[itr[w]]:0);
    ans = max(ans, f[w]); 
    for (int i=head[w];i;i=nxt[i]) {
        if (f[w] > f[itr[to[i]]]) itr[to[i]] = w;
        if (--in[to[i]] == 0) solve(to[i]);
    }
}
 
void exgcd(int a, int b, LL &x, LL &y) {
    if (b) {exgcd(b, a%b, y, x); y -= a / b * x;}
    else {x = 1; y = 0;}
}
 
inline int REV(int a, int z) {
    int tmp = gcd(a, m), b; LL x, y; 
    a /= tmp; z /= tmp; b = m / tmp;
    exgcd(a, b, x, y);
    return x * z % m;
}
 
void print(int w, int v) {
    for (int i=0;i<=que[w].size()-1;i++) {
        int nv = que[w][i], rev = REV(v, nv);
        vout.push_back((rev+m)%m); v = nv;
    }
    if (itr[w]) print(itr[w], v);
}
 
int main() {
    n = read(); m = read();
    for (int i=1;i<=n;i++) vis[read()] = 1;
    for (int i=1;i<m;i++) if (!vis[i]) {
        int tmp = gcd(m, i); 
        if (!id[tmp]) id[tmp] = ++tot, num[tot] = tmp;
        que[id[tmp]].push_back(i);
    }
    for (int i=1;i<=tot;i++) {
        for (int j=1;j<=tot;j++) {
            if (num[j] > num[i] && num[j] % num[i] == 0) {
                AddEdge(i, j); 
            }
        }
    }
    for (int i=1;i<=tot;i++) if (!in[i]) solve(i);
    for (int i=1;i<=tot;i++) if (f[i] == ans) {print(i, 1); break;}
    if (!vis[0]) vout.push_back(0); cout<<vout.size()<<endl;
    for (int i=0;i<=vout.size()-1;i++) printf("%d ",vout[i]); 
    return 0;
}



