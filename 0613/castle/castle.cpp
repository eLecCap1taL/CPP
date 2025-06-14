//%^~
#pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <limits>
#include <climits>
#include <bitset>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/pb_ds/priority_queue.hpp"
// #include <ext/rope>
// #define PBDS __gnu_pbds
// #include <bits/extc++.h>
#define MAXN 200005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define uLL unsigned long long
#define LL long long
#define LXF int
#define RIN Cap1taLDebug::read()
#define RSIN Cap1taLDebug::rdstr()
#define RCIN Cap1taLDebug::rdchar()
#define HH printf("\n")
#define All(x) (x).begin(), (x).end()
#define fi first
#define se second
#define CA const auto&
#if defined(__clang__)
#define assume(expr) __builtin_assume(expr)
#elif defined(__GNUC__)
#define assume(expr) if (expr) {} else { __builtin_unreachable(); }
#elif defined(_MSC_VER)
#define assume(expr) __assume(expr)
#endif
#define likely(x) __builtin_expect(!!(x), 1) 
#define unlikely(x) __builtin_expect(!!(x), 0)
#define mkp(x,y) make_pair(x,y)
#define ast(x) if(!(x))	{cerr<<endl<<"err at"<<__LINE__<<endl;exit(1);}
#define sz(x) ((int)(x.size()))
using namespace std;

typedef __int128 i128;
typedef unsigned __int128 u128;
typedef long long i64;
typedef unsigned long long u64;
typedef int i32;
typedef unsigned u32;
typedef short i16;
typedef unsigned short u16;

class Cap1taLDebug{
public:
	#define DEBUGING

	ostream& buf;
	#ifndef DEBUGING
	static char fbuf[1<<21],*p1,*p2;
	#define getchar() (Cap1taLDebug::p1==p2&&(p1=(p2=fbuf)+fread(fbuf,1,1<<21,stdin),p1==p2)?EOF:*p2++)
	#endif
	Cap1taLDebug(ostream& out=cout):buf(out){}
	~Cap1taLDebug(){
		#ifdef DEBUGING
		buf.flush();
		#endif
	}
	static LXF read(){
		LXF x=0,w=1;char ch=0;
		while(!isdigit(ch)){
		if(ch=='-')	w=-1;
		ch=getchar();
		}
		while(isdigit(ch))	x=x*10+(ch^48),ch=getchar();
		return x*w;
	}
	static string rdstr(){
		string s;char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();	
		while(c!=' ' && c!='\r' && c!='\n' && c!=EOF)	s+=c,c=getchar();
		return s;
	}
	static char rdchar(){
		char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();
		return c;
	}
	static string i128ToString(i128 x){
		if(x==0)	return "0";
		string s="",w="";
		if(x<0)	w="-",x*=-1;
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	static string u128ToString(u128 x){
		if(x==0)	return "0";
		string s="",w="";
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	Cap1taLDebug& operator<<(const string val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	template<typename T1,typename T2>
	Cap1taLDebug& operator<<(const pair<T1,T2>& val){
		#ifdef DEBUGING
		(*this)<<"("<<val.first<<","<<val.second<<")";
		#endif
		return *this;
	}
	template<typename T,template<typename,typename...>class Container,typename...Args>
	Cap1taLDebug& operator<<(const Container<T, Args...>& container){
		#ifdef DEBUGING
		buf<<"{";
		bool fst=0;
		for(const auto& val:container){
			if(!fst)	fst=true;
			else	buf<<",";
			(*this)<<val;	
		}
		buf<<"}";
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const i128& val){
		#ifdef DEBUGING
		buf<<i128ToString(val);
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const u128& val){
		#ifdef DEBUGING
		buf<<u128ToString(val);
		#endif
		return *this;
	}
	template<typename T>
	Cap1taLDebug& operator<<(const T& val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(ostream& (*manip)(ostream&)){
		#ifdef DEBUGING
		buf<<manip;
		#endif
		return *this;
	}
};
#ifndef DEBUGING
char Cap1taLDebug::fbuf[1<<21],*Cap1taLDebug::p1=nullptr,*Cap1taLDebug::p2=nullptr;
#endif
Cap1taLDebug cein(cout);
// Cap1taLDebug cein(cerr);
ostream& operator<<(ostream& os,i128 val){
	os<<Cap1taLDebug::i128ToString(val);
	return os;
}
ostream& operator<<(ostream& os,u128 val){
	os<<Cap1taLDebug::u128ToString(val);
	return os;
}

#define OPERATOR_FOR_PUSHBACK(pb)\
template<typename T1,typename T2>\
pb<T1>& operator += (pb<T1>& x,const T2& y){x.push_back((T1)y);return x;}

#define OPERATOR_FOR_PUSH(p)\
template<typename T1,typename T2>\
p<T1>& operator += (p<T1>& x,const T2& y){x.push((T1)y);return x;}

#define OPERATOR_FOR_INSERT(i)\
template<typename T1,typename T2>\
i<T1>& operator += (i<T1>& x,const T2& y){x.insert((T1)y);return x;}

OPERATOR_FOR_PUSHBACK(vector)
OPERATOR_FOR_PUSHBACK(deque)
OPERATOR_FOR_PUSH(stack)
OPERATOR_FOR_PUSH(queue)
OPERATOR_FOR_PUSH(priority_queue)
OPERATOR_FOR_INSERT(set)
OPERATOR_FOR_INSERT(unordered_set)
OPERATOR_FOR_INSERT(multiset)
OPERATOR_FOR_INSERT(unordered_multiset)

template<typename T1,typename T2>
inline bool chkmax(T1& x,const T2& y){return x<(T1)y?x=(T1)y,true:false;}
template<typename T1,typename T2>
inline bool chkmin(T1& x,const T2& y){return (T1)y<x?x=(T1)y,true:false;}

class TIMECHKER{
public:
	~TIMECHKER(){
		cerr<<endl<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	}
}TIMECHECKER;

constexpr int mod=998244353;
// constexpr int mod=1e9+7;

constexpr int& mdd(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mdd(int& x,const T1& y,const T2& ...xr){
	x+=y;
	if(x>=mod)	x-=mod;
	return mdd(x,xr...);
}
constexpr int& mmv(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mmv(int& x,const T1& y,const T2& ...xr){
	x-=y;
	if(x<0)	x+=mod;
	return mmv(x,xr...);
}
constexpr int& mll(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mll(int& x,const T1& y,const T2& ...xr){
	x=(LL)x*y%mod;
	return mll(x,xr...);
}
constexpr int add(const int& x){return x;}
template<class ...T>
constexpr int add(const int& x,const T& ...xr){
	int ret=x+add(xr...);
	if(ret>=mod)	ret-=mod;
	return ret;
}
constexpr int mul(const int& x){return x;}
template<class ...T>
constexpr int mul(const int& x,const T& ...xr){
	return (LL)x*mul(xr...)%mod;
}
constexpr int rmv(int x,int y){
	x-=y;
	if(x<0)	x+=mod;
	return x;
}
constexpr int mev(const int& x){return mod-x;}

constexpr int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)	mll(ret,x);
		mll(x,x),y>>=1;
	}
	return ret;
}

/*

*/

template<int N,int M,class D,D INF>
class ISAP{
	struct edge{
		int v;
		int nxt;
		D w;
	}e[M*2+5];
	int ecnt=1;
	int head[N+5],cur[N+5],dep[N+5],gap[N+5];
	int n,s,t;

	void add_e(int u,int v,D w){
		e[++ecnt]={v,head[u],w};
		head[u]=ecnt;
	}

	bool bfs(){
		static queue<int> q;
		foru(i,0,n)	dep[i]=INF;
		memcpy(cur,head,sizeof head);
		dep[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dep[u]+1>=dep[v] || e[i].w==0)	continue;
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
		return (dep[t]!=INF);
	}
	D dfs(int u,D flow){
		if(u==t)	return flow;
		D used=0;
		for(int &i=cur[u];i;i=e[i].nxt){
			// cur[u]=i;
			int v=e[i].v;
			if(e[i].w==0 || dep[u]!=dep[v]-1)	continue;
			D x=dfs(v,min(flow-used,e[i].w));

			if(x>0){
				e[i].w-=x;
				e[i^1].w+=x;
				used+=x;
				if(used==flow)	return used;
			}
		}
		return used;
	}
public:
	void clear(){
		foru(i,1,n)	head[i]=dep[i]=gap[i]=0;
		n=s=t=0;
		ecnt=1;
	}
	void set(int _n,int _s,int _t){
		n=_n,s=_s,t=_t;
	}
	int add_edge(int u,int v,D w){
		add_e(u,v,w);
		add_e(v,u,0);
		return ecnt-1;
	}
	int S(){return s;}
	int T(){return t;}
	D qry_w(int id)const{
		return e[id].w;
	}
	D maxflow(){
		D flow=0;
		while(bfs()){
			flow+=dfs(s,INF);
			// cerr<<flow<<endl;
		}
		return flow;
	}
};

int n,m;

string s[1005];

int N,M;
pair<int,int> lf[405*405];
pair<int,int> rf[405*405];
vector<int> el[405*405];
vector<int> el_id[405*405];
vector<int> er[405*405];

const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,1,-1};

int id[405][405];

ISAP<405*405,405*405*3,int,INT_MAX> g;

void solve(bool SPE){
	
	// g.set(3,1,3);
	// g.add_edge(1,2,1);
	// g.add_edge(2,3,2);

	// cerr<<g.maxflow();
	
	// exit(0);
	n=RIN,m=RIN;

	// if(n>20)	return ;
	if(n==1 && m==1){
		cout<<"Yes\n###\n#.#\n###";
		return ;
	}

	foru(i,1,2*n+1){
		s[i]=" "+RSIN;
	}

	foru(i,1,n){
		foru(j,1,m){
			if(s[2*i][2*j]=='#'){
				continue;
			}
			if((i+j)&1){
				N++;
				lf[N]={i,j};
				id[i][j]=N;
			}else{
				M++;
				rf[M]={i,j};
				id[i][j]=M;
			}
		}
	}
	foru(i,1,n){
		foru(j,1,m){
			if(s[2*i][2*j]=='#'){
				continue;
			}
			auto& e=((i+j)&1)?el[id[i][j]]:er[id[i][j]];
			for(int k=0;k<4;k++){
				int u=i+dx[k],v=j+dy[k];
				if(id[u][v]==0)	continue;
				if(s[i*2+dx[k]][2*j+dy[k]]=='#')	continue;
				e+=id[u][v];
			}
		}
	}

	cerr<<N<<' '<<M<<endl;
	cerr<<N+M<<endl;
	cerr<<n*m<<endl;

	// foru(i,1,M){
	// 	cein<<rf[i]<<endl;
	// }
	if(N>M){
		foru(i,1,N){
			swap(el[i],er[i]);
			swap(lf[i],rf[i]);
		}
		swap(N,M);
		// exit(1);
	}

	if(N==M){
		cout<<"No";
		return ;
	}

	g.set(N+M+2,N+M+1,N+M+2);

	// cerr<<N<<' '<<M<<endl;
	
	int ct=0;
	// map<int,int> mp;
	foru(u,1,N){
		el_id[u].resize(el[u].size(),0);
		// cerr<<el[u].size()<<endl;
		// mp[sz(el[u])]++;
		for(int i=0;i<sz(el[u]);i++){
			int v=el[u][i];
			el_id[u][i]=g.add_edge(u,N+v,1);
			ct++;
		}
	}
	// for(auto [X,Y]:mp){
	// 	cerr<<X<<'~'<<Y<<endl;
	// }
	foru(u,1,N)	g.add_edge(g.S(),u,1),ct++;
	foru(u,1,M)	g.add_edge(u+N,g.T(),1),ct++;
	// cerr<<ct<<endl;

	// exit(0);
	LL mxflow=g.maxflow();
	// cerr<<mxflow<<endl;
	// exit(0);
	// cerr<<mxflow<<endl;
	if(mxflow!=N){
		cout<<"No";
		return ;
	}
	// cerr<<"OK";

	// cerr<<mxflow<<endl;
	static int match[405*405];
	static int matched[405*405];

	foru(u,1,N){
		for(int i=0;i<sz(el[u]);i++){
			int v=el[u][i];
			// cerr<<el_id[u][i]<<endl;
			// cerr<<' '<<g.qry_w(el_id[u][i])<<endl;
			if(g.qry_w(el_id[u][i])==0){
				match[u]=v;
				matched[v]=u;
				// cerr<<u<<' '<<v<<endl;
				break;
			}
		}
	}
	// vector<int> chk;
	// foru(u,1,N){
	// 	chk+=match[u];
	// }
	// sort(All(chk));
	// for(int i=1;i<sz(chk);i++){
	// 	assert(chk[i]!=chk[i-1]);
	// }

	static string os[1005];
	foru(i,1,2*n+1){
		os[i]=" ";
		foru(j,1,2*m+1)	os[i]+='#';
	}
	
	
	static int fa[405*405*2];
	foru(i,1,N+M){
		fa[i]=i;
	}
	auto find=[](auto& find,int x)->int {
		return fa[x]==x?x:fa[x]=find(find,fa[x]);
	};
	auto Union=[&find](int x,int y,int sta=3)->void {
		x=find(find,x),y=find(find,y);
		// assert(x!=y);
		if(x==y)	exit(sta);
		fa[x]=y;
	};

	auto con=[](pair<int,int> x,pair<int,int> y)->void {
		// cein<<x<<' '<<y<<endl;
		if(x>y)	swap(x,y);
		os[2*x.fi][2*x.se]='.';
		os[2*y.fi][2*y.se]='.';
		if(x.fi==y.fi){
			// assert(y.se-x.se==1);
			os[2*x.fi][2*x.se+1]='.';
		}else if(x.se==y.se){
			// assert(y.fi-x.fi==1);
			os[2*x.fi+1][2*x.se]='.';
		}else{
			// assert(0);
		}
	};

	// cerr<<M<<endl;
	static bitset<405*405> vis;

	static queue<int> q;
	foru(i,1,M){
		// cein<<rf[i]<<endl;
		if(matched[i])	continue;
		q.push(i);
	}

	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:er[u]){
			if(vis[v])	continue;
			if(v==matched[u])	continue;
			vis[v]=1;
			// if(u==match[v])	exit(11);
			// if(find(find,N+u)==find(find,N+match[v]))	exit(12);
			Union(v,N+match[v],1);
			Union(v,N+u,2);
			con(lf[v],rf[u]);
			con(lf[v],rf[match[v]]);
			q.push(match[v]);
		}
	}

	int num=0;
	foru(i,1,N)	num+=vis[i];
	if(num!=N){
		cout<<"No";
		return ;
	}

	foru(v,1,M){
		for(auto u:er[v]){
			if(find(find,u)==find(find,N+v))	continue;
			con(lf[u],rf[v]);
			Union(u,N+v);
		}
	}

	// int rt=find(find,1);
	// foru(i,2,N){
	// 	if(!(rt==find(find,i)))	exit(21);
	// }
	// foru(i,1,M){
	// 	if(!(rt==find(find,N+i)))	exit(22);
	// }

	// int tot=0;
	// foru(i,1,n){
	// 	foru(j,1,m){
	// 		if(s[i*2][j*2]=='.')	tot++;
	// 	}
	// }
	// if(tot!=N+M)	exit(23);
	
	foru(i,1,n){
		foru(j,1,m){
			if(os[i*2][j*2]=='#' && s[i*2][j*2]=='.'){
				os[i*2][j*2]='.';
				// cout<<"No\n";
				// exit(0);
				// assert(i==1 && j==1);
				// exit((s[2][3]=='#')+(s[3][2]=='#'));
			}
		}
	}

	cout<<"Yes\n";
	foru(i,1,2*n+1){
		foru(j,1,2*m+1){
			putchar(os[i][j]);
		}
		putchar('\n');
	}

	return ;
}
/*
检查文件读写
检查多测清空
检查数组大小
*/
signed main()
{
	// #define MULTITEST
	
	#ifndef CPEDITOR
	if(freopen("castle4.in","r",stdin));
	if(freopen("castle.out","w",stdout));
	#ifdef ONLINE_JUDGE
	if(freopen("castle.in","r",stdin));
	if(freopen("castle.out","w",stdout));
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif
	
	for(int i=1;i<=T;i++){
		solve(i==0);
	}
	return 0;
}