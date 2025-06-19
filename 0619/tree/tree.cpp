//%^~
// #pragma GCC optimize(3)
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
#define MAXN 100005
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
int n;
vector<int> e[MAXN];

class QR{
public:
	int l,r;
}qr[500005];
int q;

int dfn[MAXN];
int fa[MAXN];
int sz[MAXN];
int dep[MAXN];
int st[19][MAXN];
int DFN;
void pre(int u,int fath){
	fa[u]=fath;
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	dfn[u]=++DFN;
	st[0][dfn[u]]=fa[u];
	for(auto v:e[u]){
		if(v==fa[u])	continue;
		pre(v,u);
	}
}
int gdep(int x,int y){
	return dep[x]<dep[y]?x:y;
}
int LCA(int u,int v){
	if(u==v)	return u;
	if((u=dfn[u])>(v=dfn[v]))	swap(u,v);
	int k=__lg(v-u++);
	return gdep(st[k][u],st[k][v-(1<<k)+1]);
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}

namespace SUB1{
	LL f[7005][7005];
	class Node{
	public:
		int x;
		bool operator < (const Node& o)const{
			return dfn[x]<dfn[o.x];
		}
	};
	set<Node> st;
	void work(){
		
		foru(l,1,n){
			st.clear();
			int s=0;
			foru(r,l,n){
				auto it=st.insert(Node{r}).fi;

				int lf=it==st.begin()?st.rbegin()->x:prev(it)->x;
				int rf=next(it)==st.end()?st.begin()->x:next(it)->x;

				s-=dis(lf,rf);
				s+=dis(lf,r)+dis(r,rf);
				
				f[l][r]=s/2+1;
			}
		}

		foru(i,1,n){
			foru(j,1,n){
				f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
			}
		}

		foru(o,1,q){
			// cerr<<o<<endl;
			auto [l,r]=qr[o];

			LL ans=0;

			ans=f[r][r]-f[l-1][r]-f[r][l-1]+f[l-1][l-1];
			// foru(i,l,r){
			// 	foru(j,i,r){
			// 		ans+=f[i][j];
			// 	}
			// }

			cout<<ans<<'\n';
		}
	}
}

void solve(bool SPE){ 
	n=RIN;
	foru(i,1,n-1){
		int u=RIN,v=RIN;
		e[u]+=v;
		e[v]+=u;
	}
	q=RIN;
	foru(i,1,q){
		qr[i]={RIN,RIN};
	}

	pre(1,0);
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[i][j]=gdep(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}

	if(n<=7000 && q<=7000){
		SUB1::work();
		return ;
	}

	// auto f=[](int l,int r)->int {
	// 	vector<int> ls;
	// 	foru(i,l,r)	ls+=i;
	// 	sort(All(ls),[](int u,int v)->bool {
	// 		return dfn[u]<dfn[v];
	// 	});
	// 	int ret=0;
	// 	int N=ls.size();
	// 	for(int i=0;i<N;i++){
	// 		ret+=dis(ls[i],ls[(i+1)%N]);
	// 	}
	// 	return ret/2+1;
	// };

	// static int F[505][505];
	// foru(l,1,n){
	// 	foru(r,l,n){
	// 		F[l][r]=f(l,r);
	// 	}
	// }
	// int cnt=0;
	// ford(r,n,1){
	// 	foru(l,1,r){
	// 		// int x=F[l][r];
	// 		// if((l+1<=r && F[l+1][r]==F[l][r]) || (l<=r-1 && F[l][r-1]==F[l][r]))	x=0;
	// 		int x=F[l][r]-F[l+1][r]-F[l][r-1]+F[l+1][r-1];
	// 		cnt+=x>0;
	// 		cout<<x<<"	";
	// 	}
	// 	cout<<endl;
	// }
	// cerr<<cnt<<' '<<n*(1+n)/2<<' '<<n*__lg(n);
	// exit(0);

	// foru(o,1,q){
	// 	cerr<<o<<endl;
	// 	auto [l,r]=qr[o];

	// 	LL ans=0;

	// 	cout<<ans<<'\n';
	// }


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
	#ifndef ONLINE_JUDGE
	// if(freopen("tree1.in","r",stdin));
	if(freopen("tree.in","r",stdin));
	if(freopen("tree.out","w",stdout));
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