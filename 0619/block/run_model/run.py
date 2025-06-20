from stable_baselines3 import DQN
from tetris_env import TetrisEnv
import time

# with open("test.txt") as f:
#     lines = f.read().splitlines()
#     n = int(lines[0])
#     shape_ids = list(map(int, lines[1:n+1]))

model = DQN.load("best_model")

env = TetrisEnv()
obs = env.reset()
done = False
total_reward = 0

rd=0

while not done:
    action, _ = model.predict(obs, deterministic=True)
    obs, reward, done, _ = env.step(action)
    total_reward += reward
    env.render()          
    print(reward)
    rd+=1
    time.sleep(0.2)     

print(f"Score：{total_reward}, Round={rd}")
