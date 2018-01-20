---
title: CSS学习笔记
date: 2017-03-17 15:16:45
tags:
- CSS
- Web
toc: true
---

CSS和HTML结合的4种方式
CSS三种基本选择器
CSS的扩展选择器
CSS的盒子模型
CSS的布局的漂浮
CSS的布局的定位
<!--more-->
# CSS和HTML结合的4种方式
	1.在每个html标签上面都有一个属性style，把css和html结合在一起
		<div style="background-color:red;">
	2.使用html的一个标签实现<style>标签，写在head里面
		<style type="text/css">
			css代码;
		</style>
	3.在style标签里面 使用语句
		<style type="text/css">
			@import url(css文件的路径)；
		</style>
	4.使用头标签link,引入外部css文件
		<link rel="stylesheet" type="text/css" href="css文件的路径" />
# CSS基本选择器
	1.标签选择器
		div {
			background-color:gray;
			color:white;
		}
	2.class选择器
		<div class="haha">aaaa</div>
		.haha {
			background-color:gray;
		}
	3.id选择器
		<div id="hehe">bbbb</div>
		#hehe {
			background-color:gray;
		}
	优先级
		style > id选择器 > class选择器 > 标签选择器

# CSS的扩展选择器
	1.关联选择器
		<div><p>wwwww</p></div>
		div p {
			background-color:orange;
		}
		//设置div里面的p标签
	2.组合选择器
		<div>1111</div>
		<p>2222</p>
		div,p {
			background-color:blue;
		}
		//同时设置div和p标签
	3.伪元素选择器
		//CSS里面提供了一些定义好的元素，可以直接使用
		//比如超链接
		:link :hover :active :visited
# CSS的盒子模型
	//布局的时候把数据装进（div）
	1.边框
		border
		border-top
		border-bottom
		border-left
		border-right
	2.内边距
		padding(上下左右)
	3.外边距
		margin（上下左右）
# CSS的布局的漂浮
	float
		left : 文本流向对象的右边
		right : 文本流向对象的左边
# CSS的布局的定位
	position
		absolute : 将对象从文档流中拖出
			可以用top、bottom等属性定位
		relative : 不会把对象从文档流中拖出
			可以用top、bottom等属性定位
