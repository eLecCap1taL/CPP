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
string s;
int n;
int C,q;

class QR{
public:
	int l,r;
}qr[MAXN];


namespace STRHASH{
	int mpow(int x,int y,int m){
		int ret=1;
		while(y){
			if(y&1)	ret=(LL)ret*x%m;
			x=(LL)x*x%m,y>>=1;
		}
		return ret;
	}

	constexpr int m1=998244853;
	constexpr int m2=1e9+7;
	constexpr int b1=157;
	constexpr int b2=173;

	int fac1[MAXN];
	int fac2[MAXN];

	class stringHash{
	public:
		int h1[MAXN];
		int h2[MAXN];
		void init(const string& S){
			foru(i,1,n){
				h1[i]=((LL)h1[i-1]*b1+S[i])%m1;
				h2[i]=((LL)h2[i-1]*b2+S[i])%m2;
			}
		}
		LL operator () (int l,int r){
			int H1=(h1[r]-(LL)h1[l-1]*fac1[r-l+1])%m1;
			int H2=(h2[r]-(LL)h2[l-1]*fac2[r-l+1])%m2;
			if(H1<0)	H1+=m1;
			if(H2<0)	H2+=m2;
			return (LL)H1*1000000000ll+H2;
		}
	}hs,rhs,dhs,rdhs;

	void init(){
		fac1[0]=fac2[0]=1;
		foru(i,1,n){
			fac1[i]=(LL)fac1[i-1]*b1%m1;
			fac2[i]=(LL)fac2[i-1]*b2%m2;
		}

		hs.init(s);
		
		reverse(All(s));
		rhs.init(s);
		reverse(All(s));

		string d=s;
		foru(i,1,n){
			int dc=(i==n?'a':s[i+1]);
			dc-=(int)(s[i]);
			dc=(dc%C+C)%C;

			dc+=100;

			d[i]=(char)(dc);
		}
		dhs.init(d);

		ford(i,n,1){
			int dc=(i==1?'a':s[i-1]);
			dc-=(int)(s[i]);
			dc=(dc%C+C)%C;

			dc+=100;

			d[i]=(char)(dc);
		}
		reverse(All(d));
		rdhs.init(d);
	}

	LL qhash(int l,int r){
		return hs(l,r);
	}
	LL qrhash(int l,int r){
		return rhs(n-r+1,n-l+1);
	}
	LL qdhash(int l,int r){
		return dhs(l,r);
	}
	LL qrdhash(int l,int r){
		return rdhs(n-r+1,n-l+1);
	}
	bool can_caesar(int l1,int r1,int l2,int r2){
		assert(r1-l1==r2-l2);
		if(l1==r1)	return true;
		return qdhash(l1,r1-1)==qrdhash(l2+1,r2);
	}
};


using STRHASH::qhash;
using STRHASH::qrhash;
using STRHASH::can_caesar;

int binarySearch(int l,int r,function<bool(int)> check,int ret=-1){
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ret=mid;
		}else{
			r=mid-1;
		}
	}
	return ret;
}

int rad[MAXN];
int mrad[MAXN];
int src_max;

void calcSRC(){
	foru(i,1,n){
		rad[i]=binarySearch(1,min(i,n-i+1),[&](int L)->bool {
			return qhash(i-L+1,i)==qrhash(i,i+L-1);
		});
		assert(rad[i]!=-1);

		chkmax(src_max,rad[i]*2-1);
	}
	foru(i,1,n-1){
		mrad[i]=binarySearch(1,min(i,n-i),[&](int L)->bool {
			return qhash(i-L+1,i)==qrhash(i+1,i+L);
		},0);

		chkmax(src_max,mrad[i]*2);
	}

	// foru(i,1,n){
	// 	cout<<rad[i]<<' ';
	// }
	// HH;
	// foru(i,1,n){
	// 	cout<<mrad[i]<<' ';
	// }
	// HH;
}

class recParser{
	class QRY{
	public:
		int x;
		int& store;
	};
	vector<QRY> qls[MAXN];

	class D1{
		multiset<int> st;
	public:
		void insert(int v){
			st.insert(v);
		}
		void erase(int v){
			st.erase(st.find(v));
		}
		int max()const{
			if(st.empty())	return INT_MIN;
			return *st.rbegin();
		}
		void clear(){
			st.clear();
		}
	};

	class DS{
		int tg;

		class SegmentTree{
			class Node{
			public:
				int l,r;
				D1 st;
				int mx;
			}tr[MAXN<<2];
			inline int lc(int x){return x<<1;}
			inline int rc(int x){return x<<1|1;}
			void push_up(int p){
				tr[p].mx=max({tr[lc(p)].mx,tr[rc(p)].mx,tr[p].st.max()});
			}
		public:
			void build(int p,int l,int r){
				tr[p].l=l,tr[p].r=r;
				tr[p].st.clear();
				tr[p].mx=INT_MIN;
				if(tr[p].l==tr[p].r){
					return ;
				}
				int mid=(l+r)>>1;
				build(lc(p),l,mid);
				build(rc(p),mid+1,r);
			}
			void insert(int p,int pos,int k){
				if(tr[p].l==tr[p].r){
					tr[p].st.insert(k);
					tr[p].mx=tr[p].st.max();
					return ;
				}
				int mid=(tr[p].l+tr[p].r)>>1;
				if(pos<=mid)	insert(lc(p),pos,k);
				else	insert(rc(p),pos,k);
				push_up(p);
			}
			void erase(int p,int pos,int k){
				if(tr[p].l==tr[p].r){
					tr[p].st.erase(k);
					tr[p].mx=tr[p].st.max();
					return ;
				}
				int mid=(tr[p].l+tr[p].r)>>1;
				if(pos<=mid)	erase(lc(p),pos,k);
				else	erase(rc(p),pos,k);
				push_up(p);
			}
			int query(int p,int l,int r){
				if(l<=tr[p].l && tr[p].r<=r)	return tr[p].mx;
				int ret=tr[p].st.max();
				int mid=(tr[p].l+tr[p].r)>>1;
				if(l<=mid)	chkmax(ret,query(lc(p),l,r));
				if(r>mid)	chkmax(ret,query(rc(p),l,r));
				return ret;
			}
		}seg;

		D1 d[MAXN];
	public:
		void insert(int x,int k){
			// d[x].insert(k-tg);
			seg.insert(1,x,k-tg);
		}
		void erase(int x,int k){
			// d[x].erase(k-tg);
			seg.erase(1,x,k-tg);
		}
		void step(){
			tg+=2;
		}
		int qry(int x){
			// int ret=INT_MIN;
			// foru(i,x,n){
			// 	chkmax(ret,d[i].max());
			// }
			int ret=seg.query(1,x,n);
			if(ret!=INT_MIN)	ret+=tg;
			return ret;
		}
		void init(){
			seg.build(1,1,n);
			// foru(i,1,n){
			// 	d[i].clear();
			// }
		}
	}ds;

public:
	vector<pair<int,int>> yls_flex[MAXN];
	vector<pair<int,int>> yls_fix[MAXN];

	virtual void addRec_fix(int xr,int yl,int k){
		yls_fix[yl]+=mkp(xr,k);
	}
	virtual void addRec_flex(int xr,int yl,int yr,int k){
		yls_flex[yl]+=mkp(xr,k);
		yls_flex[yr+1]+=mkp(xr,-(k+(yr+1-yl)*2));
	}
	virtual void add_qry(int x,int y,int& store){
		qls[y]+=QRY({x,store});
	}
	void process(){
		// process flex
		ds.init();
		foru(i,1,n){
			ds.step();
			for(auto& [xr,k]:yls_flex[i]){
				if(k>0)	ds.insert(xr,k);
				else	ds.erase(xr,-k);
			}
			for(auto& [x,store]:qls[i]){
				chkmax(store,ds.qry(x));
			}
		}
		
		// process fix
		ds.init();
		foru(i,1,n){
			for(auto& [xr,k]:yls_fix[i]){
				ds.insert(xr,k);
			}
			for(auto& [x,store]:qls[i]){
				chkmax(store,ds.qry(x));
			}
		}
	}
}par_xy;

class recParser_YX: public recParser{
public:
	void addRec_fix(int yl,int xr,int k) override {
		recParser::addRec_fix(n-yl+1,n-xr+1,k);
	}
	void addRec_flex(int yl,int xl,int xr,int k) override {
		recParser::addRec_flex(n-yl+1,n-xr+1,n-xl+1,k);
	}
	void add_qry(int x,int y,int& store) override {
		recParser::add_qry(n-y+1,n-x+1,store);
	}
}par_yx;

void stringParser(int l,int r){
	int c=binarySearch(1,min(l-1,n-r),[&](int len)->bool {
		return can_caesar(l-len,l-1,r+1,r+len);
	},0);
	if(c==0)	return ;

	int cl=l-c;
	int cr=r+c;

	int span=binarySearch(1,min(cl-1,n-cr),[&](int len)->bool {
		return qhash(cl-len,cl-1)==qrhash(cr+1,cr+len);
	},0);

	// [cl,l-1] ~ [r+1,cr]
	int len=r-l+1;

	if(c>1){
		par_xy.addRec_flex(r+1,r+1,cr-1,len+2);
		par_yx.addRec_flex(l-1,cl+1,l-1,len+2);
	}
	par_xy.addRec_fix(r+1,cr,len+2*c+2*span);
	par_yx.addRec_fix(l-1,cl,len+2*c+2*span);
}

void solve(bool SPE){ 
	s=" "+RSIN+" ";

	// s=" aabxxdcc ";

	n=sz(s)-2;

	C=RIN,q=RIN;

	foru(i,1,q){
		qr[i]={RIN,RIN};
	}

	STRHASH::init();

	// cout<<can_caesar(1,3,6,8)<<endl;
	// cout<<can_caesar(1,4,5,8)<<endl;
	// cout<<can_caesar(1,2,7,8)<<endl;
	// cout<<can_caesar(2,3,7,8)<<endl;
	// cout<<can_caesar(2,3,6,7)<<endl;
	// exit(0);
	
	calcSRC();

	foru(i,1,n){
		int L=i-rad[i]+1;
		int R=i+rad[i]-1;

		stringParser(L,R);
	}

	foru(i,1,n-1){
		int L=i-mrad[i]+1;
		int R=i+mrad[i];
		
		stringParser(L,R);
	}
	
	static int ans[MAXN];
	foru(i,1,q){
		auto [l,r]=qr[i];
		ans[i]=src_max;
		par_xy.add_qry(l,r,ans[i]);
		par_yx.add_qry(l,r,ans[i]);
	}

	par_xy.process();
	par_yx.process();

	foru(i,1,q){
		printf("%d\n",ans[i]);
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
	#ifndef ONLINE_JUDGE
	if(freopen("ex_caesar1.in","r",stdin));
	// if(freopen("caesar.in","r",stdin));
	// if(freopen("caesar.out","w",stdout));
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