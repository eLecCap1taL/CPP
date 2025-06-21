import gym
from gym import spaces
import numpy as np
import math

class TetrisEnv(gym.Env):
    shapes=[
        np.array([
            [1]
        ],dtype=np.uint8),
        np.array([
            [1],
            [1]
        ],dtype=np.uint8),
        np.array([
            [1,1]
        ],dtype=np.uint8),
        np.array([
            [1],
            [1],
            [1]
        ],dtype=np.uint8),
        np.array([
            [1,1,1]
        ],dtype=np.uint8),
        np.array([
            [1,0],
            [1,1]
        ],dtype=np.uint8),
        np.array([
            [0,1],
            [1,1]
        ],dtype=np.uint8),
        np.array([
            [1,1],
            [1,0]
        ],dtype=np.uint8),
        np.array([
            [1,1],
            [0,1]
        ],dtype=np.uint8),
    ]
    def __init__(self,fix_seq = None):
        super().__init__()
        self.board = np.zeros((9, 9), dtype=np.uint8)
        self.current_shape = 0  # 每轮的方块编号（0–8）
        
        self.fix_seq = fix_seq

        self.observation_space = spaces.Dict({
            "board": spaces.Box(0, 1, shape=(9, 9), dtype=np.uint8),
            "shape": spaces.Discrete(9)  # 9种形状
        })
        
        self.action_space = spaces.Discrete(9)  # 放在哪一列
        self.step_count = 0

    def get_shape(self,rd):
        if self.fix_seq:
            return self.fix_seq[rd]
        else:
            return np.random.randint(9)

    def reset(self):
        self.board.fill(0)
        self.step_count = 0
        self.current_shape = self.get_shape(0)

        return {
            "board": self.board.copy(),
            "shape": self.current_shape
        }

    def compute_action_mask(self):
        mask = np.zeros(9, dtype=bool)
        for pos in range(9):
            W = len(self.shapes[self.current_shape][0])
            if pos + W-1 <= 8:
                mask[pos] = True       
        return mask

    class StateInfo(object):
        def __init__(self, height, be_coverd, dy_sum) -> None:
            self.height=height
            self.be_coverd=be_coverd
            self.avg_dy=dy_sum/8

    def calcStateInfo(self):
        hls = np.zeros((9),dtype=np.int8)

        height = 0
        for i in range(9):
            for j in range(9):
                if(self.board[j][i]):
                    if j > height:
                        height = j+1
                    hls[i]=j+1
        

        be_coverd=0
        for i in range(9):
            num=0
            for j in range(9):
                if(self.board[j][i]):
                    be_coverd+=num
                    num=0
                else:
                    num+=1

        dy_sum=0
        for i in range(8):
            dy_sum+=np.abs(hls[i+1]-hls[i])
        
        return self.StateInfo(height,be_coverd,dy_sum)
    
    def calcReward(self,old_state:StateInfo,place_state:StateInfo,line_cleared,mixin_factor):
        reward = 0

        d_height = place_state.height-old_state.height
        d_avg_dy = place_state.avg_dy-old_state.avg_dy
        d_be_coverd = place_state.be_coverd-old_state.be_coverd

        reward = 1
        reward += 8 * line_cleared
        reward += -0.9 * d_height
        reward += -0.3 * d_avg_dy
        reward += -0.5 * d_be_coverd
        reward += 1.0 * mixin_factor

        return reward


    def step(self, pos):
        self.step_count += 1
        
        # check endseq
        if self.fix_seq and self.step_count == len(self.fix_seq):
            return {
                "board": self.board.copy(),
                "shape": int(self.current_shape)
            }, 0, True, {}

        old_state=self.calcStateInfo()
        
        id=self.current_shape

        W=len(self.shapes[id][0])
        H=len(self.shapes[id])

        # check pos
        if pos+W-1>=9 :
            # out of range
            reward=-20
            return {
                "board": self.board.copy(),
                "shape": int(self.current_shape)
            }, reward, True, {}
        

        # now try to place

        # find a valid height
        place=-1
        for i in range(9-H+1):
            region=self.board[i:i+H,pos:pos+W].copy()
            if(np.any(region+self.shapes[id]>1)):
                # invalid
                place=-1
            else:
                if place == -1:
                    place=i
        
        # all-height invalid
        if place==-1:
            reward=-8
            return {
                "board": self.board.copy(),
                "shape": int(self.current_shape)
            }, reward, True, {}


        # print(place,W,H)

        # add shapes
        self.board[place:place+H,pos:pos+W]+=self.shapes[id]

        placed_state = self.calcStateInfo()

        # counter
        line_cleared=0
        mixin_factor=np.sum(self.board[place:place+H,pos:pos+W])/(H*W)

        # clear lines
        for times in range(H):
            # try to clear
            region = self.board[place]
            if sum(region)==9:
                line_cleared+=1
                up = self.board[place:9,0:9].copy()
                if place == 8:
                    self.board[place:9,0:9]-=up
                else:
                    U = self.board[place+1:9,0:9].copy()
                    self.board[place:9,0:9]-=up
                    self.board[place:8,0:9]+=U
            else:
                break

        
        # calc reward
                    
        reward = self.calcReward(old_state,placed_state,line_cleared,mixin_factor)

        self.current_shape = self.get_shape(self.step_count)  # 下一块

        return {
            "board": self.board.copy(),
            "shape": int(self.current_shape)
        }, reward, False, {}

    def render(self, mode="human"):
        print('\n'.join(''.join('#' if x else '·' for x in row) for row in reversed(self.board)))

