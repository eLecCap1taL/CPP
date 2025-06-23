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
#define MAXN 55
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

// constexpr int mod=998244353;
constexpr int mod=1e9+7;

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

constexpr int _100 = qpow(100,mod-2);

int n,m;

int a[MAXN];

namespace SUB1{
	int f[6][1<<10][25];

	pair<int,int> e[100];
	int eg=0;

	int fa[6];
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void Union(int u,int v){
		u=find(u);
		v=find(v);
		if(u!=v){
			fa[u]=v;
		}
	}
	void init(int s){
		foru(i,1,n){
			fa[i]=i;
		}
		foru(i,0,eg-1){
			if((s>>i)&1){
				Union(e[i+1].fi,e[i+1].se);
			}
		}
	}

	void work(){
		memset(f,0,sizeof f);
	
		f[0][0][0]=1;

		eg=0;
		foru(u,1,n){
			foru(v,u+1,n){
				e[++eg]={u,v};
			}
		}

		int ans[200];

		foru(i,0,m-1){
			for(int s=0;s<(1<<eg);s++){
				for(int j=0;j<=(n-1)*m;j++){
					if(f[i][s][j]==0)	continue;
					int T=((1<<eg)-1)^s;
					for(int t=T;t;t=(t-1)&T){
						int nj=j;

						init(s);

						for(int k=0;k<eg;k++){
							if((t>>k)&1){
								int u=find(e[k+1].fi);
								int v=find(e[k+1].se);
								if(u!=v){
									Union(u,v);
									nj+=i+1;
								}
							}
						}

						// if(i==0 && s==0 && j==0 && t==T){
						// 	cout<<i+1<<' '<<(s|t)<<' '<<nj<<' '<<f[i][s][j]<<' '<<a[i+1]<<' '<<__builtin_popcount(t)<<endl;
						// }

						mdd(f[i+1][s|t][nj],mul(f[i][s][j],qpow(a[i+1],__builtin_popcount(t))));
					}

					mdd(f[i+1][s][j],f[i][s][j]);
				}
			}
		}
		
		// cout<<f[1][(1<<eg)-1][n-1]<<endl;
	

		memset(ans,0,sizeof ans);

		for(int s=0;s<(1<<eg);s++){
			for(int j=0;j<=(n-1)*m;j++){
				init(s);
				bool ok=1;
				for(int i=2;i<=n;i++){
					if(find(i)!=find(1)){
						ok=0;
						break;
					}
				}
				if(!ok)	continue;
				mdd(ans[j],mul(f[m][s][j],qpow(a[0],eg-__builtin_popcount(s))));
			}
		}

		foru(i,(n-1),m*(n-1)){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
}

namespace SUBM1{
	int f[55][55];
	int C[55][55];
	int P[2][55];
	void work(){
		C[0][0]=1;
		foru(i,1,n){
			C[i][0]=1;
			foru(j,1,i){
				C[i][j]=add(C[i-1][j],C[i-1][j-1]);
			}
		}

		foru(i,0,n){
			foru(j,0,1){
				P[j][i]=qpow(a[j],i);
			}
		}

		f[1][0]=1;
		foru(i,1,n-1){
			foru(j,0,i-1){
				if(f[i][j]==0)	continue;
				foru(k,0,j){
					mdd(f[i+1][j+1],mul(f[i][j],C[j][k],P[1][k],P[0][j-k]));
					mmv(f[i+1][j+1],mul(f[i][j],C[j][k],P[1][k],P[0][j-k]));
				}
				foru(k,0,i-j){
					mdd(f[i+1][j],mul(f[i][j],C[i-j][k],P[1][k],P[0][i-j-k]));
				}
			}
		}
		cout<<f[n][0]<<endl;
	}
}

void solve(bool SPE){ 
	n=RIN,m=RIN;
	foru(i,0,m){
		a[i]=RIN;
		mll(a[i],_100);
	}

	if(n==1){
		cout<<1<<'\n';
		return ;
	}

	// if(m<=1){
	// 	SUBM1::work();
	// 	return ;
	// }

	if(n<=5 && m<=5){
		SUB1::work();
		return ;
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
	#define MULTITEST
	
	#ifndef CPEDITOR
	#ifndef ONLINE_JUDGE
	if(freopen("plant0.in","r",stdin));
	// if(freopen("plant.in","r",stdin));
	// if(freopen("plant.out","w",stdout));
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