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
int a[MAXN];
int b[MAXN];

int q;
int op[MAXN];

void showperm(int* A){
	static bool vis[MAXN];
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	int cnt=0;
	foru(i,1,n)	vis[i]=0;
	foru(i,1,n){
		if(vis[i])	continue;
		int u=i;
		cnt++;
		while(1){
			vis[u]=1;
			int v=A[u];
			cout<<u<<"->";
			if(v==i){
				cout<<"("<<v<<")"<<endl;
				break;
			}
			u=v;
		}
	}
	cout<<"tot: "<<cnt<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void opt(int* A,int* B){
	static int t[MAXN];
	foru(i,1,n){
		t[i]=A[B[A[i]]];
	}
	foru(i,1,n){
		A[i]=t[i];
	}
}
void optself(int* A){
	static int t[MAXN];
	foru(i,1,n){
		t[i]=A[A[i]];
	}
	foru(i,1,n){
		A[i]=t[i];
	}
}

namespace SUB1{
	void work(){
		foru(o,1,q){
			if(op[o]==1)	opt(a,b);
			else	opt(b,a);
		}
		
		foru(i,1,n){
			printf("%d ",a[i]);
		}
		printf("\n");
		foru(i,1,n){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}

int mpow(int x,__int128 y,int p){
	int ret=1;
	while(y){
		if(y&1)	ret=(LL)ret*x%p;
		x=(LL)x*x%p,y>>=1;
	}
	return ret;
}

// namespace SUBF1{
// 	int st[19][MAXN];
// 	bool vis[MAXN];
// 	int len[MAXN];
// 	void work(){
// 		foru(i,1,n){
// 			a[i]=b[a[i]];
// 		}

// 		foru(i,1,n){
// 			static stack<int> st;
// 			if(vis[i])	continue;
// 			int u=i;
// 			int num=0;
// 			while(!vis[u]){
// 				vis[u]=1;
// 				num++;
// 				u=a[u];
// 				st+=u;
// 			}
// 			while(!st.empty()){
// 				len[st.top()]=num;
// 				st.pop();
// 			}
// 		}

// 		foru(i,1,n){
// 			st[0][i]=a[i];
// 			a[i]=i;
// 		}
// 		for(int j=1;(1<<j)<=q;j++){
// 			for(int i=1;i<=n;i++){
// 				st[j][i]=st[j-1][st[j-1][i]];
// 			}
// 		}

// 		foru(i,1,n){
// 			int N=mpow(2,q,len[i]);
// 			for(int j=0;(1<<j)<=q;j++){
// 				if((N>>j)&1){
// 					a[i]=st[j][a[i]];
// 				}
// 			}
// 		}


// 		// foru(i,1,n){
// 		// 	a[i]=i;
// 		// }
// 		// foru(o,1,q){
// 		// 	static int t[MAXN];
// 		// 	foru(i,1,n){
// 		// 		t[i]=a[a[i]];
// 		// 		// t[i]=st[0][a[i]];
// 		// 	}
// 		// 	foru(i,1,n){
// 		// 		a[i]=t[i];
// 		// 		// a[i]=st[0][a[i]];
// 		// 	}
// 		// }

// 		static int t[MAXN];
// 		foru(i,1,n){
// 			t[b[i]]=i;
// 		}
// 		foru(i,1,n){
// 			printf("%d ",t[a[i]]);
// 			// printf("%d ",A[i].fi);
// 		}
// 		printf("\n");
// 		foru(i,1,n){
// 			printf("%d ",b[i]);
// 		}
// 		printf("\n");
// 	}
// }

void cp(int* A,int* B){
	foru(i,1,n){
		A[i]=B[i];
	}
}
void useon(int* A,int* B,int* C){
	static int t[MAXN];
	foru(i,1,n){
		t[i]=A[B[i]];
	}
	cp(C,t);
}

namespace SUBPQ{
	int p[MAXN];
	int Q[MAXN];
	int Q1[MAXN];

	bool vis[MAXN];
	// int len[MAXN];

	vector<int> prim;
	bitset<100005> np;
	void genprim(){
		foru(i,2,n){
			if(!np[i]){
				prim+=i;
			}
			for(int j=0;j<sz(prim) && i*prim[j]<=n;j++){
				np[i*prim[j]]=1;
				if(i%prim[j]==0)	break;
			}
		}
	}

	unordered_map<int,int> mp;

	void work(){
		genprim();

		useon(b,a,Q);
		
		// get Q cycle
		foru(i,1,n){
			// static stack<int> st;
			if(vis[i])	continue;
			int u=i;
			int num=0;
			while(!vis[u]){
				vis[u]=1;
				num++;
				u=Q[u];
				// st+=u;
			}
			// while(!st.empty()){
			// 	len[st.top()]=num;
			// 	st.pop();
			// }

			// cerr<<num<<endl;
			//gen LCM
			for(auto p:prim){
				if(num==1)	break;
				if(!np[num]){
					chkmax(mp[num],1);
					break;
				}

				if(num%p!=0)	continue;
				int cnt=0;
				while(num%p==0){
					cnt++;
					num/=p;
				}
				chkmax(mp[p],cnt);
			}
		}

		foru(i,1,n){
			p[i]=i;
		}

		__int128 LCM=1;
		for(auto [p,m]:mp){
			while(m--){
				LCM*=p;
			}
		}

		__int128 mi=1;
		__int128 tot=0;
		foru(o,1,q){
			if(op[o]==1){
				tot+=mi;
				tot%=LCM;
			}
			mi*=2;
			mi%=LCM;
		}

		// cerr<<tot<<' '<<LCM<<endl;

		// showperm(p);

		// useon(p,Q,p);
		// showperm(p);

		// // useon(Q,Q,Q);
		// useon(p,Q,p);
		// showperm(p);
		// useon(p,Q,p);
		// showperm(p);

		
		while(tot){
			if(tot&1){
				useon(p,Q,p);
			}
			tot>>=1;
			useon(Q,Q,Q);
		}

		// foru(i,1,tot){
		// 	useon(p,Q,p);
		// }
		useon(b,a,Q1);
		foru(i,1,n){
			Q[i]=i;
		}
		while(mi){
			if(mi&1){
				useon(Q,Q1,Q);
			}
			mi>>=1;
			useon(Q1,Q1,Q1);
		}
		// foru(i,1,q){
		// 	useon(Q,Q,Q);
		// }



		useon(a,p,a);
		foru(i,1,n){
			b[a[i]]=Q[i];
		}

		
		foru(i,1,n){
			printf("%d ",a[i]);
		}
		printf("\n");
		foru(i,1,n){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}

void solve(bool SPE){ 
	n=RIN;
	foru(i,1,n){
		a[i]=RIN;
	}
	foru(i,1,n){
		b[i]=RIN;
	}

	bool f1=1;

	q=RIN;
	foru(i,1,q){
		op[i]=RIN;
		f1&=op[i]==1;
	}


	// n=5;
	// foru(i,1,n){
	// 	a[i]=i%n+1;
	// }
	// showperm(a);
	// optself(a);
	// showperm(a);
	// optself(a);
	// showperm(a);
	// optself(a);
	// showperm(a);
	// optself(a);
	// showperm(a);

	// exit(0);

	SUBPQ::work();
	// if(f1){
	// 	SUBF1::work();
	// 	return ;
	// }
	// if(n<=5000 && q<=5000){
	// 	SUB1::work();
	// 	return ;
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
	// if(freopen("ex_dualperm1.in","r",stdin));
	if(freopen("dualperm.in","r",stdin));
	if(freopen("dualperm.out","w",stdout));
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