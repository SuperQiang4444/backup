---
title: Java学习笔记
date: 2017-03-09 10:17:32
tags:
- Java基础
toc: true
---


Math,Random,System,BigInteger,BigDecimal,DateFormat,Calendar
<!--more-->
# Math(掌握)
	(1)针对数学运算进行操作的类PI E
	(2)常见方法
		A:绝对值public static int abs(int a)
		B:向上取整public static double ceil(double a)
		C:向下取整public static double floor(double a)
		D:两个数据中的大值public static int max(int a,int b)
		E:a的b次幂public static double pow(double a,double b)
		F:随机数public static double random():随机数[0.0,1.0)
		G:四舍五入public static int round(float a)
		H:正平方根public static sqrt(double a)
# Random(理解)
	(1)用于产生随机数的类
	(2)构造方法:
		A:Random() 默认种子，每次产生的随机数不同
		B:Random(long seed) 指定种子，每次种子相同，随机数就相同
	(3)成员方法:
		A:int nextInt() 返回int范围内的随机数
		B:int nextInt(int n) 返回[0,n)范围内的随机数
# System(掌握)
	(1)系统类,提供了一些有用的字段和方法
	(2)成员方法(自己补齐)
		A:运行垃圾回收器 public static void gc()
		B:退出jvm public static void exit(int status)
		C:获取当前时间的毫秒值 public static long currentTimeMillis()
		D:数组复制 public static void arraycopy(源数组,开始位置,目标数组,开始位置,复制长度)
# BigInteger(理解)
	(1)针对大整数的运算
	(2)构造方法	
		A:BigInteger(String s)
	(3)成员方法(自己补齐)
		A:加public BigInteger add(BigInteger val)
                B:减public BigInteger subtract(BigInteger val)
		C:乘public BigInteger multiply(BigInteger val)
		D:除public BigInteger divide(BigInteger val)
		E:商和余数public BigInteger[] divideAndRemainder(BigInteger val)

# BigDecimal(理解)
	(1)浮点数据做运算，会丢失精度。所以，针对浮点数据的操作建议采用BigDecimal。(金融相关的项目)
	(2)构造方法
		A:BigDecimal(String s)
	(3)成员方法：
		A:加public BigDecimal add(BigDecimal augend)
                B:减public BigDecimal subtract(BigDecimal subtrahend)
		C:乘public BigDecimal multiply(BigDecimal multiplicand)
		D:除public BigDecimal divide(BigDecimal divisor)
		E:自己保留小数几位public BigDecimal divide(BigDecimal divisor,int scale,int roundingMode)

# Date/DateFormat(掌握)
	(1)Date是日期类，可以精确到毫秒。
		A:构造方法
			Date()
			Date(long time)
		B:成员方法
			getTime()
			setTime(long time)
		C:日期和毫秒值的相互转换
		案例：你来到这个世界多少天了?
	(2)DateFormat针对日期进行格式化和针对字符串进行解析的类，但是是抽象类，所以使用其子类SimpleDateFormat
		A:SimpleDateFormat(String pattern) 给定模式
			yyyy-MM-dd HH:mm:ss
		B:日期和字符串的转换
			a:Date -- String
				format()
				
			b:String -- Date
				parse()
	
# Calendar(掌握)
	(1)日历类，封装了所有的日历字段值，通过统一的方法根据传入不同的日历字段		可以获取值。
	(2)如何得到一个日历对象呢?
		Calendar rightNow = Calendar.getInstance();
		本质返回的是子类对象
	(3)成员方法
		A:根据日历字段得到对应的值
  		public int get(int field)
    		B:根据日历字段和一个正负数确定是添加还是减去对应日历字段的值			public void add(int field,int amount)
		C:设置日历对象的年月日
		public final void set(int year,int month,int date)