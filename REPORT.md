# C++大作业报告
### 一、大作业内容
##### 在nebula工程中发现了有测试秒和毫秒的函数，但是没有测试微秒的函数，于是，我仿造nebula自带的测试秒和毫秒的函数，写了一段测试微秒的函数。
##### nebula中秒、毫秒和微秒的函数如下
![](https://github.com/MUNLELEE/PICTURE/blob/master/c++1.png?raw=true)
##### nabula中测试秒和毫秒的函数如下
![](https://github.com/MUNLELEE/PICTURE/blob/master/c++3.png?raw=true)
##### 我更改的代码，也就是测试微秒的函数如下
![](https://github.com/MUNLELEE/PICTURE/blob/master/c++2.png?raw=true)
##### 过程：
通过理解nebula自带的两个测试函数，可以知道，测试的流程是通过一定的迭代次数以及`std::chrono::steady_clock::now()` 函数的两次使用相减，以及最后`ASSERT_LE` 和 `ASSERT_GE` 两个函数确定允许的误差范围，最终判断函数是否符合要求。而通过`sleep`函数来进行程序的计时。
##### 最后提交的pr结果如图
![](https://github.com/MUNLELEE/PICTURE/blob/master/c++4.png?raw=true)
由于不知道为什么在`git remote`upstream和origin正确的情况下，不能提交到vesoft-inc的账户中去，所以最后只是提交到了silverdays账户中
### 二、大作业心得
##### 在这次的大作业中，首先是从环境配置开始一步一步的坑和不懂的问题，通过百度一个一个的解决，也算提升了一定的解决问题的能力，而且在函数修改的时候，多次编译无法通过，在这个期间通过修改`usleep`函数的参数大小以及之后两个比较函数的允许误差范围来提高精确度，多次的调参也让我对这几个函数的功能有了更深的了解。而且在这次的作业中，多次使用git命令和Linux系统以及vim编辑器，让我对这三个工具有了一定掌握，能够在未来做项目或者工作的时候提供帮助。也知道了通过ssh密钥来连接本地和远程的GitHub仓库。不足的是对nebula这个项目还不是很懂。
##### （_*最后希望以后有什么问题还能问老师qaq*_）
