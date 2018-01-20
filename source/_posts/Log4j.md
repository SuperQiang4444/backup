---
title: Log4j
toc: true
date: 2017-06-29 12:04:32
tags:
- Java基础
---
# 日志的原理
通过一个标志位debug控制输出，这是的输出便是可控的，但只有两个级别：输出与不输出。
debug为false时不输出，debug为true时输出。
<!--more-->
# Logging，Log4j和commons-logging的关系
Logging为JDK1.4自带的一套日志系统
Log4j是Apache的一个开源项目
commons-logging用来选择是使用Logging还是Log4j，如果有Log4j就把输出原封不动交给Log4j，如果没有，将输出转化为JDK Logging的输出。
# Log4j简介
Log4j是Apache的一个开源项目，通过使用Log4j，我们可以控制日志信息输送的目的地是控制台、文件、GUI组件，甚至是套接口服务器、NT的事件记录器、UNIX Syslog守护进程等；我们也可以控制每一条日志的输出格式；通过定义每一条日志信息的级别，我们能够更加细致地控制日志的生成过程。最令人感兴趣的就是，这些可以通过一个配置文件来灵活地进行配置，而不需要修改应用的代码。
# Log4j.properties例子
```
### direct log messages to stdout ###
log4j.appender.stdout=org.apache.log4j.ConsoleAppender
log4j.appender.stdout.Target=System.err
log4j.appender.stdout.layout=org.apache.log4j.PatternLayout
log4j.appender.stdout.layout.ConversionPattern=%d{ABSOLUTE} %5p %c{1}:%L - %m%n

### direct messages to file mylog.log ###
log4j.appender.file=org.apache.log4j.FileAppender
log4j.appender.file.File=c:\mylog.log
log4j.appender.file.layout=org.apache.log4j.PatternLayout
log4j.appender.file.layout.ConversionPattern=%d{ABSOLUTE} %5p %c{1}:%L - %m%n

### set log levels - for more verbose logging change 'info' to 'debug' ###
log4j.rootLogger=info, stdout
```
具体配置有很多，等以后用到在具体学习。