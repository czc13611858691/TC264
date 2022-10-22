python-can是一个使用can比较方便的库，可以用来开发一些脚本

使用的是pcan设备

pip install -r requirement.txt

关于使用此工具存在不稳定的点

can库可能会有错误

在我的硬件上无法使用python-can 4.0.0

当我回退到**python-can 3.3.4**版本可以使用

笔记本电脑程序可以正常运行

台式机却不能运行会提示导入pcanbasic dll之后报错

- 我是将pcan驱动重新安装，**点了所有的选项**

![](https://cdn.jsdelivr.net/gh/czc13611858691/picgoRepo@master/20221022112547.png)

- 并且安装了**PCAN-PassThru**

目前不能确认是什么原因导致的

参考文章

https://blog.csdn.net/qq_45303968/article/details/126103202