﻿---
title: Java学习笔记内部类
date: 2017-03-07 17:01:38
tags:
- Java基础
toc: true
---
内部类是很难理解的东西。
<!--more-->
# 内部类(理解)
### (1)把类定义在另一个类的内部，该类就被称为内部类。
		举例：把类B定义在类A中，类B就被称为内部类。
### (2)内部类的访问规则
		A:可以直接访问外部类的成员，包括私有
		B:外部类要想访问内部类成员，必须创建对象
### (3)内部类的分类
		A:成员内部类
		B:局部内部类
### (4)成员内部类
		A:private 为了数据的安全性
		B:static 为了访问的方便性
		成员内部类不是静态的：
			外部类名.内部类名 对象名 = new 外部类名.new 内部类名();
		成员内部类是静态的：
			外部类名.内部类名 对象名 = new 外部类名.内部类名();
### (5)成员内部类的面试题(填空)
```
		30,20,10
		
		class Outer {
			public int num = 10;
			
			class Inner {
				public int num = 20;
				
				public viod show() {
					int num  = 30;
					
					System.out.println(num);
					System.out.println(this.num);
					System.out.println(Outer.this.num);
				}
			}
		}
```
### (6)局部内部类
		A:局部内部类访问局部变量必须加final修饰。
		B:为什么呢?
			因为局部变量使用完毕就消失，而堆内存的数据并不会立即消失。
			所以，堆内存还是用该变量，而改变量已经没有了。
			为了让该值还存在，就加final修饰。
			通过反编译工具我们看到了，加入final后，堆内存直接存储的是值，而不是变量名。
### (7)匿名内部类(掌握)
		A:是局部内部类的简化形式
		B:前提
			存在一个类或者接口
		C:格式:
			new 类名或者接口名() {
				重写方法;
			}
		D:本质：
			其实是继承该类或者实现接口的子类匿名对象
### (8)匿名内部类在开发中的使用
		我们在开发的时候，会看到抽象类，或者接口作为参数。
		而这个时候，我们知道实际需要的是一个子类对象。
		如果该方法仅仅调用一次，我们就可以使用匿名内部类的格式简化。
```
		
		interface Person {
			public abstract void study();
		}
		
		class PersonDemo {
			public void method(Person p) {
				p.study();
			}
		}
		
		class PersonTest {
			public static void main(String[] args) {
				PersonDemo pd = new PersonDemo();
				pd.method(new Person() {
					public void study() {
						System.out.println("好好学习，天天向上");
					}
				});
			}
		}
```	
### (9)匿名内部类的面试题(补齐代码)
```
		interface Inter {
			void show();
		}
		
		class Outer {
			//补齐代码
			//public static Inter method() {
			//	return new Inter() {
			//		public void show() {
			//			System.out.println("HelloWorld");
			//		}	
			//	};
			//}
		}
		
		class OuterDemo {
			public static void main(String[] args) {
				Outer.method().show(); //"HelloWorld"
			}
		}
```
http://www.cnblogs.com/dolphin0520/p/3811445.html
内部类详解