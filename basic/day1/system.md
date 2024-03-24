### 系统函数

**标准输入输出**

```c
#define STDIN_FILENO  0 //标准输入的文件描述符
#define STDOUT_FILENO 1 //标准输出的文件描述符
#define STDERR_FILENO 2 //标准错误的文件描述符
```

```c
write
int main()
{
    int fd = open("test.txt",O_RDWR|O_TRUNC|O_CREAT);
    if(fd==-1)
    {
        perror("open errno");
    }

    char buf[1024];
    scanf("%s",&buf);
    write(fd,buf,sizeof(buf));

    return 0;
}
read
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = open("test.txt",O_RDONLY);
    if(fd == -1)perror("open errno");
    char buf[1024];
    int n;
    while(n= (read(fd,buf,sizeof(buf)))>0)
    {
        printf("%s\n",buf);
    }

    close(fd);
    return 0;
}

STDIN_FILENO STDOUT_FILENO 

int main()
{
    char buf[1024];
    int n = read(STDIN_FILENO,buf,sizeof(buf));
    if(n<0)perror("没有输入");
    write(STDOUT_FILENO,buf,n);

    return 0;
}
```

#### 手搓cp函数

```c
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>


int main(int argc,char*argv[])
{
    char buf[1024];
    int  fd = open(argv[1],O_RDONLY);
    int  fd1 = open(argv[2],O_CREAT|O_RDWR|O_TRUNC);
    int n;
    while((n = read(fd,buf,sizeof(buf)))>0)
    {
        write(fd1,buf,n);
    }
    close(fd);
    close(fd1);
    

    return 0;
}
```

#### 错误处理函数

perror函数：void perror();

strerror函数: char*strerror(int errnum);

#### 扩展大小

```c
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int fd = open("lseek.txt",O_CREAT|O_RDWR,0664);
    if(fd == -1)
    {
        perror("open error");
    }
    //使用lseek拓文件大小
    int len = lseek(fd,10,SEEK_END);
    printf("LEN = %d\n",len);

    int ret  = write(fd,"a",strlen("a"));
    close(fd);
    printf("ret = %d\n",ret);
    return 0;
}
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);

```

**阻塞与非阻塞：后面的epoll 和 select**

#### read

```c
失败返回-1
 	errno == EAGAIN(或EWOULDBLOCK)：以非阻塞读，没读到数据
 	errno != EAGAIN:错误
```



#### fcntl

```c
#include <fcntl.h>
int fcntl(int fd, int cmd, ... /* arg */ );
fd 是要操作的文件描述符。
cmd 是要执行的操作，可以是下列之一：
F_DUPFD：复制文件描述符。
F_GETFD：获取文件描述符标志。
F_SETFD：设置文件描述符标志。
F_GETFL：获取文件状态标志。
F_SETFL：设置文件状态标志。
arg 是一个可选参数，它取决于 cmd 的值 
function： 不打开文件修改文件权限

    int flg = fcntl(fd,F_GETFL)
    flg |= O_NONBLOCK //添加非阻塞
    fcntl(fd,F_SETFL,flag)
```

#### ftruncate

```c
#include <unistd.h>

int ftruncate(int fd, off_t length);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    off_t length = 100; // 要截断文件到 100 字节
    int ret = ftruncate(fd, length);
    if (ret == -1) {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}

```

#### stat获取文件属性类型

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
void sys_err(const char*str)
{
    perror(str);
    exit(1);
}

int main(int argc,char * argv[])
{
    struct stat sbuf;
    int ret = lstat(argv[1],&sbuf);
    printf("file size is %ld\n",sbuf.st_size);
    if(ret == -1)
    {
        sys_err("stat err");
    }
    if(S_ISREG(sbuf.st_mode)){
        printf("It's a regular file");
    }
    else if (S_ISDIR(sbuf.st_mode))
    {
        printf("it's a dir\n");
    }
    else if( S_ISFIFO(sbuf.st_mode))
    {
        printf("It's is a fifo");
    }
    else if(S_ISLNK(sbuf.st_mode))
    {
        printf("It's a software link");
    }
    
    return 0;
}
lstat stat 
   	stat会穿透连接
    lstat不会穿透连接
```

####　stat获取inode号

查看软连接的内容：readlink() 或者readlink()函数
