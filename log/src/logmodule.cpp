#include "logmodule.h"

Log *g_log = 0;

LogModule::LogModule():m_quit(true), m_count(0) {

}

LogModule::~LogModule() {

}

int LogModule::init() {
    g_log = create("./log/", "name");
    g_log->setTarget(LOG_STDOUT | LOG_FILE);
    return Succeed;
}

int LogModule::start() {
    for (uint32 i = 0; i < m_count; ++i) {
        m_log[i]->start();
    }
    m_thread.start((Run)running, this);
    return Succeed;
}

int LogModule::update() {
    return Succeed;
}

int LogModule::stop() {
    return Succeed;
}

int LogModule::release() {
    return Succeed;
}

uint32 LogModule::running(LogModule* logModule) {
    return logModule->work();
}

uint32 LogModule::work() {
    m_quit = false;
    while (!m_quit) {
        for (uint32 i = 0; i < m_count; ++i) {
            m_log[i]->output();
        }
    }
    return 0;
}

Log* LogModule::create(const char *path, const char *name) {
    Log *log = new Log(path, name);
    m_log[m_count++] = log;
    return log;
}