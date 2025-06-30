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
class Node{
public:
	int x,c;
	bool operator < (const Node& o)const{
		return x<o.x;
	}
};

vector<Node> a;

int q;
int tid;

class Matrix{
public:
	LL a[5][5];
	Matrix(){
		memset(a,0,sizeof a);
	}
	LL* operator [] (const int& idx){
		return a[idx];
	}
	const LL* operator [] (const int& idx)const{
		return a[idx];
	}
	void fillc(const int& idx,const LL& A,const LL& B,const LL& C,const LL& D,const LL& E){
		a[0][idx]=A;
		a[1][idx]=B;
		a[2][idx]=C;
		a[3][idx]=D;
		a[4][idx]=E;
	}
	Matrix operator * (const Matrix& x)const{
		Matrix ret;
		foru(i,0,4){
			foru(j,0,4){
				ret[i][j]=max({a[i][0]+x[0][j],a[i][1]+x[1][j],a[i][2]+x[2][j],a[i][3]+x[3][j],a[i][4]+x[4][j]});
			}
		}
		return ret;
	}
};

class Vector{
public:
	LL a[5];
	Vector(){
		memset(a,0,sizeof a);
	}
	LL& operator [] (const int& idx){
		return a[idx];
	}
	const LL& operator [] (const int& idx)const{
		return a[idx];
	}
	Vector operator * (const Matrix& x)const{
		Vector ret;
		foru(j,0,4){
			ret[j]=max({a[0]+x[0][j],a[1]+x[1][j],a[2]+x[2][j],a[3]+x[3][j],a[4]+x[4][j]});
		}
		return ret;
	}
};

constexpr LL inf=5e13;

Matrix gen(int L,int c){
	Matrix ret;

	if(c==-1){
		// 机器人
		// 结算
		
		ret.fillc(0,0,0,0,-1*L,-inf);
		ret.fillc(1,0,0,0,-inf,-2*L);
		ret.fillc(2,-inf,-inf,-inf,-inf,-inf);
		ret.fillc(3,-inf,-inf,-inf,-inf,-inf);
		ret.fillc(4,-inf,-inf,-inf,-inf,-inf);
		// nf[0]=max({f[0],f[1],f[2],f[3]-L});
		// nf[1]=max({f[0],f[1],f[2],f[4]-2*L});
		// nf[2]=-1e16;
		// nf[3]=-1e16;
		// nf[4]=-1e16;
	}else{
		ret.fillc(0,c-2*L,-inf,-inf,-inf,-inf);
		ret.fillc(1,-inf,c-1*L,-inf,-inf,-inf);
		ret.fillc(2,0,0,0,-inf,-inf);
		ret.fillc(3,c,c,c,c-1*L,-inf);
		ret.fillc(4,c,c,c,-inf,c-2*L);
		// nf[0]=max({f[0]+c-2*L});
		// nf[1]=max({f[1]+c-L});
		// nf[2]=max({f[0],f[1],f[2]});
		// nf[3]=max({f[0]+c,f[1]+c,f[2]+c,f[3]+c-L});
		// nf[4]=max({f[0]+c,f[1]+c,f[2]+c,f[4]+c-2*L});
	}

	return ret;
}

Matrix one(){
	Matrix ret;
	foru(i,0,4){
		foru(j,0,4){
			if(i==j)	ret[i][j]=0;
			else	ret[i][j]=-inf;
		}
	}
	return ret;
}

Vector gen(int c){
	Vector f;

	if(c==-1){
		//first robot
		f[0]=0;
		f[1]=0;
		f[2]=-inf;
		f[3]=-inf;
		f[4]=-inf;
	}else{
		f[0]=-inf;
		f[1]=-inf;
		f[2]=0;
		f[3]=c;
		f[4]=c;
	}

	return f;
}

unordered_map<int,int> mp;
vector<int> X;
Node in[MAXN];

Matrix ls[MAXN];

class DS{
public:
	class Node{
	public:
		int l,r;
		Matrix d;
	}tr[MAXN<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		tr[p].d=tr[lc(p)].d*tr[rc(p)].d;
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		tr[p].d=one();
		if(l==r){
			return ;
		}
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
	}
	void modify(int p,int pos,int L,int c){
		if(tr[p].l==tr[p].r){
			tr[p].d=gen(L,c);
			return ;
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		if(pos<=mid)	modify(lc(p),pos,L,c);
		else	modify(rc(p),pos,L,c);
		push_up(p);
	}
	void query(int p,int l,int r,Vector& f){
		// cout<<p<<' '<<tr[p].l<<' '<<tr[p].r<<' '<<l<<' '<<r<<endl;
		if(l<=tr[p].l && tr[p].r<=r){
			f=f*tr[p].d;
			return ;
			// return tr[p].d;
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	query(lc(p),l,r,f);
		if(r>mid)	query(rc(p),l,r,f);
	}
}ds;

void solve(bool SPE){ 
	tid=RIN;
	q=RIN;

	foru(o,1,q){
		int ty=RIN;
		if(ty==1){
			int x=RIN;
			in[o]=Node{x,-1};
			X+=x;
		}else{
			int x=RIN,c=RIN;
			in[o]=Node{x,c};
			X+=x;
		}
	}

	sort(All(X));
	foru(i,1,q){
		mp[X[i-1]]=i;
		// ls[i]=one();
	}

	ds.build(1,1,q);

	static set<pair<int,int>> st;

	// return ;
	foru(o,1,q){
		auto [x,c]=in[o];
		int p=mp[x];

		auto it=st.upper_bound(mkp(x,0));
		if(it!=st.end()){
			ds.modify(1,mp[it->fi],it->fi-x,it->se);
			// ls[mp[it->fi]]=gen(it->fi-x,it->se);
		}

		it=st.insert(mkp(x,c)).fi;

		if(it!=st.begin()){
			ds.modify(1,p,x-prev(it)->fi,c);
			// ls[p]=gen(x-prev(it)->fi,c);
		}

		Vector f=gen(st.begin()->se);

		int l=mp[st.begin()->fi];

		if(l<q){
			ds.query(1,l+1,q,f);
		}
		// foru(i,l+1,q){
		// 	f=f*ls[i];
		// }

		printf("%lld\n",max({f[0],f[1],f[2]}));
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
	if(freopen("apple1.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("apple.in","r",stdin));
	if(freopen("apple.out","w",stdout));
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