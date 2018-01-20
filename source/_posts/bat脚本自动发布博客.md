---
title: bat脚本自动发布hexo博客
toc: true
date: 2017-12-02 13:44:42
tags:
- 编程
---
因为hexo博客发布就是hexo clean,hexo g,hexo d 3条语句，所以为了省事就百度bat脚本写了一个一键发布的脚本。
<!--more-->
以下是代码部分，供大家学习分享
### bat脚本
```
@echo off
rem 下面2行表示进入到hexo博客根目录。
C:
cd \Users\444\hexo-demo\
rem 注意最后一行必须连写，因为执行hexo就不会返回原来的cmd，所以在hexo下执行完所有命令。
echo Job start!
hexo clean && hexo g && hexo d && echo Job is done! && pause
```
### windows下设置计划任务
```
schtasks /create /tn "My App" /tr C:\\Users\\444\\hexo-demo\\DeployBlog.bat /sc daily /st 00:00 
```
任务名称为My App,每天0点执行1次
### pm2
pm2在windows下会弹出dos框，所以windows系统目前自动发布不考虑。