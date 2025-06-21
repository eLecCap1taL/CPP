# train.py
import gym
from tetris_env import TetrisEnv
from stable_baselines3 import DQN

from stable_baselines3.dqn.policies import DQNPolicy
from stable_baselines3.common.callbacks import EvalCallback
import torch.nn.functional as F
import torch

class MaskedDQNPolicy(DQNPolicy):
    def forward(self, obs, deterministic=True):
        q_values = self.q_net(obs)

        # 如果环境传了 mask，就应用它
        action_masks = obs.get("action_mask", None)
        if action_masks is not None:
            # 设置非法动作的 Q 值为极小
            mask = ~action_masks.bool()
            q_values = q_values.masked_fill(mask, -1e10)

        actions = q_values.argmax(dim=1)
        return actions, None


def main():
    shape_ids=None

    # 读取固定形状序列
    def work(x):
        return int(x)-1
    
    # with open("../block1.in") as f:
    #     lines = f.read().splitlines()
    #     n = int(lines[0])
    #     shape_ids = list(map(work, lines[1:n+1]))
        
    env = TetrisEnv(shape_ids)
    env.reset()
    model = DQN.load("tetris_dqn",
            env=env,
            # exploration_fraction=1.25,
            # exploration_final_eps=0.05,      
            # exploration_initial_eps=0.2,
            tensorboard_log="./tetris_tensorboard/"
    )

    eval_env = TetrisEnv()  
    eval_env.reset()

    eval_callback = EvalCallback(
        eval_env,
        best_model_save_path='./logs/best_model',
        log_path='./logs/results',
        eval_freq=10000,     
        n_eval_episodes=5,   
        deterministic=True,  
    )

    model.learn(total_timesteps=500000,reset_num_timesteps=False,log_interval=10,callback=eval_callback)
    model.save("tetris_dqn_conti")

if __name__ == "__main__":
    main()
