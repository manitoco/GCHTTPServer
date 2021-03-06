//
//  GCAsyncSocket.hpp
//  GCHTTPServer
//
//  Created by 小疯子 on 16/3/3.
//  Copyright © 2016年 GC. All rights reserved.
//

#ifndef GCAsyncSocket_hpp
#define GCAsyncSocket_hpp

#include <stdio.h>
#include "GCEvent.hpp"
#include "CORequest.hpp"
#include <iostream>
using namespace std;

#define COLog(fmt,...) printf("[CO:%s]+%d " fmt "\n",__func__,__LINE__,##__VA_ARGS__)

#define BUFFER_SIZE  50

/// 异步套接字对象
class GCAsyncSocket {
public:
    /// 监听端口，默认8888
    int port;
    /// 监听IP地址,默认0.0.0.0
    string addr;
    /// 服务器根目录
    string rootPath;
    ///服务器是否正在运行
    bool isRunning;
    GCAsyncSocket();
    ~GCAsyncSocket();
    ///启动服务器
    bool startServer();
    ///停止服务器
    bool stopServer();
    ///接收到新的连接请求
    GCEvent<int> onAccpeted;
private:
    /// 监听套接字编号
    int sockid;
    ///开始监听连接请求
    void beginSocketAccept();
};

#endif /* GCAsyncSocket_hpp */
