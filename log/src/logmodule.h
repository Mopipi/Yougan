#ifndef _LOG_MODULE_H_
#define _LOG_MODULE_H_

#include "server.h"
#include "thread.h"

#include "log.h"

static const char LOG_MODULE[] = "LogModule";

#define LOG_MAX 256

class LogModule : public Module {
    DISALLOW_COPY_AND_ASSIGN(LogModule);
public:
    LogModule();
    ~LogModule();
public:
    virtual int init();
    virtual int start();
    virtual int update();
    virtual int stop();
    virtual int release();
public:
    Log* create(const char *path, const char *name);
private:
    static uint32 running(LogModule* logModule);
    uint32 work();
private:
    bool m_quit;
    Thread m_thread;

    uint32 m_count;
    Log *m_log[LOG_MAX];
};

extern Log *g_log; //��������־

#define LOG_DEBUG(str) g_log->write(LV_DEBUG, str, sizeof(str))
#define LOG_INFO(str) g_log->write(LV_INFO, str, sizeof(str))

#endif