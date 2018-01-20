---
title: Java学习笔记之IO流2
date: 2017-03-14 16:49:11
tags:
- Java基础
toc: true
---


字符流,IO流小结,数据操作流,内存操作流,打印流,标准输入输出流,随机访问流,合并流,序列化流,Properties,NIO
<!--more-->
# 1:字符流(掌握)
	(1)字节流操作中文数据不是特别的方便，所以就出现了转换流。
	   转换流的作用就是把字节流转换字符流来使用。
	(2)转换流其实是一个字符流
		字符流 = 字节流 + 编码表
	(3)编码表
		A:就是由字符和对应的数值组成的一张表
		B:常见的编码表
			ASCII
			ISO-8859-1
			GB2312
			GBK
			GB18030
			UTF-8
		C:字符串中的编码问题
			编码
				String -- byte[]
			解码
				byte[] -- String
	(4)IO流中的编码问题
		A:OutputStreamWriter
			OutputStreamWriter(OutputStream os):默认编码，GBK
			OutputStreamWriter(OutputStream os,String charsetName):指定编码。
		B:InputStreamReader
			InputStreamReader(InputStream is):默认编码，GBK
			InputStreamReader(InputStream is,String charsetName):指定编码
		C:编码问题其实很简单
			编码只要一致即可
	(5)字符流
		Reader
			|--InputStreamReader
				|--FileReader
			|--BufferedReader
		Writer
			|--OutputStreamWriter
				|--FileWriter
			|--BufferedWriter

# 2:IO流小结(掌握)
	IO流
		|--字节流
			|--字节输入流
				InputStream
					int read():一次读取一个字节
					int read(byte[] bys):一次读取一个字节数组
				
					|--FileInputStream
					|--BufferedInputStream
			|--字节输出流
				OutputStream
					void write(int by):一次写一个字节
					void write(byte[] bys,int index,int len):一次写一个字节数组的一部分
					
					|--FileOutputStream
					|--BufferedOutputStream
		|--字符流
			|--字符输入流
				Reader
					int read():一次读取一个字符
					int read(char[] chs):一次读取一个字符数组
					
					|--InputStreamReader
						|--FileReader
					|--BufferedReader
						String readLine():一次读取一个字符串
			|--字符输出流
				Writer
					void write(int ch):一次写一个字符
					void write(char[] chs,int index,int len):一次写一个字符数组的一部分
					
					|--OutputStreamWriter
						|--FileWriter
					|--BufferedWriter
						void newLine():写一个换行符
						
						void write(String line):一次写一个字符串
# 3:数据操作流(操作基本类型数据的流)(理解)
	(1)可以操作基本类型的数据
	(2)流对象名称	
		DataInputStream
		DataOutputStream

# 4:内存操作流(理解)
	(1)有些时候我们操作完毕后，未必需要产生一个文件，就可以使用内存操作流。
	(2)三种
		A:ByteArrayInputStream,ByteArrayOutputStream
		B:CharArrayReader,CharArrayWriter
		C:StringReader,StringWriter

# 5:打印流(掌握)
	(1)字节打印流，字符打印流
	(2)特点：
		A:只操作目的地,不操作数据源
		B:可以操作任意类型的数据
		C:如果启用了自动刷新，在调用println()方法的时候，能够换行并刷新
		D:可以直接操作文件
			问题：哪些流可以直接操作文件呢?
			看API，如果其构造方法能够同时接收File和String类型的参数，一般都是可以直接操作文件的
	(3)复制文本文件
		BufferedReader br = new BufferedReader(new FileReader("a.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("b.txt"),true);
		
		String line = null;
		while((line=br.readLine())!=null) {
			pw.println(line);
		}
		
		pw.close();
		br.close();
			
# 6:标准输入输出流(理解)
	(1)System类下面有这样的两个字段
		in 标准输入流
		out 标准输出流
	(2)三种键盘录入方式
		A:main方法的args接收参数
		B:System.in通过BufferedReader进行包装
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		C:Scanner
			Scanner sc = new Scanner(System.in);
	(3)输出语句的原理和如何使用字符流输出数据
		A:原理
			System.out.println("helloworld");
			
			PrintStream ps = System.out;
			ps.println("helloworld");
		B:把System.out用字符缓冲流包装一下使用
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

# 7:随机访问流(理解)
	(1)可以按照文件指针的位置写数据和读数据。
	(2)案例：
		A:写数据
		B:读数据
		C:获取和改变文件指针的位置

# 8:合并流(理解)
	(1)把多个输入流的数据写到一个输出流中。
	(2)构造方法：
		A:SequenceInputStream(InputStream s1, InputStream s2) 
		B:SequenceInputStream(Enumeration<? extends InputStream> e) 

# 9:序列化流(理解)
	(1)可以把对象写入文本文件或者在网络中传输
	(2)如何实现序列化呢?
		让被序列化的对象所属类实现序列化接口。
		该接口是一个标记接口。没有功能需要实现。
	(3)注意问题：
		把数据写到文件后，在去修改类会产生一个问题。
		如何解决该问题呢?
			在类文件中，给出一个固定的序列化id值。
			而且，这样也可以解决黄色警告线问题
	(4)面试题：
		什么时候序列化?
		如何实现序列化?
		什么是反序列化?

# 10:Properties(理解)
	(1)是一个集合类，Hashtable的子类
	(2)特有功能
		A:public Object setProperty(String key,String value)
		B:public String getProperty(String key)
		C:public Set<String> stringPropertyNames()
	(3)和IO流结合的方法
		把键值对形式的文本文件内容加载到集合中
		public void load(Reader reader)
		public void load(InputStream inStream)

		把集合中的数据存储到文本文件中
		public void store(Writer writer,String comments)
		public void store(OutputStream out,String comments)

# 11:NIO(了解)
	(1)JDK4出现的NIO，对以前的IO操作进行了优化，提供了效率。但是大部分我们看到的还是以前的IO
	Channel : 可以和原来的Stream类比， 但是有个关键区别， 那就是通过Channel 读写数据，是非阻塞的， 一个socket 也是Channel 的一种。
	Buffer: 通过Channel 读写的数据都在Buffer 中， 由于Buffer 不是流， 你读到Buffer 尾部以后还可以从头再读。
	Selector： 和Channel配合使用， Channel 可以把自己注册到Selector当中， 告诉Selector 说， 我要监听XXX事件， 这是一个线程管理多个Channel的关键。
![](http://img.mp.itc.cn/upload/20170303/a06999e89b3b4915a6ea4952231caa8d_th.png)
	(2)JDK7的NIO的使用	
		Path:路径
		Paths:通过静态方法返回一个路径
		Files:提供了常见的功能
			复制文本文件
			把集合中的数据写到文本文件