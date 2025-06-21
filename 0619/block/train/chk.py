from tetris_env import TetrisEnv
import numpy as np


env = TetrisEnv()
obs = env.reset()
# print("初始状态：", obs)
env.render()

obs,r,done,x=env.step(0)

print(r)
