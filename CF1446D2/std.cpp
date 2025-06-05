#include<cstdio>
#include<cmath>
const int N=200000;
int t[N<<1|1],tmp[N<<1|1],a[N];
inline int read() {
	register int x=0,f=1;register char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
	return x*f; 
}
inline int max(const int &x,const int &y) {return x>y? x:y;}
int main() {
	int n=read(),bound=sqrt(n);
	for(register int i=1;i<=n;++i) {a[i]=read(); ++t[a[i]];}
	int mode=0,mx=0;
	for(register int i=1;i<=n;++i) if(t[mode]<t[i]) mode=i;
	for(register int x=1;x<=n;++x) {
		if(t[x]>bound) {
			if(x==mode) continue;
			int cnt=0;tmp[N]=0;
			for(register int i=1;i<=n;++i) {
				if(a[i]==mode) {++cnt;}
				else if(a[i]==x) {--cnt;}
				if(tmp[cnt+N]||cnt==0) {mx=max(mx,i-tmp[cnt+N]);}
				else {tmp[cnt+N]=i;}
			}
			cnt=0;
			for(register int i=1;i<=n;++i) {
				if(a[i]==mode) {++cnt;}
				else if(a[i]==x) {--cnt;}
				tmp[cnt+N]=0;
			}
		}
	} 
	for(register int x=1;x<=bound;++x) {
		int L=1,cnt=0;
		for(register int i=1;i<=n;++i) tmp[i]=0;
		for(register int i=1;i<=n;++i) {
			++tmp[a[i]];
			if(tmp[a[i]]==x) ++cnt;
			while(L<=i&&tmp[a[i]]>x) {
				if(tmp[a[L]]==x) --cnt;
				--tmp[a[L]]; 
				++L;
			}
			if(cnt>=2) mx=max(mx,i-L+1);
		} 
	}
	printf("%d\n",mx);
	return 0; 
}