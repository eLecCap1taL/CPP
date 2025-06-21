from stable_baselines3 import DQN
from tetris_env import TetrisEnv
import time

def work(x):
    return int(x)-1

shape_ids=None

# 读取固定形状序列
with open("../block2.in") as f:
    lines = f.read().splitlines()
    n = int(lines[0])
    shape_ids = list(map(work, lines[1:n+1]))

# print(shape_ids)
# exit(0)

# 初始化模型与环境（使用固定序列）
model = DQN.load("best_model")
env = TetrisEnv(shape_ids)

obs = env.reset()
done = False
total_reward = 0
rounds = 0

while not done:
    print('\n')
    action, _ = model.predict(obs, deterministic=True)
    obs, reward, done, _ = env.step(action)
    total_reward += reward
    env.render()
    print(f"Round {rounds},Reward: {reward}")
    rounds += 1
    time.sleep(0.02)

print(f"Score: {total_reward}, Rounds: {rounds}")
