#!/usr/bin/env python3
import sys
import random
from collections import deque

def generate_grid(n, ratio=0.5, lookahead_depth=5, straight_bias=2.0):
    """
    生成一个 (2n+1)x(2n+1) 的网格，路径：
    - 中心点为 (n, n)
    - 第一步固定向上
    - 随机DFS结合局部BFS启发式和“直行偏好”：
      对每个可选邻居进行深度限制 BFS，计算子区域可访问比率；
      对保持同一方向的候选加上 straight_bias 权重；
      最终权重 = 出口数 + 子区域可访问比率 + (保持直行? bias : 0)
    - 持续移动直到访问数 ≥ ratio * 总格数 或 无路可走
    - 路径上每格标记箭头，停留点标记 'G'
    """
    size = 2 * n + 1
    total_cells = size * size
    center = (n, n)

    # 方向元组：delta_i, delta_j, symbol
    dirs = [(-1, 0, '^'), (1, 0, 'v'), (0, -1, '<'), (0, 1, '>')]

    visited = {center}
    grid = [['.' for _ in range(size)] for _ in range(size)]

    # 初始化：第一步必向上
    ci, cj = center
    ni, nj = ci - 1, cj
    if ni < 0:
        raise RuntimeError("无法向上移动：网格太小")
    grid[ci][cj] = '^'
    visited.add((ni, nj))
    ci, cj = ni, nj
    last_sym = '^'

    def lookahead_score(si, sj):
        """
        深度受限 BFS 计算未访问格子可达比率
        """
        seen = {(si, sj)}
        q = deque([((si, sj), 0)])
        reachable = 0
        max_nodes = 0
        while q:
            (x, y), d = q.popleft()
            if d > 0:
                if (x, y) not in visited:
                    reachable += 1
                max_nodes += 1
            if d < lookahead_depth:
                for ddi, ddj, _ in dirs:
                    xi, xj = x + ddi, y + ddj
                    if 0 <= xi < size and 0 <= xj < size and (xi, xj) not in seen:
                        seen.add((xi, xj))
                        q.append(((xi, xj), d + 1))
        return (reachable / max_nodes) if max_nodes > 0 else 0.0

    # 主循环
    while len(visited) < int(total_cells * ratio):
        candidates = []
        # 遍历所有可能的方向
        for di, dj, sym in dirs:
            ti, tj = ci + di, cj + dj
            if 0 <= ti < size and 0 <= tj < size and (ti, tj) not in visited:
                # 基础出口数
                exit_cnt = sum(
                    1 for ddi, ddj, _ in dirs
                    if 0 <= ti+ddi < size and 0 <= tj+ddj < size and (ti+ddi, tj+ddj) not in visited
                )
                # 局部可达比率
                score = lookahead_score(ti, tj)
                # 直行偏好
                bias = straight_bias if sym == last_sym else 0.0
                weight = exit_cnt + score + bias
                candidates.append((ti, tj, sym, weight))
        if not candidates:
            break
        # 加权随机选择
        total_w = sum(w for *_, w in candidates)
        r = random.uniform(0, total_w)
        acc = 0
        for ti, tj, sym, w in candidates:
            acc += w
            if r <= acc:
                chosen = (ti, tj, sym)
                break
        ti, tj, sym = chosen

        # 移动并标记
        grid[ci][cj] = sym
        visited.add((ti, tj))
        ci, cj = ti, tj
        last_sym = sym

    # 最后标记宝藏
    grid[ci][cj] = 'G'
    return grid


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 gen_treasure_dfs.py <n> [ratio] [depth] [bias]")
        sys.exit(1)
    n = int(sys.argv[1])
    ratio = float(sys.argv[2]) if len(sys.argv) >= 3 else 0.5
    depth = int(sys.argv[3]) if len(sys.argv) >= 4 else 5
    bias = float(sys.argv[4]) if len(sys.argv) >= 5 else 2.0

    grid = generate_grid(n, ratio, lookahead_depth=depth, straight_bias=bias)
    print(n)
    for row in grid:
        print(''.join(row))

if __name__ == "__main__":
    main()
