# IO

## 目录说明

- server-1.c：基于socket的阻塞IO服务器端，一次运行处理一个请求；
- server-2.c：基于socket的阻塞IO服务器端，每个http请求打开独立的子进程进行处理；
- server-3.c：基于socket的阻塞IO服务器端，每个请求打开独立的线程进行处理；
- server-4.c：基于socket的阻塞IO服务器端，请求通过协程进行处理；

## 准备工作

1. 安装AB测试工具: `sudo apt-get install apache2-utils`
2. 查看系统的最大进程数限制: `cat /proc/sys/kernel/pid_max`

## 测试

- Server: Intel(R) Xeon(R) Platinum 8269CY CPU @ 2.50GHz 1Core 1G Free=104M 带宽1Mbps
- Client: MacBookAir 1.1GHz Intel i5 4Core 8GB

```
$ ./server-2.out 8888
```

```
$ ab -n 1000 -c 1 http://<公网IP>:8888/
Concurrency Level:      1
Time taken for tests:   101.885 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      288000 bytes
HTML transferred:       161000 bytes
Requests per second:    9.81 [#/sec] (mean)
Time per request:       101.885 [ms] (mean)
Time per request:       101.885 [ms] (mean, across all concurrent requests)
Transfer rate:          2.76 [Kbytes/sec] received
```

```
$ ab -n 500 -c 10 http://<公网IP>:8888/
Concurrency Level:      10
Time taken for tests:   5.933 seconds
Complete requests:      500
Failed requests:        0
Total transferred:      144000 bytes
HTML transferred:       80500 bytes
Requests per second:    84.28 [#/sec] (mean)
Time per request:       118.658 [ms] (mean)
Time per request:       11.866 [ms] (mean, across all concurrent requests)
Transfer rate:          23.70 [Kbytes/sec] received
```

```
$ ab -n 1000 -c 100 http://<公网IP>:8888/
Concurrency Level:      100
Time taken for tests:   15.840 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      288000 bytes
HTML transferred:       161000 bytes
Requests per second:    63.13 [#/sec] (mean)
Time per request:       1584.046 [ms] (mean)
Time per request:       15.840 [ms] (mean, across all concurrent requests)
Transfer rate:          17.76 [Kbytes/sec] received
```

## 三种IO模型

- 阻塞IO（Blocking IO）
- 异步IO（Asynchronous IO）
- 并发IO（Concurrent IO）

## 解释

- Concurrency Level：并发数；
- Time taken for tests：测试总共耗时；
- Complete requests：完成的请求数量；
- Failed requests：失败的请求数量；
- Requests per second：平均每秒处理的请求数量；
- Time per request：每个请求的平均处理时间；
- Time per request：每个请求的平均等待时间（考虑并发）；
- Transfer rate：传输速率（单位是 KB/s）；
