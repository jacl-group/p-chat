
from https://pocoproject.org/download.html

```bash
git clone -b master https://github.com/pocoproject/poco.git
mkdir cmake-build
cd cmake-build
cmake -DCMAKE_INSTALL_PREFIX=${HOME}/local ..
```



```bash
sudo apt-get install openssl libssl-dev
```
  
```bash
sudo apt install mysql-server mysql-client libmysqlcppconn-dev
```

## Troubleshooting

when I ran cmake, the following message was given:

```
-- Couldn't find MySQL or MariaDB
-- MySQL Support Disabled - no MySQL library
```
This indicates that the package *libmysqlclient-dev* needs to be installed. 

```bash
sudo apt install libmysqlclient-dev
```
