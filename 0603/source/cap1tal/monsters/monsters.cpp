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
#define PBDS __gnu_pbds
#include <bits/extc++.h>
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
template<typename T>\
pb<T>& operator += (pb<T>& x,const T& y){x.push_back(y);return x;}

#define OPERATOR_FOR_PUSH(p)\
template<typename T>\
p<T>& operator += (p<T>& x,const T& y){x.push(y);return x;}

#define OPERATOR_FOR_INSERT(i)\
template<typename T>\
i<T>& operator += (i<T>& x,const T& y){x.insert(y);return x;}

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
class OPT{
public:
	int t,x,y,z,w;
}opt[MAXN<<1];

struct Info{
	int sz;
	LL sum;
	Info(int sz=0,LL sum=0):sz(sz),sum(sum){}
	Info operator + (const Info& x)const{
		return Info(sz+x.sz,sum+x.sum);
	}
	void operator += (const Info& x){
		sz+=x.sz;
		sum+=x.sum;
	}
};
template<class cptr,class ptr,class cmp,class _alloc>
struct dsupdate{
	typedef Info metadata_type;
	virtual cptr node_begin() const = 0;
	virtual cptr node_end() const = 0;
	int rank(LL k){
		int ret=0;
		auto it=node_begin();
		while(it!=node_end()){
			auto lc=it.get_l_child();
			auto rc=it.get_r_child();
			// int ls=lc==node_end()?0:**lc;
			// int rs=rc==node_end()?0:**rc;
			
			// cerr<<"at "<<(**it)<<' '<<ls<<' '<<rs<<endl;
			
			if(((**it)>=k)){
				it=lc;
			}else{
				ret++;
				if(lc!=node_end())	ret+=lc.get_metadata().sz;
				it=rc;
			}
		}
		return ret;
	}
	LL presum_by_num(int x){
		LL ret=0;
		auto it=node_begin();
		while(1){
			auto lc=it.get_l_child();
			auto rc=it.get_r_child();

			if(lc!=node_end()){
				if(lc.get_metadata().sz>=x){
					it=lc;
					continue;
				}
				x-=lc.get_metadata().sz;
				ret+=lc.get_metadata().sum;
			}

			x--;
			ret+=**it;
			if(x==0)	return ret;
			
			it=rc;
		}
	}
	LL sum_by_rank(int l,int r){
		LL ret=presum_by_num(r);
		if(l>1)	ret-=presum_by_num(l-1);
		return ret;
	}
	int LOWER_BOUND(LL k){
		int ret=n+1;
		int lf=0;

		auto it=node_begin();
		while(it!=node_end()){
			auto lc=it.get_l_child();
			auto rc=it.get_r_child();

			if((**it)>=k){
				ret=lf+(lc==node_end()?0:lc.get_metadata().sz)+1;
				it=lc;
			}else{
				lf+=(lc==node_end()?0:lc.get_metadata().sz)+1;
				it=rc;
			}
		}
		
		return ret;
	}
	int UPPER_BOUND(LL k){
		int ret=n+1;
		int lf=0;

		auto it=node_begin();
		while(it!=node_end()){
			auto lc=it.get_l_child();
			auto rc=it.get_r_child();

			if((**it)>k){
				ret=lf+(lc==node_end()?0:lc.get_metadata().sz)+1;
				it=lc;
			}else{
				lf+=(lc==node_end()?0:lc.get_metadata().sz)+1;
				it=rc;
			}
		}
		
		return ret;
	}
	void operator () (ptr it,cptr endit){
		auto lc=it.get_l_child();
		auto rc=it.get_r_child();
		Info res(1,**it);
		if(lc!=endit)	res+=lc.get_metadata();
		if(rc!=endit)	res+=rc.get_metadata();
		const_cast<Info&>(it.get_metadata())=res;
	}
};

PBDS::tree<LL,PBDS::null_type,less_equal<LL>,PBDS::rb_tree_tag,dsupdate> tr;

class DS{

public:
	int rank(LL k){
		return tr.rank(k)+1;
		// cerr<<"ok ranking "<<k<<endl;
		// int ret=0;
		// foru(i,1,n){
		// 	ret+=a[i]<k;
		// 	cerr<<a[i]<<' ';
		// }
		// cerr<<endl;
		// int res=tr.rank(k)+1;
		// cerr<<' '<<ret+1<<' '<<res<<endl;
		// return ret+1;
	}
	LL sum_by_rank(int l,int r){
		if(l>r)	return 0;
		return tr.sum_by_rank(l,r);

		// LL ret=0;
		// foru(i,l,r){
		// 	ret+=a[i];
		// }
		// return ret;
	}
	int lower_bound(LL k){
		return tr.LOWER_BOUND(k);
		// foru(i,1,n){
		// 	if(a[i]>=k)	return i;
		// }
		// return n+1;
	}
	int upper_bound(LL k){
		return tr.UPPER_BOUND(k);
		// foru(i,1,n){
		// 	if(a[i]>k)	return i;
		// }
		// return n+1;
	}
}ds;

LL calc(int m,int k,int l,int r){
	// cerr<<endl;
	// cerr<<m<<' '<<k<<' '<<l<<' '<<r<<endl;
	LL L=-1e10,R=1e10,V=0,res=0;
	while(L<=R){
		LL mid=(L+R)>>1;

		LL lf=0;
		LL rf=0;

		int rkmid=ds.rank(mid+1);
		lf=min(n-k,rkmid-1)*mid;
		if(rkmid<=n-k){
			lf+=ds.sum_by_rank(rkmid,n-k);
			// lf=0;
		}
		
		int rkmmid=ds.rank(m+mid);
		// if(rkmmid<=n-k+1)
		rf=min(k,n-rkmmid+1)*(m+mid);
		if(rkmmid>n-k+1){
			rf+=ds.sum_by_rank(n-k+1,rkmmid-1);
		}

		lf-=(n-k)*mid;
		rf=(m+mid)*(LL)k-rf;

		if(lf>=rf){
			V=mid;
			res=lf-rf;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}

	// foru(i,1,n){
	// 	cerr<<a[i]<<' ';
	// }
	// HH;
	// cerr<<V<<' '<<res<<endl;

	// static int b[MAXN];
	int lf=ds.lower_bound(V);
	int rf=ds.upper_bound(m+V)-1;
	// while(lf-1>=1 && a[lf-1]>=V)	lf--;
	// while(rf+1<=n && a[rf+1]<=m+V)	rf++;

	// foru(i,1,n){
	// 	cerr<<b[i]<<' ';
	// }
	// cerr<<endl;
	// cerr<<V<<' '<<lf<<' '<<rf<<endl;
	assert(rf>n-k);

	LL ret=0;
	ret+=ds.sum_by_rank(max(1,l),min(r,lf-1));
	ret+=ds.sum_by_rank(max(rf+1,l),min(r,n))-(LL)m*max(min(r,n)-max(rf+1,l)+1,0);
	ret+=V*max(min(rf-res,(LL)r)-max(lf,l)+1,0ll);
	ret+=(V+1)*max(min(rf,r)-max(rf-res+1,(LL)l)+1,0ll);
	// foru(i,l,r){
	// 	if(lf<=i && i<=rf-res)	ret+=V;
	// 	if(rf-res<i && i<=rf)	ret+=V+1;
	// 	// if(i>rf)	ret+=a[i]-m;
	// }
	return ret;
}

int M,K,q;
namespace Q0{
	void workQ0(){
		LL l=-1e10,r=1e10,V=0,res=0;
		while(l<=r){
			LL mid=(l+r)>>1;

			LL lf=0;
			LL rf=0;

			foru(i,1,n-K){
				lf+=max(a[i]-mid,0ll);
			}
			foru(i,n-K+1,n){
				rf+=max(mid-(a[i]-M),0ll);
			}

			if(lf>=rf){
				V=mid;
				res=lf-rf;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}

		// foru(i,1,n){
		// 	cerr<<a[i]<<' ';
		// }
		// HH;
		// cerr<<V<<' '<<res<<endl;

		static LL b[MAXN];
		foru(i,1,n){
			b[i]=a[i];
			if(i>n-K)	b[i]-=M;
		}
		foru(i,1,n-K){
			chkmin(b[i],V);
		}
		foru(i,n-K+1,n){
			chkmax(b[i],V);
		}
		for(int i=n;i>=1;i--){
			if(b[i]==V && res){
				res--;
				b[i]++;
			}
		}
		sort(b+1,b+1+n);
		foru(i,1,n){
			printf("%lld ",b[i]);
		}
		HH;
	}
}

void solve(bool SPE){ 
	n=RIN;
	M=RIN,K=RIN,q=RIN;

	static int sa[MAXN];
	foru(i,1,n){
		a[i]=RIN;
		sa[i]=a[i];
		tr.insert(a[i]);
	}

	foru(o,1,q){
		opt[o].t=RIN;
		if(opt[o].t==1){
			opt[o].x=RIN;
			opt[o].y=RIN;
			opt[o].z=RIN;
		}else if(opt[o].t==2){
			opt[o].x=RIN;
			opt[o].y=RIN;
		}else{
			opt[o].x=RIN;
			opt[o].y=RIN;
			opt[o].z=RIN;
			opt[o].w=RIN;
		}
	}

	sort(a+1,a+1+n);
	
	//work Q0
	Q0::workQ0();

	foru(o,1,q){
		// cerr<<o<<endl;
		auto [ty,x,y,z,w]=opt[o];
		if(ty==1){
			// cerr<<"q1"<<endl;
			int m=x,k=y,x=z;
			printf("%lld\n",calc(m,k,x,x));
		}else if(ty==2){
			// cerr<<"mdf"<<' '<<x<<' '<<y<<endl;
			int p=x,v=y;

			tr.erase(tr.upper_bound(sa[p]));
			tr.insert(v);
			
			// foru(i,1,n){
			// 	if(a[i]==sa[p]){
			// 		a[i]=v;
			// 		break;
			// 	}
			// }
			sa[p]=v;
			
			// sort(a+1,a+1+n);
		}else{
			// cerr<<"q2"<<endl;
			int m=x,k=y,l=z,r=w;
			printf("%lld\n",calc(m,k,l,r));
		}
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
	if(freopen("a.in","r",stdin));
	// if(freopen("monsters1.in","r",stdin));
	if(freopen("monsters.out","w",stdout));
	#ifdef ONLINE_JUDGE
	if(freopen("monsters.in","r",stdin));
	if(freopen("monsters.out","w",stdout));
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