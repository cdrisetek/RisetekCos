<h3>工具下载地址：</h3>
<ul>
<li>ftp://ftp.ecoscentric.com/pub/ecos/gnutools/i386linux/</li>
</ul>
<h3>环境设置</h3>
<ul>
<li>用户目录下创建bin目录，该目录是缺省的搜索目录。将工具ecosconfig拷贝到该目录下</li>
<li>将工具gnutools展开安放到~/bin/gnutools/下，并将诸如：i386-elf的bin目录加入到缺省搜索目录</li>
</ul>
<h3>用ecosconfig构造</h3>
<ul>
<li>ecosconfig --srcdir=/vagrant/eCos/packages new target template 构造ecos.ecc文件</li>
<li>ecosconfig --srcdir=/vagrant/eCos/packages resolve 处理冲突</li>
<li>ecosconfig --srcdir=/vagrant/eCos/packages tree 生成编译环境</li>
<li>make编译链接</li>
</ul>
