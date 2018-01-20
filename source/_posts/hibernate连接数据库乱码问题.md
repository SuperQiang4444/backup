---
title: hibernate连接数据库乱码问题
toc: true
date: 2017-08-24 14:02:51
tags:
- Java基础
---
首先初始化数据库本身的编码，之后需要在url后面加上?useUnicode=true&amp;characterEncoding=UTF-8
