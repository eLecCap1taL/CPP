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
    def __init__(self):
        super().__init__()
        self.board = np.zeros((9, 9), dtype=np.uint8)
        self.current_shape = 0  # 每轮的方块编号（0–8）
        
        self.observation_space = spaces.Dict({
            "board": spaces.Box(0, 1, shape=(9, 9), dtype=np.uint8),
            "shape": spaces.Discrete(9)  # 9种形状
        })
        
        self.action_space = spaces.Discrete(9)  # 放在哪一列
        self.step_count = 0

    def reset(self):
        self.board.fill(0)
        # self.step_count = 0
        self.current_shape = np.random.randint(9)
        # self.current_shape = 3
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


    def step(self, pos):
        self.step_count += 1
        
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

        lst=-1
        for i in range(9-H+1):
            region=self.board[i:i+H,pos:pos+W].copy()
            if(np.any(region+self.shapes[id]>1)):
                # invalid
                lst=-1
            else:
                if lst == -1:
                    lst=i
        
        if lst==-1:
            # all invalid
            reward=-5
            return {
                "board": self.board.copy(),
                "shape": int(self.current_shape)
            }, reward, True, {}


        # print(lst,W,H)

        self.board[lst:lst+H,pos:pos+W]+=self.shapes[id]

        cnt=0

        for times in range(H):
            # try to clear
            region = self.board[lst]
            if sum(region)==9:
                cnt+=1
                up = self.board[lst:9,0:9].copy()
                if lst == 8:
                    self.board[lst:9,0:9]-=up
                else:
                    U = self.board[lst+1:9,0:9].copy()
                    self.board[lst:9,0:9]-=up
                    self.board[lst:8,0:9]+=U
            else:
                break

        cv=0
        mxh=0

        hs=np.zeros((9),dtype=np.uint8)

        for i in range(9):
            num=0
            for j in range(9):
                if(self.board[j][i]):
                    cv+=num
                    num=0
                    if(j>mxh):
                        mxh=j
                    hs[i]=j+1
                else:
                    num+=1
        
        avg=sum(hs)/9
        fc=0
        for x in hs:
            fc+=(x-avg)*(x-avg)
        fc/=9
        # fc=math.sqrt(fc)
        fc=np.sqrt(fc)
        
        reward = 1+cnt*6
        reward += -0.6*cv
        reward += 0.3*(4-mxh)
        reward += 0.5*(2-fc)

        self.current_shape = np.random.randint(9)  # 下一块
        # self.current_shape = 3
        
        # info = {"action_mask": self.compute_action_mask()}

        return {
            "board": self.board.copy(),
            "shape": int(self.current_shape)
        }, reward, False, {}

    def render(self, mode="human"):
        print('\n'.join(''.join('#' if x else '·' for x in row) for row in reversed(self.board)))

