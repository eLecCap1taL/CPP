#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	// #define MULTITEST
	
	#ifndef CPEDITOR
	if(freopen("game1.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("game.in","r",stdin));
	if(freopen("game.out","w",stdout));
	#endif
	#endif
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    std::vector<int> a(n);
    std::vector<int> b_sorted(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        b_sorted[i] = b[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // 对 A 和 B 的牌进行排序
    std::sort(a.begin(), a.end());
    std::sort(b_sorted.begin(), b_sorted.end());

    // --- 步骤 1: 计算最大胜利次数 (按两种赢法分类) ---
    int wins1 = 0; // A 的最大牌 vs B 的最大牌
    int wins2 = 0; // A 的最小牌 vs B 的最小牌

    int a_min_ptr = 0, a_max_ptr = n - 1;
    int b_min_ptr = 0, b_max_ptr = n - 1;

    // 模拟田忌赛马，计算两种胜利类型的数量
    for (int i = 0; i < n; ++i) {
        if (a[a_max_ptr] > b_sorted[b_max_ptr]) {
            wins1++;
            a_max_ptr--;
            b_max_ptr--;
        } else if (a[a_min_ptr] > b_sorted[b_min_ptr]) {
            wins2++;
            a_min_ptr++;
            b_min_ptr++;
        } else {
            // 策略性牺牲: A的最小牌对阵B的最大牌
            a_min_ptr++;
            b_max_ptr--;
        }
    }

    // --- 步骤 2: 构造字典序最大的解 ---
    std::vector<int> result(n);
    a_min_ptr = 0;
    a_max_ptr = n - 1;

    for (int i = 0; i < n; ++i) {
        // 优先用最大的牌赢 (上驷对决)
        if (wins1 > 0 && a[a_max_ptr] > b[i]) {
            result[i] = a[a_max_ptr];
            a_max_ptr--;
            wins1--;
        } 
        // 其次用最小的牌赢 (下驷对决)
        else if (wins2 > 0 && a[a_min_ptr] > b[i]) {
            result[i] = a[a_min_ptr];
            a_min_ptr++;
            wins2--;
        } 
        // 必须输掉本局，牺牲最弱的牌以保留实力
        else {
            result[i] = a[a_min_ptr];
            a_min_ptr++;
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}