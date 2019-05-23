---
title: 在Vultr+Ubuntu17.10上安装Nextcloud
toc: true
date: 2018-02-10 14:55:46
tags:
- Nextcloud
---
在互联网时代，“隐私”一词变得岌岌可危。
在中国各大网盘不顾用户的隐私，随意使用数据的现象已经司空见惯，于是就想着搭建一个私人网盘。
素闻Nextcloud天府乡，乱世之中，避风之港。
所以我决定尝试一下。
<!--more-->
# 前言
首先，我查阅了各种博客，由于我的服务器是512MB的内存不能安装Mysql5.7,所以最终将目标转向了Vultr官方文档[How to Install Nextcloud on Ubuntu 17.04](https://www.vultr.com/docs/how-to-install-nextcloud-on-ubuntu-17-04)。
# 具体步骤
看得懂英文的小伙伴可以直接阅读官方文档。
在开始之前，请确保您的服务器是最新的，并安装所需的 PHP 7.1 模块。
```
apt-get update
apt-get upgrade -y
apt-get install software-properties-common unzip
```
## 安装并配置 PHP 7.1
```
apt-get install -y python-software-properties
add-apt-repository -y ppa:ondrej/php
apt-get update -y
apt-get install -y php7.1 php7.1-fpm php7.1-cli php7.1-json php7.1-curl php7.1-imap php7.1-gd php7.1-mysql php7.1-xml php7.1-zip php7.1-intl php7.1-mcrypt php-imagick php7.1-mbstring
```
对于 Caddy，我们将使用 TCP 套接字而不是 Unix 套接字，因为它们更加优化。

/etc/php/7.1/fpm/pool.d/www.conf在第 36 行左右编辑该文件。查找listen = /run/php/php7.1-fpm.sock。注释掉并添加 TCP 套接字，如下所示：
```
;listen = /run/php/php7.1-fpm.sock
listen = 127.0.0.1:9000
```
现在重新启动 PHP7.1-fpm。
```
service php7.1-fpm restart
```
## 安装 Caddy
运行 Caddy 设置脚本将自动为您的系统（32/64 位）下载正确的版本并进行安装。
```
curl https://getcaddy.com | bash -s personal
```
创建我们将在其中提供文件的根目录：
```
mkdir -p /var/www/nextcloud
```
创建文件夹/etc/caddy和文件 “ Caddyfile”。
```
mkdir -p /etc/caddy
nano /etc/caddy/Caddyfile
```
现在，粘贴以下内容(第一行替换为自己的域名)：
```
your-domain-here.com {

root   /var/www/nextcloud
log    /var/log/nextcloud_access.log
errors /var/log/nextcloud_errors.log

fastcgi / 127.0.0.1:9000 php {
    env PATH /bin
}

rewrite {
    r ^/index.php/.*$
    to /index.php?{query}
}

# client support (e.g. os x calendar / contacts)
redir /.well-known/carddav /remote.php/carddav 301
redir /.well-known/caldav /remote.php/caldav 301

# remove trailing / as it causes errors with php-fpm
rewrite {
    r ^/remote.php/(webdav|caldav|carddav|dav)(\/?)$
    to /remote.php/{1}
}

rewrite {
    r ^/remote.php/(webdav|caldav|carddav|dav)/(.+?)(\/?)$
    to /remote.php/{1}/{2}
}

rewrite {
    r ^/public.php/(.+?)(\/?)$
    to /public.php/(.+?)(\/?)$
}

# .htaccess / data / config / ... shouldn't be accessible from outside
status 403 {
    /.htacces
    /data
    /config
    /db_structure
    /.xml
    /README
}

header / Strict-Transport-Security "max-age=31536000;"

}
```
让我们也把Caddy变成一项服务。将这些行粘贴到文件中/etc/systemd/system/caddy.service(如果你有多个网站需要进行解析，需要将PrivateTmp=true更改为false)。
```
[Unit]
Description=Caddy HTTP/2 web server %I
Documentation=https://caddyserver.com/docs
After=network-online.target
Wants=network-online.target
Wants=systemd-networkd-wait-online.service

[Service]
; run user and group for caddy
User=root
Group=root
ExecStart=/usr/local/bin/caddy -agree=true -conf=/etc/caddy/Caddyfile
Restart=on-failure

; create a private temp folder that is not shared with other processes
PrivateTmp=true

; limit the number of file descriptors, see `man systemd.exec` for more limit settings
LimitNOFILE=8192

[Install]
WantedBy=multi-user.target
```
启用并运行 Caddy 服务器。
```
systemctl enable caddy.service
systemctl start caddy.service
```
## 安装MariaDB
注意：保存并记住 MariaDB 安装过程中选择的根密码！

运行以下命令来安装 MariaDB。您可能希望用您选择的另一个替换 MariaDB 存储库。
```
apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0xF1656F24C74CD1D8
add-apt-repository 'deb [arch=amd64,i386] http://ftp.utexas.edu/mariadb/repo/10.2/ubuntu zesty main'
apt update
apt install mariadb-server -y
```
安装 MariaDB 后，我们必须为 NextCloud 安装创建一个用户和数据库。

运行这个命令序列：
```
mysql -u root -p
CREATE DATABASE nextcloud;
GRANT ALL PRIVILEGES ON nextcloud.* TO 'exampleUser'@'localhost' IDENTIFIED BY 'securepassword';
FLUSH PRIVILEGES;
exit
```
## NextCloud
切换到安装位置的根目录并执行以下命令。
```
cd /var/www/nextcloud
wget https://download.nextcloud.com/server/releases/nextcloud-12.0.0.zip
unzip nextcloud-*
mv nextcloud/* .
chown -R www-data:www-data /var/www/nextcloud
rm -rf nextcloud-*.zip
```
现在访问您的域名或 IP 地址，您将看到安装屏幕。按照屏幕上的安装说明并填写所需的管理员帐户详细信息，数据库用户，密码和名称。
# 总结
到这里我们基本就完成了Nextcloud的配置，如果你在安装过程中遇到任何问题欢迎联系我。