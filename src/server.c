#include "../inc/poolsocket.h"
#include <pthread.h>

int main(void){
    int listenFd;
    int port = 8080;
    int ret = 0;

    int timeOut = 3;
    int connFd = -1;
    // 服务端 初始化
    ret = sckServer_init(port, &listenFd);
    if (ret != 0){
        printf("sckServer_init error %d\n", ret);
        return ret;
    }

    while(1){

        ret = sckServer_accept(listenFd, timeOut, &connFd);
        if (ret != 0){
            printf("sckServer_accept error %d\n", ret);
            return ret;
        }
        pthread_create()
    }

    return 0;
}


