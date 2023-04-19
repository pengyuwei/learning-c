# IO

## 目录说明

- server-1.c：基于socket的阻塞IO服务器端，一次运行处理一个请求；
- server-2.c：基于socket的阻塞IO服务器端，每个http请求打开独立的子进程进行处理；
- server-3.c：基于socket的阻塞IO服务器端，每个请求打开独立的线程进行处理；
- server-4.c：基于socket的阻塞IO服务器端，请求通过协程进行处理；

## 准备工作

1. 安装AB测试工具: `sudo apt-get install apache2-utils`
2. 安装libgcc1：`apt-get install libgcc1:amd64`
3. 确认：`gcc --print-file-name=libgcc_s.so.1`
4. `export LD_LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/7/libgcc_s.so.1:$LD_LIBRARY_PATH`
5. 查看系统的最大进程数限制: `cat /proc/sys/kernel/pid_max`
6. 跟踪线程数：ps -mq `/bin/ps -aux|grep server|head -n 1|awk '{print $2}'`
7. 启动服务端：`LD_PRELOAD=/usr/lib/gcc/x86_64-linux-gnu/7/libgcc_s.so.1 ./server-3.out 8888`

测试环境

- Server: Intel(R) Xeon(R) Platinum 8269CY CPU @ 2.50GHz 1Core 1G Free=104M 带宽1Mbps
- Client: MacBookAir 1.1GHz Intel i5 4Core 8GB

## 横向对比

### 公网IP

| server | 请求数  | 并发  | 总耗时s    | 每秒处理  | 每请求耗时ms  | 每请求耗时ms(并发) | 速率KB/s |
| ------ | ---- | --- | ------- | ----- | -------- | ----------- | ------ |
| 1.顺序   | 1000 | 1   | 9.758   | 10.25 | 97.578   | 97.578      | 2.88   |
| 2.进程   | 1000 | 1   | 101.885 | 9.81  | 101.885  | 101.885     | 2.76   |
|        | 1000 | 10  | 17.282  | 57.86 | 172.825  | 17.282      | 16.27  |
|        | 1000 | 100 | 15.840  | 63.13 | 1584.046 | 15.840      | 17.76  |
| 3.线程   | 1000 | 1   | 98.567  | 10.15 | 98.567   | 98.567      | 2.85   |
|        | 1000 | 10  |         |       |          |             |        |
|        | 1000 | 100 |         |       |          |             |        |

### 127.0.0.1


| server  | 请求数   | 并发   | 总耗时s   | 每秒处理     | 每请求耗时ms | 每请求耗时ms(并发) | 速率KB/s  |
| ------- | ----- | ---- | ------ | -------- | ------- | ----------- | ------- |
| 1.顺序    | 1000  | 1    | 0.109  | 9139.51  | 0.109   | 0.109       | 2570.49 |
|         | 1000  | 10   | 0.062  | 16188.56 | 0.618   | 0.062       | 4553.03 |
|         | 1000  | 100  | 0.070  | 14231.23 | 7.027   | 0.070       | 4002.53 |
|         | 5000  | 100  | 0.408  | 12251.78 | 8.162   | 0.082       | 3445.81 |
|         | 5000  | 1000 | 0.416  | 12011.90 | 83.251  | 0.083       | 3378.35 |
|         | 10000 | 1000 | 0.755  | 13251.33 | 75.464  |             | 3726.94 |
| 2.进程    | 1000  | 1    | 0.256  | 3902.35  | 0.256   | 0.256       | 1097.54 |
|         | 1000  | 10   | 0.149  | 6733.83  | 1.485   | 0.149       | 1893.89 |
|         | 1000  | 100  | 0.130  | 7664.54  | 13.047  | 0.130       | 2155.65 |
|         | 5000  | 1    | 出错     |          |         |             |         |
| 3.线程    | 1000  | 1    | 0.148  | 6741.32  | 0.148   | 0.148       | 1895.99 |
|         | 1000  | 10   | 出错     |          |         |             |         |
|         | 5000  | 1    | 1.081  | 4626.49  | 0.216   | 0.216       | 1301.20 |
|         | 5000  | 10   | 出错     |          |         |             |         |
| python3 | 1000  | 1    | 1.004  | 995.73   | 1.004   | 1.004       | 1304.95 |
|         | 1000  | 10   | 0.847  | 1180.60  | 8.470   | 0.847       | 1547.23 |
|         | 1000  | 100  | 0.585  | 1709.48  | 58.497  | 0.585       | 2240.35 |
|         | 1000  | 1000 | 0.892  | 1120.71  | 892.289 | 0.892       | 1468.75 |
|         | 2000  | 1000 | 出错     |          |         |             |         |
|         | 5000  | 1    | 4.840  | 1032.97  | 0.968   | 0.968       | 1353.76 |
|         | 5000  | 10   | 3.650  | 1369.95  | 7.300   | 0.730       | 1795.38 |
|         | 5000  | 100  | 出错     |          |         |             |         |
|         | 10000 | 1    | 11.550 | 865.82   | 1.155   | 1.155       | 1134.69 |
|         | 10000 | 10   | 6.662  | 1501.09  | 6.662   | 0.666       | 1967.25 |
|         | 10000 | 100  | 出错     |          |         |             |         |



## 三种IO模型

- 阻塞IO（Blocking IO）
- 异步IO（Asynchronous IO）
- 并发IO（Concurrent IO）

## AB输出结果解释

- Concurrency Level：并发数；
- Time taken for tests：测试总耗时；
- Complete requests：完成的请求数量；
- Failed requests：失败的请求数量；
- Requests per second：每秒的请求数，公式：请求数 / 所用总时间；
- Time per request：每个请求花费的平均时间，公式：concurrency * timetaken * 1000 / done；
- Time per request：每个请求花费的平均时间，公式：timetaken * 1000 / done；
- Transfer rate：传输速率（单位是 KB/s），公式：totalread / 1024 / timetaken；

## Raw

### Test-1

```
$ ./server-1.out 8888
```

```
ab -n 1000 -c 1 http://<公网IP>:8888/
Concurrency Level:      1
Time taken for tests:   9.758 seconds
Complete requests:      100
Failed requests:        0
Total transferred:      28800 bytes
HTML transferred:       16100 bytes
Requests per second:    10.25 [#/sec] (mean)
Time per request:       97.578 [ms] (mean)
Time per request:       97.578 [ms] (mean, across all concurrent requests)
Transfer rate:          2.88 [Kbytes/sec] received
```

### Test-2

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
$ ab -n 1000 -c 10 http://<公网IP>:8888/
Concurrency Level:      10
Time taken for tests:   17.282 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      288000 bytes
HTML transferred:       161000 bytes
Requests per second:    57.86 [#/sec] (mean)
Time per request:       172.825 [ms] (mean)
Time per request:       17.282 [ms] (mean, across all concurrent requests)
Transfer rate:          16.27 [Kbytes/sec] received
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

### Test-3

```
# 每次测试需重启
./server-3.out 8888
# or
python3 -m http.server 8888
```

```
$ ab -t 30 -n 5000 -c 1 http://127.0.0.1:8888/
Concurrency Level:      1
Time taken for tests:   1.081 seconds
Complete requests:      5000
Failed requests:        0
Total transferred:      1440000 bytes
HTML transferred:       805000 bytes
Requests per second:    4626.49 [#/sec] (mean)
Time per request:       0.216 [ms] (mean)
Time per request:       0.216 [ms] (mean, across all concurrent requests)
Transfer rate:          1301.20 [Kbytes/sec] received
```

```
$ ab -t 30 -n 1000 -c 10 http://<公网IP>:8888/

```

```
$ ab -t 30 -n 1000 -c 100 http://<公网IP>:8888/

```
