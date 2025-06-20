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
    env = TetrisEnv()
    env.reset()
    model = DQN(
        policy="MultiInputPolicy",
        env=env,
        learning_rate=1e-3,
        buffer_size=50000,
        learning_starts=1000,
        batch_size=32,
        gamma=0.99,
        exploration_fraction=0.1,
        exploration_final_eps=0.05,      
        exploration_initial_eps=1.0,     # 一开始ε=1，完全随机
        target_update_interval=500,
        verbose=1,
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

    model.learn(total_timesteps=1000000,log_interval=10,callback=eval_callback)
    model.save("tetris_dqn")

if __name__ == "__main__":
    main()
