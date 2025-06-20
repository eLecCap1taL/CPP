from tetris_env import TetrisEnv
import numpy as np


env = TetrisEnv()
obs = env.reset()
# print("初始状态：", obs)
env.render()

env.step(0)
env.step(1)
env.step(2)
env.step(3)
env.step(4)
env.step(5)
env.step(6)
env.step(7)

env.step(0)
env.step(1)

obs,r,done,x=env.step(8)
print("~~~~~~~")
env.render()
print(r)
