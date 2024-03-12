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
```

