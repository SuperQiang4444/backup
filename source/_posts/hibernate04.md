---
title: hibernate04
date: 2017-06-05 10:20:19
tags:
- Java基础
toc: true
---
查询的方式
<!--more-->
# HQL查询
```
//查询所有
Query query = session.createQuery("from Customer");
List<Customer> list = query.list();
//条件查询
Query query = session.createQuery("from Customer c where c.cid=? and c.custName=?");
query.setParameter(0,1);
query.setParameter(1,"123");
List<Customer> list = query.list();
//排序查询
Query query = session.createQuery("from Customer order by cid asc");
List<Customer> list = query.list();
//分页查询
Query query = session.createQuery("from Customer");
query.setFirstResult(0);//开始位置
query.setMaxResults(3);//每页记录数
List<Customer> list = query.list();
//投影查询
Query query = session.createQuery("select custName from Customer");
List<Customer> list = query.list();
//函数使用
Query query = session.createQuery("select count(*) from Customer");
Object obj = query.uniqueResult();
Long lobj = (Long) obj;
int count = lobj.intValue();
```
# QBC查询
```
//查询所有
Criteria criteria = session.createCriteria(Customer.class);
List<Customer> list = criteria.list();
//条件查询
Criteria criteria = session.createCriteria(Customer.class);
criteria.add(Restrictions.eq("cid",1));
criteria.add(Restrictions.eq("custName","123"));
List<Customer> list = criteria.list();
//排序查询
Criteria criteria = session.createCriteria(Customer.class);
criteria.addOrder(Order.asc("cid"));
List<Customer> list = criteria.list();
//分页查询
Criteria criteria = session.createCriteria(Customer.class);
criteria.setFirstResult(0);//开始位置
criteria.setMaxResults(3);//每页记录数
List<Customer> list = criteria.list();
//统计查询
Criteria criteria = session.createCriteria(Customer.class);
criteria.setProjection(Projections.rowCount());
Object obj = criteria.uniqueResult();
Long lobj = (Long) obj;
int count = lobj.intValue();
//离线查询
DetachedCriteria detachedCriteria = DetachedCriteria.forClass(Customer.class);
Criteria criteria = detachedCriteria.getExecutableCriteria(session);
List<Customer> list = criteria.list();
```
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fga6m6r2s3j30gd0br0u3.jpg)
# HQL多表查询
### 内连接
from Customer c inner join c.setLinkMan
返回的list里面是数组形式
### 迫切内连接
from Customer c inner join fetch c.setLinkMan
返回的list里面是对象
### 左外连接
from Customer c left outer join c.setLinkMan
### 迫切做外连接
from Customer c left outer join fetch c.setLinkMan
### 右外连接
from Customer c right outer join c.setLinkMan
# hibernate检索策略
1.立即查询
根据id查询，一调用get方法马上发送语句查询数据库
2.延迟查询
根据id查询，可以调用load方法，只有在真正需要的时候才发送语句查询数据库
2.1延迟查询分类
2.1.1类级别延迟
根据id查询，调用load的延迟
2.1.2关联级别延迟
通过客户查所有联系人
2.1.2.1关联级别延迟操作
在set标签上进行配置
![](http://wx4.sinaimg.cn/large/005P8ayVgy1fga6m62bt4j30is0a3769.jpg)
# hibernate批量抓取
set标签batch-size=""进行配置，值为整数，值越大发送的语句越少。