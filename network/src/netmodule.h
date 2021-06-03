#ifndef _NET_MODULE_H_
#define _NET_MODULE_H_

#include "server.h"
#include "network.h"

class NetModule : public Module {
    DISALLOW_COPY_AND_ASSIGN(NetModule);
public:
    NetModule(char* moduleName = 0);
    ~NetModule() {}
public:
    virtual int init();
    virtual int start();
    virtual int update();
    virtual int stop();
    virtual int release();
public:
    uint32 connectAsynWork();
    static uint32 running(NetModule* netModule);
public:
    bool listen(const char *host, Port port, int backlog, NetCallback* netkCallback, NetID *netid = 0);
    bool connect(const char *host, Port port, NetCallback* netkCallback, NetID* netid = 0, uint32 timeout = 3000);
    bool connectAsyn(Host host, Port port, uint32* handle, NetCallback* netkCallback, uint32 timeout = 3000);
    bool connectAsyn(const char *host, Port port, uint32* handle, NetCallback* netkCallback, uint32 timeout = 3000);
private:
    struct ConnectAsyn {
        uint32 handle;
        std::string host;
        Port port;
        uint32 timeout;
        NetCallback* netkCallback;
    };

    struct ConnectRet {
        NetID netid;
        uint32 handle;
        Host host;
        Port port;
        bool result;
        NetCallback* netkCallback;
    };

    typedef ThreadQueue<ConnectAsyn> ConnectAsynQueue;
    typedef ThreadQueue<ConnectRet> ConnectRetQueue;
    ConnectAsynQueue m_connectAsynQueue;
    ConnectRetQueue m_connectRetQueue;
    Thread m_connectAsynThread;

    bool m_exist;
    uint32 m_handle;
    uint32 m_packSize;
    JobQueue *m_jobQueue;
    Network *m_network;
    Semaphore* m_mainLoopSem;
};
#endif