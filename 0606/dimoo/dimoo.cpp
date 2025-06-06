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
#define MAXN 10000005
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
	// #define DEBUGING

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
inline bool chkmax(T1& x,const T2& y){return (T1)x<y?x=(T1)y,true:false;}
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
int a[MAXN];
int b[MAXN];
int n;
int jp[MAXN];
LL sum[MAXN];
LL qry(int x,int y){
	if(y<=x){
		if(y==0)	return sum[x];
		return sum[x]-sum[y-1];
	}else{
		return sum[x]+sum[n-1]-sum[y-1];
	}
}
void rotate(int k){
	sum[0]=a[0];
	foru(i,1,n-1){
		sum[i]=sum[i-1]+a[i];
	}
	// foru(i,0,n-1){
	// 	cerr<<a[i]<<' ';
	// }
	// cerr<<endl;
	foru(i,0,n-1){
		if(a[i]==0)	continue;
		if(a[i]>=n){
			jp[i]=n;
			continue;
		}
		int j=i;
		LL s=a[i];
		foru(o,1,n-1){
			j=(j-1+n)%n;

			// if(a[j]>0){
			// 	if(jp[j]>0){
			// 		s+=jp[j];
			// 		o+=jp[j];
			// 		jp[i]=o-1;
			// 		j=((j-jp[j])%n+n)%n;
			// 		continue;
			// 	}else{
			// 		s+=a[j];
			// 	}
			// }

			// cerr<<i<<' '<<j<<' '<<o<<' '<<s<<endl;
			if(jp[j]>0){
				// cerr<<i<<' '<<j<<' '<<o<<' '<<a[j]<<' '<<jp[j]<<endl;
				{
					s+=jp[j]+1;
					if(s>=n){
						jp[i]=n;
						break;
					}
					int res=jp[j];
					o+=res;
					jp[i]=o;
					j=((j-res)%n+n)%n;
				}
				if(o<s-1){
					int res=s-1-o;
					int nj=((j-res)%n+n)%n;
					o+=res;
					// cerr<<(j-1+n)%n<<' '<<nj<<' '<<res<<endl;
					s+=qry((j-1+n)%n,nj);
					j=nj;
				}
				jp[i]=o;
				continue;
			}else{
				s+=a[j];
			}
			if(s>=n){
				jp[i]=n;
				break;
			}
			if(o>=s)	break;
			if(o<s-1){
				int res=s-1-o;
				int nj=((j-res)%n+n)%n;
				o+=res;
				// cerr<<(j-1+n)%n<<' '<<nj<<' '<<res<<endl;
				s+=qry((j-1+n)%n,nj);
				j=nj;
			}
			jp[i]=o;
		}

		// cerr<<i<<' '<<jp[i]<<endl;
	}
	// foru(i,0,n-1){
	// 	cerr<<jp[i]<<' ';
	// }
	// cerr<<endl;
	
	int tot=0;

	foru(i,0,n-1){
		b[i]+=a[i];
		int x=a[i];
		if(x>0){
			int K=k;
			x--;
			// cerr<<endl<<i<<" "<<K<<endl;
			b[i]--;
			b[((i+K)%n)]++;
		}
		int j=i;
		// int r=-1;
		// bool lst=0;
		foru(o,2,k){
			j=(j-1+n)%n;

			if(a[j]>0){
				// assert(!lst);
				// lst=1;
				o+=jp[j];
				j=((j-jp[j])%n+n)%n;
				continue;
			}
			// lst=0;
			if(x>0){
				int K=k-o+1;
				x--;
				// cerr<<endl<<i<<" "<<K<<' '<<o<<endl;
				b[i]--;
				b[((i+K)%n)]++;
				tot++;
			}else{
				break;
			}
		}
	}
}
void solve(bool SPE){ 
	n=RIN;
	int k=RIN;
	foru(i,0,n-1){
		a[i]=RIN;
	}
	rotate(min(n-1,k));
	static int c[MAXN];
	if(k>n-1){
		k-=n-1;
		bool z=0;
		foru(i,0,n-1){
			if(b[i]==0){
				z=1;
				break;
			}
		}
		if(z){
			foru(i,0,n-1){
				c[i]=b[((i-k)%n+n)%n];
			}
		}else{
			foru(i,0,n-1){
				c[i]=b[i];
			}
		}
	}else{
		foru(i,0,n-1){
			c[i]=b[i];
		}
	}
	// foru(i,0,n-1){
	// 	cout<<c[i]<<' ';
	// }
	u64 M=12345678901ull;
	u64 mi=1;
	u64 out=0;
	foru(i,0,n-1){
		mi*=M;
		out+=mi*((u64)c[i]+1);
	}
	cout<<out;
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
	if(freopen("dimoo5.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("dimoo.in","r",stdin));
	if(freopen("dimoo.out","w",stdout));
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