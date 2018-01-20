---
title: 'Java学习笔记StringBuffer和Arrays，Integer,Character'
date: 2017-03-08 15:18:42
tags:
- Java基础
toc: true
---
StringBuffer(掌握)Arrays(掌握)Integer(掌握)Character(了解)
<!--more-->
# StringBuffer(掌握)
	(1)用字符串做拼接，比较耗时并且也耗内存，而这种拼接操作又是比较常见的，为了解决这个问题，Java就提供了
	   一个字符串缓冲区类。StringBuffer供我们使用。
	(2)StringBuffer的构造方法
		A:StringBuffer()
		B:StringBuffer(int size)
		C:StringBuffer(String str)
	(3)StringBuffer的常见功能(自己补齐方法的声明和方法的解释)
		A:添加功能
                public StringBuffer append(String str)
                public StringBuffer insert(int offset,String str)
		B:删除功能
                public StringBuffer deleteCharAt(int index)
                public StringBuffer delete(int start,int end)
		C:替换功能
                public StringBuffer replace(int start,int end,String str)
		D:反转功能
                public StringBuffer reverse()
		E:截取功能(注意这个返回值)
                public String substring(int start)
                public String substring(int start,int end)
	(4)StringBuffer的练习
		A:String和StringBuffer相互转换
			String -- StringBuffer
				构造方法
			StringBuffer -- String
				toString()方法
		B:字符串的拼接
		C:把字符串反转
		D:判断一个字符串是否对称
	(5)面试题
		小细节：
			StringBuffer：同步的，数据安全，效率低。
			StringBuilder：不同步的，数据不安全，效率高。
		A:String,StringBuffer,StringBuilder的区别
		B:StringBuffer和数组的区别?
	(6)注意的问题：
		String作为形式参数，StringBuffer作为形式参数。
	(7)String,StringBuffer,StringBuilder的区别(转自http://www.cnblogs.com/A_ming/archive/2010/04/13/1711395.html)
		1.三者在执行速度方面的比较：StringBuilder >  StringBuffer  >  String
		2.String <（StringBuffer，StringBuilder）的原因
			String：字符串常量
			StringBuffer：字符串变量
			StringBuilder：字符串变量
			从上面的名字可以看到，String是“字符串常量”，也就是不可改变的对象。对于这句话的理解你可能会产生这样一个疑问  ，比如这段代码：
			String s = "abcd";
			s = s+1;
			System.out.print(s);// result : abcd1
			我们明明就是改变了String型的变量s的，为什么说是没有改变呢? 其实这是一种欺骗，JVM是这样解析这段代码的：首先创建对象s，赋予一个abcd，然后再创建一个新的对象s用来执行第二行代码，也就是说我们之前对象s并没有变化，所以我们说String类型是不可改变的对象了，由于这种机制，每当用String操作字符串时，实际上是在不断的创建新的对象，而原来的对象就会变为垃圾被ＧＣ回收掉，可想而知这样执行效率会有多低。
			而StringBuffer与StringBuilder就不一样了，他们是字符串变量，是可改变的对象，每当我们用它们对字符串做操作时，实际上是在一个对象上操作的，这样就不会像String一样创建一些而外的对象进行操作了，当然速度就快了。
		3.一个特殊的例子：
			String str = “This is only a” + “ simple” + “ test”;
			StringBuffer builder = new StringBuilder(“This is only a”).append(“ simple”).append(“ test”);
			你会很惊讶的发现，生成str对象的速度简直太快了，而这个时候StringBuffer居然速度上根本一点都不占优势。其实这是JVM的一个把戏，实际上：
			String str = “This is only a” + “ simple” + “test”;
			其实就是：
			String str = “This is only a simple test”;
			所以不需要太多的时间了。但大家这里要注意的是，如果你的字符串是来自另外的String对象的话，速度就没那么快了，譬如：
			String str2 = “This is only a”;
			String str3 = “ simple”;
			String str4 = “ test”;
			String str1 = str2 +str3 + str4;
			这时候JVM会规规矩矩的按照原来的方式去做。
		4.StringBuilder与 StringBuffer
			StringBuilder：线程非安全的
			StringBuffer：线程安全的
			当我们在字符串缓冲去被多个线程使用是，JVM不能保证StringBuilder的操作是安全的，虽然他的速度最快，但是可以保证StringBuffer是可以正确操作的。当然大多数情况下就是我们是在单线程下进行的操作，所以大多数情况下是建议用StringBuilder而不用StringBuffer的，就是速度的原因。
	(8)StringBuffer详解
		http://blog.csdn.net/u012877472/article/details/50808554
		StringBuffer初始化及扩容机制http://www.cnblogs.com/myhappylife/p/6542633.html
# Arrays(掌握)
    (1)Arrays工具类
		A:是针对数组进行操作的工具类。包括排序和查找等功能。
		B:要掌握的方法
                        public static String toString(int[] a)
                        public static void sort(int[] a)
                        public static int binarySearch(int[] a,int key)
			把数组转成字符串：
			排序：
			二分查找：
	(2)Arrays工具类的源码解析
	(3)把字符串中的字符进行排序
		举例：
			"edacbgf"
			得到结果
			"abcdefg"
# Integer(掌握)
	(1)为了让基本类型的数据进行更多的操作，Java就为每种基本类型提供了对应的包装类类型
		byte 		Byte
		short		Short
		int		     Integer
		long		Long
		float		Float
		double		Double
		char		Character
		boolean		Boolean
	(2)Integer的构造方法
		A:Integer i = new Integer(100);
		B:Integer i = new Integer("100");
			注意：这里的字符串必须是由数字字符组成
	(3)String和int的相互转换
		A:String -- int
			Integer.parseInt("100");
		B:int -- String
			String.valueOf(100);
	(4)其他的功能(了解)
		进制转换
                public static String toBinaryString(int i)
                public static String toOctalString(int i)
                public static String toHexString(int i)
                十进制转其他进制
                public static String toString(int i,int radix)//radix为2-36
	(5)JDK5的新特性
		自动装箱	基本类型--引用类型
		自动拆箱	引用类型--基本类型
		
		把下面的这个代码理解即可：
			Integer i = 100;
			i += 200;
	(6)面试题(-128到127之间的数据缓冲池问题|转自http://blog.csdn.net/wuxizhi777/article/details/51588895)
		/*
		* 看程序写结果
		* 
		* 注意：Integer的数据直接赋值，如果在-128到127之间，会直接从缓冲池里获取数据
		*/
		public class IntegerDemo {
		    public static void main(String[] args) {
		        Integer i1 = new Integer(127);
		        Integer i2 = new Integer(127);
		        System.out.println(i1 == i2);
		        System.out.println(i1.equals(i2));
		        System.out.println("-----------");

		        Integer i3 = new Integer(128);
		        Integer i4 = new Integer(128);
		        System.out.println(i3 == i4);
		        System.out.println(i3.equals(i4));
		        System.out.println("-----------");

		        Integer i5 = 128;
		        Integer i6 = 128;
		        System.out.println(i5 == i6);
		        System.out.println(i5.equals(i6));
		        System.out.println("-----------");

		        Integer i7 = 127;
		        Integer i8 = 127;
		        System.out.println(i7 == i8);
		        System.out.println(i7.equals(i8));

		        // 通过查看源码，我们就知道了，针对-128到127之间的数据，做了一个数据缓冲池，如果数据是该范围内的，每次并不创建新的空间
		        Integer ii = Integer.valueOf(127);
		    }
		}
		结果如下：
		false
		true

		false
		true

		false // 这里是因为开辟了新的空间。
		true

		true
		true

		这里可以参照 jdk 中的源码：

		* @return a <tt>Integer</tt> instance representing <tt>i</tt>.
		     * @since  1.5
		     */
		    public static Integer valueOf(int i) {
		    final int offset = 128;
		    if (i >= -128 && i <= 127) { // must cache 
		        return IntegerCache.cache[i + offset];
		    }
		        return new Integer(i);
		    }
		当在 -128~127之外才重新 new Integer(i);
# Character(了解)
	(1)Character构造方法	
		Character ch = new Character('a');
	(2)要掌握的方法：(自己补齐)
		A:public static boolean isUpperCase(char ch)判断给定的字符是否是大写
		B:public static boolean isLowerCase(char ch)判断给定的字符是否是小写
		C:public static boolean isDigit(char ch)判断给定的字符是否是数字字符
		D:public static boolean toUpperCase(char ch)把给定的字符转成大写
		E:public static boolean toLowerCase(char ch)把给定的字符转成小写
	(3)案例：
		统计字符串中大写，小写及数字字符出现的次数