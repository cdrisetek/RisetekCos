<h3>工具下载地址：</h3>
<ul>
<li>ftp://ftp.ecoscentric.com/pub/ecos/gnutools/i386linux/</li>
<li>ftp://mirror.aarnet.edu.au/pub/sourceware/ecos/gnutools/i386linux/test/ 这里的版本支持 context-a5</li>
</ul>
<h3>环境设置</h3>
<ul>
<li>用户目录下创建bin目录，该目录是缺省的搜索目录。将工具ecosconfig拷贝到该目录下</li>
<li>将工具gnutools展开安放到~/bin/gnutools/下，并将诸如：i386-elf的bin目录加入到缺省搜索目录</li>
<li>通过sudo apt-get install tcl安装tcl以支持tclsh</li>
</ul>
<h3>用ecosconfig构造</h3>
<ul>
<li>ftp://mirror.aarnet.edu.au/pub/sourceware/ecos/anoncvs/ecos-tools-bin-110209.i386linux.tar.bz2 下载到bin目录，并展开、使用ecosconfig，该版本避免了cr,lf在windows系统下出现的一些问题。</li>
<li>ecosconfig --srcdir=/vagrant/eCos/packages new target template 构造ecos.ecc文件</li>
<li>ecosconfig --srcdir=/vagrant/eCos/packages resolve 处理冲突</li>
<li>ecosconfig --srcdir=/vagrant/eCos/packages tree 生成编译环境</li>
<li>make编译链接</li>
<li>在.profile里面加上ECOS_REPOSITORY=/vagrant/eCos/packages，并export ECOS_REPOSITORY后，可以不指明--srcdir</li>
</ul>
<h3>WSL 下构建ecosconfig工具</h3>
<ul>
<li>mkdir -p ~/targets && cd ~/targets</li>
<li>./{path to}/host/configure && make</li>
<li>./tools/configtool/standalone/common/ecosconfig</li>
</ul>