# IO

## 目录说明

- server-1.c：基于socket的阻塞IO服务器端，一次运行处理一个请求；
- server-2.c：基于socket的阻塞IO服务器端，每个请求打开独立的子进程进行处理；
- server-3.c：基于socket的阻塞IO服务器端，每个请求打开独立的线程进行处理；
- server-4.c：基于socket的阻塞IO服务器端，请求通过协程进行处理；

## Usage

```
./server-1.out
./client.out 127.0.0.1 8888
```

## 三种IO模型

- 阻塞IO（Blocking IO）
- 异步IO（Asynchronous IO）
- 并发IO（Concurrent IO）

