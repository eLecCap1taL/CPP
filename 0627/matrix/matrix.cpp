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

class Matrix{
public:
	int a[2][2];
	Matrix(int x=0,int y=0,int z=0,int w=0){
		a[0][0]=x;
		a[0][1]=y;
		a[1][0]=z;
		a[1][1]=w;
	}
	int* operator [] (const int& x){
		return a[x];
	}
	const int* operator [] (const int& x)const{
		return a[x];
	}
	Matrix operator * (const Matrix& x)const{
		return Matrix(
			add(mul(a[0][0],x[0][0]),mul(a[0][1],x[1][0])),
			add(mul(a[0][0],x[0][1]),mul(a[0][1],x[1][1])),
			add(mul(a[1][0],x[0][0]),mul(a[0][1],x[1][0])),
			add(mul(a[1][0],x[0][1]),mul(a[0][1],x[1][1]))
		);
	}
};
ostream& operator << (ostream& os,const Matrix& x){
	os<<'['<<x[0][0]<<','<<x[0][1]<<','<<x[1][0]<<','<<x[1][1]<<']';
	return os;
}

Matrix a[505];

int n;

int fac[2005];
int ifac[2005];
int C(int n,int m){
	return mul(fac[n],ifac[m],ifac[n-m]);
}

namespace SUBN8{
	int p[10];
	void work(){
		foru(i,1,n){
			p[i]=i;
		}
		int ans=0;
		do{
			// cout<<"~~~~~~~~~~"<<endl;
			Matrix res(1,0,0,1);
			foru(i,1,n){
				res=res*a[p[i]];
				// cout<<a[p[i]]<<' ';
			}
			// cout<<res;
			// exit(0);
			// cout<<endl;
			mdd(ans,res[0][0]);
		}while(next_permutation(p+1,p+1+n));
		cout<<ans;
	}
}


int divide(int n,int m){
	//divide n element into m set
	//empty is allowed
	// if(n==0 && m==0)	return 1;
	return C(n+m-1,m-1);
}

namespace SUBN18{
	int _2=qpow(2,mod-2);
	int f[2][505][1005][2];
	void work(){
		f[0][0][n][0]=1;
		foru(i,0,n-1){
			bool t=(i+1)&1;
			foru(xy,0,i+1){
				foru(z,n-i-1,n+i+1){
					f[t][xy][z][0]=0;
					f[t][xy][z][1]=0;
				}
			}
			foru(xy,0,i){
				foru(z,n-i,n+i){
					int v=0;
					
					v=f[t^1][xy][z][0];
					mdd(f[t][xy+1][z][0],mul(v,a[i+1][0][0]));
					mdd(f[t][xy+1][z+1][0],mul(v,a[i+1][0][1]));
					mdd(f[t][xy+1][z+1][1],mul(v,a[i+1][0][1]));
					mdd(f[t][xy][z-1][0],mul(v,a[i+1][1][0]));
					mdd(f[t][xy][z][0],mul(v,a[i+1][1][1]));
					
					v=f[t^1][xy][z][1];
					mdd(f[t][xy+1][z][1],mul(v,a[i+1][0][0]));
					mdd(f[t][xy+1][z+1][1],mul(v,a[i+1][0][1]));
					mdd(f[t][xy][z-1][1],mul(v,a[i+1][1][0]));
					mdd(f[t][xy][z][1],mul(v,a[i+1][1][1]));
				}
			}
		}

		/*
		
		*/
		int ans=0;
		foru(xy,0,n-1){
			// if(x+y*2>n)	break;

			// cerr<<x<<' '<<y<<' '<<z<<' '<<mul(divide(z,y),divide(y,(x-1)+1))<<' '<<g[n&1][x][y][0]<<endl;
			// if(mul(divide(z,y),divide(y,(x-1)+1))!=g[n&1][x][y][0]){
			// 	cerr<<divide(z,y)<<' '<<divide(y,x)<<endl;
			// 	exit(1);
			// }
			// cerr<<y<<' '<<z<<endl;
			// cout<<x<<' '<<y<<' '<<z<<' '<<g[n][x][y][z][0]<<endl;
			mdd(ans,mul(fac[n-xy-1],fac[xy],f[n&1][xy][n][1]));
		}

		{
			int x=fac[n];
			foru(i,1,n){
				mll(x,a[i][0][0]);
			}
			mdd(ans,x);
		}

		cout<<ans;
	}
}


namespace SUBA{
	int f[2][505][4][4];
	int g[2][505][4][4][2];
	void work(){
		f[0][0][0][0]=1;
		foru(i,0,n-1){
			bool t=(i+1)&1;
			foru(x,0,i){
				foru(y,0,min(i,2)){
					foru(z,0,min(i,2)){
						f[t][x][y][z]=0;
					}
				}
			}
			foru(x,0,i){
				foru(y,0,min(i,2)){
					foru(z,0,min(i,2)){
						if(f[t^1][x][y][z]==0)	continue;
						int v=f[t^1][x][y][z];
						mdd(f[t][x+1][y][z],mul(v,a[i+1][0][0]));
						mdd(f[t][x][y+1][z],mul(v,a[i+1][0][1]));
						mdd(f[t][x][y][z+1],mul(v,a[i+1][1][0]));
						mdd(f[t][x][y][z],mul(v,a[i+1][1][1]));
					}
				}
			}
		}
		g[1][1][0][0][0]=1;
		g[1][0][1][0][1]=1;
		foru(i,1,n-1){
			bool t=(i+1)&1;
			foru(x,0,i){
				foru(y,0,min(i,2)){
					foru(z,0,min(i,2)){
						g[t][x][y][z][0]=0;
						g[t][x][y][z][1]=0;
					}
				}
			}
			foru(x,0,i){
				foru(y,0,min(i,2)){
					foru(z,0,min(i,2)){
						if(g[t^1][x][y][z][0]==0 && g[t^1][x][y][z][1]==0)	continue;
						mdd(g[t][x+1][y][z][0],g[t^1][x][y][z][0]);
						mdd(g[t][x][y+1][z][1],g[t^1][x][y][z][0]);
						mdd(g[t][x][y][z+1][0],g[t^1][x][y][z][1]);
						mdd(g[t][x][y][z][1],g[t^1][x][y][z][1]);
					}
				}
			}
		}

		int ans=0;
		foru(x,0,n){
			foru(y,0,min(n,2)){
				foru(z,0,min(n,2)){
					if(x+y+z>n)	break;
					if(g[n&1][x][y][z][0]==0)	continue;
					// cout<<x<<' '<<y<<' '<<z<<' '<<g[n][x][y][z][0]<<endl;
					mdd(ans,mul(g[n&1][x][y][z][0],f[n&1][x][y][z],fac[x],fac[y],fac[z],fac[n-x-y-z]));
				}
			}
		}
		cout<<ans;
	}
}

namespace SUBN500{
	// int f[505][505][505];
	void work(){
		
	}
}

void solve(bool SPE){ 

	fac[0]=1;
	foru(i,1,2000){
		fac[i]=mul(fac[i-1],i);
	}
	ifac[2000]=qpow(fac[2000],mod-2);
	ford(i,1999,0){
		ifac[i]=mul(ifac[i+1],i+1);
	}

	bool A=1;

	n=RIN;
	foru(i,1,n){
		a[i][0][0]=RIN;
		a[i][0][1]=RIN;
		a[i][1][0]=RIN;
		a[i][1][1]=RIN;
		A&=a[i][1][0]==0;
		A&=a[i][1][1]==0;
	}

	// if(n<=8){
	// 	SUBN8::work();
	// 	return ;
	// 	// cout<<endl;
	// }

	if(A){
		SUBA::work();
		return ;
	}

	// if(n<=100){
	SUBN18::work();
	return ;
	// }

	// SUBN500::work();

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
	if(freopen("matrix2.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("matrix.in","r",stdin));
	if(freopen("matrix.out","w",stdout));
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