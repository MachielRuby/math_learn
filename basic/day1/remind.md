### 1、gcc的使用

-o file 指定生成的输出文件名为file

-E  只进行预处理

-S 只进行预处理和编译

-c 只进行预处理编译和汇编

-v 查看gcc版本号

-g 包含调式信息1

-On n=0~3 编译优化n越大优化得越多

-Wall   提示更多警告信息

-D  编译时定义宏

-static 静态连接

```c
int main()
{
	printf("Size: %d\n",SIZE);
	return 0;
}
deng@itcast:~/test$ gcc 2test.c -DSIZE=10

deng@itcast:~/test$ ./a.out

SIZE: 10
```

### 2、静态库的制作

- 前缀:lib
- 名字：self define
- 后缀: .a

最后名字为:libxxx.a

```c
gcc -c add.c -o add.o 
gcc -c sub.c -o sub.o
ar -rcs libtest.a add.o sub.o 自定义名字为test
r:更新
c:创建
s:建立索引
```

**使用**：

gcc test.c -L ./ -I./ -ltest -o test

1. -L：表示要连接的库所在目录
2. -I./: I(大写i) 表示指定头文件的目录为当前目录
3. -l(小写L)：指定链接时需要的库，去掉前缀和后缀

### 3、动态库的制作

- 前缀：lib
- 库名称：自己定义即可
- 后缀：.so

所以最终的动态库的名字应该为：libxxx.so

```
1、生成目标文件 -fPIC
gcc -fPIC -c add.c
2、生成共享库 -shared
生成指定的动态库
gcc -shared add.o sub.o -o libtest.so
3、nm查看对应函数
nm libtest.so | grep add
ldd 查看可执行文件的依赖和动态库ldd test linux-vdso.so.1
```

1. 临时设置LD_LIBRARY_PATH
   - export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径
2. 永久设置
   - 永久设置,把export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径，设置到~/.bashrc或者 /etc/profile文件中
   - source ~/.bashrc
3. 添加到ld.so.conf文件中 sudo ldconfig -v
   - sudo vim /etc/ld.so.conf
   - 文件最后添加动态库的绝对路径

### 4、gdb的使用

gcc -g hello.c -o hello 需要-g不然看不见程序函数名和变量名全是地址

- gdb test.c //启动执行文件
- set args 设置运行时的参数 show args 查看设置好的运行参数
- 启动程序 run:开始执行 start 向下执行一行
- list打印源代码
- set listsize count 设置一次打印的数量
- b 10 设置断点 break 10     break add 设置断点在add函数处
- info b 
- info break
- i break
- i b
- b test.c:8 if Value==5
- run 运行程序，可简写为r
- next 单步跟踪，函数调用当作一条简单语句执行，可简写为n
- step 单步跟踪，函数调进入被调用函数体内，可简写为s
- finish 退出进入的函数
- until 在一个循环体内单步跟踪时，这个命令可以运行程序直到退出循环体,可简写为u。
- continue 继续运行程序，停在下一个断点的位置，可简写为c
- quit 退出gdb，可简写为q

### 5、Makefile的使用

**三要素**

- 目标 依赖文件 命令

命令格式 make [-f file][options][targets]

1. [-f file]:
   - make默认在工作目录中寻找名为GNUmakefile、makefile、Makefile的文件作为makefile输入文件
   - -f 可以指定以上名字以外的文件作为makefile输入文件	
2. [ options ]
   - -v： 显示make工具的版本信息
   - -w： 在处理makefile之前和之后显示工作路径
   - -C dir：读取makefile之前改变工作路径至dir目录
   - -n：只打印要执行的命令但不执行
   - -s：执行但不显示执行的命令

```makefile
最简单的
test:test.c add.c sub.c
	gcc test.c add.c sub.c -o test
	
第二个版本
test:test.o add.o sub.o mul.o div.o
    gcc test.o add.o sub.o mul.o div.o -o test

test.o:test.c
    gcc -c test.c
add.o:add.c
    gcc -c add.c
sub.o:sub.c
    gcc -c sub.c
mul.o:mul.c
    gcc -c mul.c
div.o:div.c
    gcc -c div.c
    
CC = gcc #arm-linux-gcc

CPPFLAGS : C预处理的选项 如:-I

CFLAGS: C编译器的选项 -Wall -g -c

LDFLAGS : 链接器选项 -L -l
```

```makefile
版本3：
OBJS = add.o sub.o test.o
TARGET = test
CC = gcc

$(TARGET): $(OBJS)
	$(CC) $^ -o $@
add.o: add.c
	$(CC) -c $< -o $@
sub.o: sub.c
	$(CC) -c $< -o $@
test.o: test.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)
#$@: 表示目标
#$<: 表示第一个依赖
#$^: 表示所有的依赖
```

```makefile
版本4
OBJS = add.o sub.o test.o
TARGET = test
$(TARGET) : $(OBJS)
	gcc $(OBJS) -o $(TARGET)

%.o : %.c
	gcc -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)
```

- 常用函数 wildcard 查找当前目录下指定类型的文件
- patsubst匹配替换

```makefile
版本5
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
TARGET = test
cc = gcc
$(TARGET) : $(OBJS)
	$(cc) $(OBJS) -o $(TARGET)

%.o : %.c
	$(cc) -c $< -o $@

clean:
	rm -rf $(OBJS)  $(TARGET)
```

```makefile
版本6
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
TARGET = test
cc = gcc
$(TARGET) : $(OBJS)
	$(cc) $(OBJS) -o $(TARGET)

%.o : %.c
	$(cc) -c $< -o $@
.PYTHON:clean
clean:
	rm -rf $(OBJS)  $(TARGET)
	@echo "clean done"
```

make filename

```makefile
CC = gcc

# 默认目标是空的
.DEFAULT_GOAL := $(MAKECMDGOALS)

# 如果用户提供了目标文件，则将其作为默认目标
# ifeq ($(filter test%,$(MAKECMDGOALS)),)
# .DEFAULT_GOAL := $(filter test%,$(MAKECMDGOALS))
# endif

# 默认目标规则
%: %.o
	$(CC) $< -o $@

# 编译规则
%.o: %.c
	$(CC) -c $< -o $@

# 清理规则
clean:
	rm -f *.o 

```

