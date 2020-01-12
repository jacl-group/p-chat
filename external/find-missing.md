# How to find a missing file

When trying to build the **poco** project, I got the message
```
-- Couldn't find MySQL or MariaDB
```

Because it came from a cmake build, and knowing the way the **poco** build directory was put together, I knew that it was probably in the ```poco/cmake``` directory. So I looked there to find the file the message came from.


```bash
$ grep "Couldn't find MySQL or MariaDB" *
FindMySQL.cmake:        message(STATUS "Couldn't find MySQL or MariaDB")
```

Looking into *FindMySQL.cmake*, I found that it was searching for *mysql.h*. 

I installed a tool called ```apt-file``` to find the packages which installed the file *mysql.h*.

```bash
$ apt-file search mysql.h | egrep /mysql\.h$
hhvm-dev: /usr/include/hphp/third-party/webscalesqlclient/mysql-5.6/include/mysql.h
libdballe-dev: /usr/include/dballe/sql/mysql.h
libmariadb-dev: /usr/include/mariadb/mysql.h
libmariadbclient-dev: /usr/include/mysql/mysql.h
libmysqlclient-dev: /usr/include/mysql/mysql.h
pike7.8-mysql: /usr/lib/pike7.8/7.4/include/mysql.h
```

The above shows that there are two optoins for getting mysql.h. I can either choose mariadb or mysql. And because I have chosen to use mysql, then I need to install package **libmysqlclient-dev**.

```bash
sudo apt install libmysqlclient-dev
```
