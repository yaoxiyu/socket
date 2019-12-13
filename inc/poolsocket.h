#ifndef _poolsocket_H_
#define _poolsocket_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define Sck_Ok                              0
#define Sck_BaseErr                         3000

#define Sck_ErrParam                        (Sck_BaseErr + 1)
#define Sck_ErrTimeOut                      (Sck_BaseErr + 2)
#define Sck_ErrPeerClosed                   (Sck_BaseErr + 3)
#define Sck_ErrMalloc                       (Sck_BaseErr + 4)

#define Sck_Err_Pool_CreateConn             (Sck_BaseErr + 20)
#define Sck_Err_Pool_Termisnated             (Sck_BaseErr + 21)
#define Sck_Err_Pool_GetConn_ValidIsZero    (Sck_BaseErr + 22)
#define Sck_Err_Pool_HaveExist              (Sck_BaseErr + 23)
#define Sck_Err_Pool_ValidBounds            (Sck_BaseErr + 24)

// 客户端 初始化
int sckClient_init();

// 客户端 连接服务器
int sckClient_connect(char *ip, int port, int connectTime, int *connFd);

// 客户端 关闭和服务端的连接
int sckClient_closeConn(int connFd);

// 客户端 发送报文
int sckClient_send(int connFd, int sendTime, unsigned char *data, int dataLen);

// 客户端 接收报文
int sckClient_rev(int connFd, int revTime, unsigned char **out, int *outLen);

// 客户端 释放
int sckClient_destroy();

// 释放内存 
int sck_FreeMem(void **buf);


typedef struct _SCKClientPoolParameters{
    char    serverIp[64];
    int     serverPort;
    int     bounds;
    int     connectTime;
    int     sendTime;
    int     revTime;
}SCKClientPoolParameter;

// 客户端 socket池初始化
int sckClientPool_init(void **handle, SCKClientPoolParameter *param);

// 客户端 socket池 获取一条连接
int sckClientPool_getConn(void *handle, int *connFd);

// 客户端 socket池 发送数据
int sckClientPool_send(void *handle, int connFd, unsigned const char *data, int dataLen);

// 客户端 socket池 接收数据
int sckClientPool_rev(void *handle, int connFd, unsigned char **out, int *outLen);

// 客户端 socket池 把连接放回
int sckClientPool_putConn(void *handle, int connFd, int validFlag);

// 客户端 socket池 销毁连接
int sckClientPool_destroy(void *handle);





// 服务端 初始化
int sckServer_init(int port, int *listenFd);

// 服务端 接收连接
int sckServer_accept(int listenFd, int timeOut, int *connFd);

// 服务端 关闭连接
int sckServer_closeConn(int connFd);

// 服务端 发送报文
int sckServer_send(int connFd, int timeOut, unsigned char *data, int dataLen);

// 服务端 接收报文
int sckServer_rev(int connFd, int timeOut, unsigned char **out, int *outLen);

// 服务端 释放
int sckServer_destroy();






#ifdef __cplusplus
}
#endif


#endif