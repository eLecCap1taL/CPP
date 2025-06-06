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
#define MAXN 1000005
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

int n;
LL b,p,m;
class OPT{
public:
	int ty;
	LL v;
}a[MAXN];

unordered_map<int,vector<int>> mls;
vector<int> als[MAXN];
vector<LL> sls[MAXN];
vector<int> ls;

bitset<MAXN> us;

LL ans=LLONG_MIN;

void calc(){
	int N=0;
	for(auto i:ls){
		N+=us[i];
	}
	// cerr<<' '<<N<<endl;
	if(N*m>b)	return ;

	
	LL cur=0;
	{
		LL suf=1;
		for(auto i:ls){
			suf*=a[i].v;
		}
		cur+=sls[0].back()*suf;
		for(auto i:ls){
			if(!us[i])	suf/=a[i].v;
			if(!sls[i].empty()){
				cur+=sls[i].back()*suf;
			}
		}
	}


	int res=(b-N*m)/p;
	LL L=-3e18,R=3e18,mx=0;
	while(L<=R){
		LL Mid=(L+R)/2;
		LL Sum=0;
		int Num=0;
		int Add=0;
		// if(N==0){
		// 	cerr<<"BS"<<' '<<Mid<<' '<<L<<' '<<R<<endl;
		// }

		LL pre=1;
		LL suf=1;
		for(auto i:ls){
			suf*=a[i].v;
		}
		for(auto i:ls){
			if(!us[i])	pre*=a[i].v,suf/=a[i].v;
			if(!sls[i].empty()){
				int num=0;
				LL sum=0;
				int add=0;
				{
					int l=0,r=sls[i].size()-1;
					while(l<=r){
						int mid=(l+r)>>1;
						if(als[i][mid]*(pre-1)*suf>Mid){
							num=mid+1;
							sum=sls[i][mid];
							l=mid+1;
						}else{
							r=mid-1;
						}
					}
				}
				{
					int l=0,r=sls[i].size()-1;
					while(l<=r){
						int mid=(l+r)>>1;
						if(als[i][mid]*(pre-1)*suf>=Mid){
							add=mid+1;
							l=mid+1;
						}else{
							r=mid-1;
						}
					}
					add-=num;
				}
				
				// if(N==0){
				// 	cerr<<i<<' '<<num<<endl;
				// }
				Num+=num;
				Add+=add;
				Sum+=sum*(pre-1)*suf;
			}
		}

		Sum+=min(Add,res-Num)*Mid;
		if(Num<=res){
			// assert(Sum>=mx);
			mx=Sum;
			// chkmax(mx,Sum);
			R=Mid-1;
		}else{
			L=Mid+1;
		}
	}

	// cerr<<res<<endl;
	// cerr<<cur<<endl;
	// if(N==0){
	// 	cerr<<cur<<' '<<mx<<endl;
	// }
	chkmax(ans,cur+mx);
}

void dfs(unordered_map<int,vector<int>>::iterator it){
	if(it==mls.end()){
		calc();
		return ;
	}
	for(auto i:it->se){
		us[i]=1;
	}
	dfs(next(it));
	ford(i,(int)it->se.size()-1,0){
		us[it->se[i]]=0;
		dfs(next(it));
	}
}

void solve(bool SPE){ 
	n=RIN,b=RIN,p=RIN,m=RIN;

	als[0]+=1;
	int lst=0;
	foru(i,1,n){
		char c=RCIN;
		if(c=='+'){
			a[i].ty=0;
		}else{
			a[i].ty=1;
		}
		a[i].v=RIN;

		if(a[i].ty==1 && a[i].v==1)	continue;

		if(a[i].ty){
			lst=i;
			ls+=i;
		}
		if(a[i].ty){
			mls[a[i].v]+=i;
		}else{
			als[lst]+=a[i].v;
		}
	}

	auto process=[](vector<int>& X,vector<LL>& S)->void {
		S.clear();
		if(X.empty())	return ;
		S.resize(X.size(),0);
		sort(All(X),[](int x,int y)->bool {
			return x>y;
		});
		S[0]=X[0];
		for(size_t i=1;i<X.size();i++){
			S[i]=S[i-1]+X[i];
		}
	};
	process(als[0],sls[0]);
	for(auto i:ls){
		process(als[i],sls[i]);
	}

	dfs(mls.begin());

	cout<<ans;

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
	// if(freopen("CF1753E4.in","r",stdin));
	#ifdef ONLINE_JUDGE
	// if(freopen("CF1753E.in","r",stdin));
	// if(freopen("CF1753E.out","w",stdout));
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