#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

template<class U0, class U1, class S0, U0 P>
struct Static_Modint {
private:
	static_assert((P >> (sizeof(U0) * 8 - 1)) == 0, "'Mod' must less than max(U0)/2");
	static constexpr U0 Mod = P;
	U0 x;
	template<class T>
	static constexpr unsigned SafeMod(T x) {
		if constexpr (std::is_unsigned<T>::value) {
			x %= static_cast<T>(Mod);
			return static_cast<U0>(x);
		} else {
			if ((x %= static_cast<T>(Mod)) < 0)
				x += static_cast<T>(Mod);
			return static_cast<U0>(x);
		}
	}
public:
	constexpr Static_Modint(): x(static_cast<U0>(0)) {}
	template<class T>
	constexpr Static_Modint(T _x): x(SafeMod(_x)) {}
	static constexpr Static_Modint raw(U0 _x) noexcept {
		Static_Modint x;
		return x.x = _x, x;
	}
	static constexpr U0 GetMod() {
		return Mod;
	}
	template<class T>
	explicit constexpr operator T() const {
		return static_cast<T>(x);
	}
	constexpr Static_Modint &operator += (const Static_Modint &rhs) {
		x = ((x += rhs.x) >= Mod) ? (x - Mod) : x;
		return *this;
	}
	constexpr Static_Modint &operator -= (const Static_Modint &rhs) {
		x = ((x -= rhs.x) >= Mod) ? (x + Mod) : x;
		return *this;
	}
	constexpr Static_Modint &operator *= (const Static_Modint &rhs) {
		x = (static_cast<U1>(x) * rhs.x) % Mod;
		return *this;
	}
	constexpr Static_Modint &operator /= (const Static_Modint &rhs) {
		return (*this *= rhs.inv());
	}
	friend constexpr Static_Modint fma(const Static_Modint &a, const Static_Modint &b, const Static_Modint &c) {
		return raw((static_cast<U1>(a.x) * b.x + c.x) % Mod);
	}
	friend constexpr Static_Modint fam(const Static_Modint &a, const Static_Modint &b, const Static_Modint &c) {
		return raw((a.x + static_cast<U1>(b.x) * c.x) % Mod);
	}
	friend constexpr Static_Modint fms(const Static_Modint &a, const Static_Modint &b, const Static_Modint &c) {
		return raw((static_cast<U1>(a.x) * b.x + Mod - c.x) % Mod);
	}
	friend constexpr Static_Modint fsm(const Static_Modint &a, const Static_Modint &b, const Static_Modint &c) {
		return raw((a.x + static_cast<U1>(Mod - b.x) * c.x) % Mod);
	}
	constexpr Static_Modint div_2() const {
		return raw(((x & 1) ? (x + Mod) : x) >> 1);
	}
	constexpr Static_Modint inv() const {
		U0 a = Mod, b = x; S0 y = 0, z = 1;
		while (b) {
			const U0 q = a / b;
			const U0 c = a - q * b;
			a = b, b = c;
			const S0 w = y - static_cast<S0>(q) * z;
			y = z, z = w;
		}
		return raw(y < 0 ? y + Mod : y);
	}
	friend constexpr Static_Modint operator + (const Static_Modint &x) {
		return x;
	}
	friend constexpr Static_Modint operator - (Static_Modint x) {
		x.x = x.x ? (Mod - x.x) : 0U;
		return x;
	}
	constexpr Static_Modint &operator ++ () {
		x = (x + 1 == Mod) ? 0U : (x + 1);
		return *this;
	}
	constexpr Static_Modint &operator -- () {
		x = (x == 0U) ? (Mod - 1) : (x - 1);
		return *this;
	}
	constexpr Static_Modint operator ++ (int) {
		Static_Modint tmp = (*this);
		return ++ (*this), tmp;
	}
	constexpr Static_Modint operator -- (int) {
		Static_Modint tmp = (*this);
		return -- (*this), tmp;
	}
	friend constexpr Static_Modint operator + (Static_Modint x, const Static_Modint &y) {
		return x += y;
	}
	friend constexpr Static_Modint operator - (Static_Modint x, const Static_Modint &y) {
		return x -= y;
	}
	friend constexpr Static_Modint operator * (Static_Modint x, const Static_Modint &y) {
		return x *= y;
	}
	friend constexpr Static_Modint operator / (Static_Modint x, const Static_Modint &y) {
		return x /= y;
	}
	constexpr Static_Modint Pow(long long y) const {
		if (y < 0) return inv().Pow(- y);
		Static_Modint x = *this, ans;
		ans.x = static_cast<U0>(1);
		for (; y; y >>= 1, x *= x)
			if (y & 1) ans *= x;
		return ans;
	}
	friend constexpr std::istream& operator >> (std::istream& is, Static_Modint &x) {
		return is >> x.x;
	}
	friend constexpr std::ostream& operator << (std::ostream& os, const Static_Modint &x) {
		return os << x.x;
	}
	friend constexpr bool operator == (const Static_Modint &x, const Static_Modint &y) {
		return x.x == y.x;
	}
	friend constexpr bool operator != (const Static_Modint &x, const Static_Modint &y) {
		return x.x != y.x;
	}
	friend constexpr bool operator <= (const Static_Modint &x, const Static_Modint &y) {
		return x.x <= y.x;
	}
	friend constexpr bool operator >= (const Static_Modint &x, const Static_Modint &y) {
		return x.x >= y.x;
	}
	friend constexpr bool operator < (const Static_Modint &x, const Static_Modint &y) {
		return x.x < y.x;
	}
	friend constexpr bool operator > (const Static_Modint &x, const Static_Modint &y) {
		return x.x > y.x;
	}
};
template<u32 P>
using sm32 = Static_Modint<u32, u64, int, P>;
template<u64 P>
using sm64 = Static_Modint<u64, u128, i64, P>;

constexpr u32 Mod = 1E9 + 7;
using Z = sm32<Mod>;

struct Combination {
	int N;
	std::vector<Z> _fac, _ifac, _inv;
	
	Combination(int n): N(0), _fac{1}, _ifac{1}, _inv{0} { Init(n); }
	Combination(): N(0), _fac{1}, _ifac{1}, _inv{0} {}
	void Init(int n) {
		if (n <= N) return;
		_fac.resize(n + 1), _ifac.resize(n + 1), _inv.resize(n + 1);
		for (int i = N + 1; i <= n; i ++) _fac[i] = _fac[i - 1] * i;
		_ifac[n] = _fac[n].inv();
		for (int i = n; i > N; i --) _ifac[i - 1] = _ifac[i] * i,
																 _inv[i] = _ifac[i] * _fac[i - 1];
		N = n; return;
	}
	Z fac(int n) {
		if (n > N) Init(n << 1);
		return _fac[n];
	}
	Z ifac(int n) {
		if (n > N) Init(n << 1);
		return _ifac[n];
	}
	Z inv(int n) {
		if (n > N) Init(n << 1);
		return _inv[n];
	}
	Z binom(int n, int m) {
		if (n < m || n < 0 || m < 0) return 0;
		return fac(n) * ifac(m) * ifac(n - m);
	}
} comb;

constexpr Z inv100 = Z(100).inv();
using namespace std;
// x = 0, 1, 2, ..., n - 1
std::vector<Z> Lagrange(std::vector<Z> y) {
	if (y.empty()) return y;
	const int n = (int)y.size();
	std::vector<Z> f(n + 1), a(n), coef, g(n);
	
	for (int i = 0; i < n; i ++) {
		Z res = y[i] * comb.ifac(i) * comb.ifac(n - i - 1);
		((n - i - 1) & 1) ? a[i] = - res : a[i] = res;
	}

	
	f[0] = 1;
	for (int i = 0; i < n; i ++) {
		f[i + 1] = 0;
		for (int j = i + 1; j; j --)
			f[j] = f[j - 1] - i * f[j];
		f[0] = - f[0] * i;
	}
    for(auto x:f){
        cout<<x<<' ';
    }
    std::cout<<endl;
	
	coef = f, coef.erase(coef.begin());
	for (auto &x : coef) x *= a[0];
	for (int i = 1; i < n; i ++) {
		g[0] = - comb.inv(i) * f[0];
		for (int j = 1; j < n; j ++)
			g[j] = comb.inv(i) * (g[j - 1] - f[j]);
		for (int j = 0; j < n; j ++)
			coef[j] += a[i] * g[j];
	}
	
	return coef;
}

int main() {
    freopen("plant1.in","r",stdin);

	int T;
	std::cin >> T;
	
	while (T --) {
		int n, m;
		std::cin >> n >> m;
		
		std::vector<Z> p(m + 1);
		for (int i = 0; i <= m; i ++) {
			std::cin >> p[i];
			p[i] *= inv100;
		}
		
		std::vector<Z> sum(m + 2);
		sum[m + 1] = p[0];
		for (int i = m; i > 0; i --) {
			sum[i] = sum[i + 1] + p[i];
		}
		std::vector<std::vector<Z>> pw(m + 2, std::vector<Z>(n * n + 1));
		for (int i = 1; i <= m + 1; i ++) {
			pw[i][0] = 1;
			for (int j = 1; j <= n * n; j ++) {
				pw[i][j] = pw[i][j - 1] * sum[i];
			}
		}
		
		const int M = m * (n - 1);
		
		std::vector<Z> ans(M + 1);
		for (int X = 0; X <= M; X ++) {
			std::vector<Z> f(n + 1);
			Z pwX = 1;
			f[1] = 1;
			for (int k = 1; k <= m; k ++) {
				pwX *= X;
				auto g = f;
				for (int i = 1; i <= n; i ++) {
					for (int j = 1; j < i; j ++) {
						const Z coef = comb.binom(i - 1, j - 1) * pw[k][(i - j) * j];
						g[i] += coef * f[j] * g[i - j] * pwX;
					}
				}
				f = g;
				for (int i = 1; i <= n; i ++) {
					for (int j = 1; j < i; j ++) {
						const Z coef = comb.binom(i - 1, j - 1) * pw[k + 1][j * (i - j)];
						f[i] -= coef * f[j] * g[i - j] * pwX;
                        // if(X==2){
                        //     std::cout<<i<<'~'<<j<<' '<<coef * f[j] * g[i - j] * pwX<<std::endl;
                        // }
					}
				}

                // if(X==2){
                //     for(int o=1;o<=n;o++){
                //         std::cout<<f[o]<<' ';
                //     }
                //     std::cout<<'\n';
                // }
			}
			ans[X] = f[n];
		}
		
		auto coef = Lagrange(ans);
		for (int s = n - 1; s <= M; s ++) {
			std::cout << coef[s] << ' ';
		}
		
		std::cout << '\n';
		// for (int s = 0; s <= M; s ++) {
		// 	std::cout << ans[s] << ' ';
		// }
		
		// std::cout << '\n';
        // exit(0);
	}
	
	return 0;
}