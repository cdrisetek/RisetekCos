# Risetek eCos Host Project 【该项目不再维护，准备清理】

## 工具下载地址：
- ftp://ftp.ecoscentric.com/pub/ecos/gnutools/i386linux/
- ftp://mirror.aarnet.edu.au/pub/sourceware/ecos/gnutools/i386linux/test/ 这里的版本支持 context-a5

## 环境设置
- 用户目录下创建bin目录，该目录是缺省的搜索目录。将工具ecosconfig拷贝到该目录下
- 将工具gnutools展开安放到~/bin/gnutools/下，并将诸如：i386-elf的bin目录加入到缺省搜索目录
- 通过sudo apt-get install tcl安装tcl以支持tclsh

## 用ecosconfig构造
- ftp://mirror.aarnet.edu.au/pub/sourceware/ecos/anoncvs/ecos-tools-bin-110209.i386linux.tar.bz2 下载到bin目录，并展开、使用ecosconfig，该版本避免了cr,lf在windows系统下出现的一些问题。
- ecosconfig --srcdir=/vagrant/eCos/packages new target template 构造ecos.ecc文件
- ecosconfig --srcdir=/vagrant/eCos/packages resolve 处理冲突
- ecosconfig --srcdir=/vagrant/eCos/packages tree 生成编译环境
- make编译链接
- 在.profile里面加上ECOS_REPOSITORY=/vagrant/eCos/packages，并export ECOS_REPOSITORY后，可以不指明--srcdir

## WSL 下构建ecosconfig工具
- 安装ecosconfig host tools需要的库：sudo apt-get install tcl-dev tk-dev
- mkdir -p ~/targets && cd ~/targets
- ./{path to}/host/configure && make
- ./tools/configtool/standalone/common/ecosconfig
