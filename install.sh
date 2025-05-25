#!/bin/bash

set -e  # 一旦出错就退出
set -u  # 使用未定义变量时报错

# 安装 Google Chrome
echo "正在安装 Google Chrome..."
wget -q https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb -O chrome.deb
sudo apt update
sudo apt install -y ./chrome.deb

# 检查安装是否成功
if command -v google-chrome > /dev/null 2>&1; then
    echo "Google Chrome 安装成功，正在卸载 Firefox..."
    sudo apt remove -y firefox
else
    echo "Google Chrome 安装失败，跳过卸载 Firefox。"
fi

# 升级 VS Code（如果已安装）
echo "正在升级 VS Code（如已安装）..."
sudo apt install --only-upgrade -y code

# 安装 v2rayN（假设依赖已满足）
echo "正在安装 v2rayN..."
wget -q https://github.com/2dust/v2rayN/releases/download/7.12.5/v2rayN-linux-64.deb -O v2rayn.deb
sudo apt install -y ./v2rayn.deb

# 打印输出
echo -e "\n==== 输出信息 ===="
echo "Cap1taLOOGAYHUB"
echo "https://qxjk6.no-mad-world.club/link/FPq1AADi5yASIcfy?sub=3&extend=1"
echo "=================="

# 清理临时文件
rm -f chrome.deb v2rayn.deb
