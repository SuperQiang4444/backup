---
title: Maven
toc: true
date: 2017-07-13 16:54:47
tags:
- Java基础
---
# 简介
Maven项目对象模型(POM)，可以通过一小段描述信息来管理项目的构建，报告和文档的软件项目管理工具。
<!--more-->
# 安装
去apache官方下载maven的压缩包(免安装)
解压到本地磁盘
配置环境变量
打开cmd输入mvn -v看是否成功
# 仓库类型
### 本地仓库
本地电脑上的仓库
当你第一次运行maven命令的时候，本地仓库就会创建默认路径为C:\Users\你的用户名\.m2
如果需要修改仓库路径需要在C:\apache-maven-3.5.0\conf\settings.xml的文件里添加配置如下
```
<localRepository>你想要的仓库路径</localRepository>
```
### 私服
局域网内的仓库，一般公司都有自己的私服
### 中心仓库
由apache官方维护
# maven常用命令
* clean：清理
将项目根目录下的target目录清理掉
* compile：编译
* test：单元测试
单元测试类命名要求：必须以Test结尾，如abcTest.java
* package：打包
* install：安装
解决本地多个项目共用1个jar包
打包到本地仓库
# maven项目生命周期
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fhiew13ighj30la05s0ud.jpg)
# eclipse中配置maven插件
打开顺序如下
window>>
preferences>>
maven>>
installations>>
add添加maven的安装路径
user settings配置本地仓库

构建索引
window>>
show view>>
maven repositories>>
local repositories右键构建索引
# 依赖范围
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fhnu0ngq03j30hq09s78e.jpg)
# 传递依赖冲突解决
### Maven自己的调节原则
第一声明者优先原则(谁先定义的就用谁的传递依赖)
路径近者优先原则(直接依赖高于传递依赖)
### 排除依赖
可以手动Exclude，排除jar包
### 版本锁定
<dependencyManagement> 标签下进行配置
# maven整合ssh
# 项目拆分
# 私服
