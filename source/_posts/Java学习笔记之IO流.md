---
title: Java学习笔记之IO流
date: 2017-03-13 16:22:23
tags:
- Java基础
toc: true
---
IO流
<!--more-->
# IO流(掌握)
	(1)IO用于在设备间进行数据传输的操作	
	(2)分类：
		A:流向
			输入流	读取数据
			输出流	写出数据
		B:数据类型
			字节流	
					字节输入流
					字节输出流
			字符流
					字符输入流
					字符输出流
		注意：
			a:如果我们没有明确说明按照什么分，默认按照数据类型分。
			b:除非文件用windows自带的记事本打开我们能够读懂，才采用字符流，否则建议使用字节流。
	(3)FileOutputStream写出数据
		A:操作步骤
			a:创建字节输出流对象
			b:调用write()方法
			c:释放资源
			
		B:代码体现：
			FileOutputStream fos = new FileOutputStream("fos.txt");
			
			fos.write("hello".getBytes());
			
			fos.close();
			
		C:要注意的问题?
			a:创建字节输出流对象做了几件事情?
			b:为什么要close()?
			c:如何实现数据的换行?
			d:如何实现数据的追加写入?
	(4)FileInputStream读取数据
		A:操作步骤
			a:创建字节输入流对象
			b:调用read()方法
			c:释放资源
			
		B:代码体现：
			FileInputStream fis = new FileInputStream("fos.txt");
			
			//方式1
			int by = 0;
			while((by=fis.read())!=-1) {
				System.out.print((char)by);
			}
			
			//方式2
			byte[] bys = new byte[1024];
			int len = 0;
			while((len=fis.read(bys))!=-1) {
				System.out.print(new String(bys,0,len));
			}
			
			fis.close();
	(5)案例：2种实现
		A:复制文本文件
		B:复制图片
		C:复制视频
	(6)字节缓冲区流
		A:BufferedOutputStream
		B:BufferedInputStream
	(7)案例：4种实现
		A:复制文本文件
		B:复制图片
		C:复制视频
		
# IO流分类
		字节流：
			InputStream
				FileInputStream
				BufferedInputStream
			OutputStream
				FileOutputStream
				BufferedOutputStream
		
		字符流：
			Reader
				FileReader
				BufferedReader
			Writer
				FileWriter
				BufferedWriter