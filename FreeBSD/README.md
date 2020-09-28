## 编译

本示例需要在FreeBSD中编译。推荐版本FreeBSD 13。

## 用法说明

本示例来自[kqueue官方文档](https://www.freebsd.org/cgi/man.cgi?kqueue)，监控文件系统指定目录，当新建或者删除文件的时候显示提示信息。

```
0xFF@FreeBSD:~/FreeBSD $ make
0xFF@FreeBSD:~/FreeBSD $ ./kqueue.out ./
Something was written in './'
```

```
struct kevent {
    uintptr_t   ident;      /* identifier for this event */
    int16_t     filter;     /* filter for event */
    uint16_t    flags;      /* general flags */
    uint32_t    fflags;     /* filter-specific flags */
    intptr_t    data;       /* filter-specific data */
    void        *udata;     /* opaque user data identifier */
};
```