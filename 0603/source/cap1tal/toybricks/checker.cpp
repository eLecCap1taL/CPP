#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
typedef long long ll;

int main(int argc, char** argv) {
	registerTestlibCmd(argc,argv);
	// registerTestlibChecker(argc, argv);
	int n = inf.readInt();
	for (int _ = 0; _ < n; ++_) {
		inf.readInt();
	}
	int o1 = inf.readInt(), o2 = inf.readInt();
	ll f1 = ouf.readLong();
	ll f2 = ouf.readLong();
	ll f3 = ouf.readLong();
	ll g1 = ans.readLong();
	ll g2 = ans.readLong();
	ll g3 = ans.readLong();
	if (f1 != g1) {
		quitf(_wa, "f(1) is wrong.");
	} else if (f2 != g2) {
		quitp(o1, "f(2) is wrong.");
	} else if (f3 != g3) {
		quitp(o2, "f(3) is wrong.");
	} else {
		quitf(_ok, "Accepted.");
	}
	return 0;
}
