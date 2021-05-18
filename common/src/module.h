#ifndef _MODULE_H_
#define _MODULE_H_

#include "define.h"

class Module {
    DISALLOW_COPY_AND_ASSIGN(Module)
public:
    enum{
        Succeed = 0,
        Fail,
        Pending,
    };

    enum{
        Initing,
        Inited,
        Starting,
        Started,
        Updating,
        Updated,
        Stopping,
        Stopped,
        Releasing,
        Released,
        //Fail,
    };
    Module()
        //:m_interface_mgr(0), m_module_state(ST_Released)
    {}
    virtual ~Module() {}

    virtual int init() = 0;
    virtual int start() = 0;
    virtual int update() = 0;
    virtual int stop() = 0;
    virtual int release() = 0;

//    /* �˺����ͷ��Լ���ռ�õĿռ䣬���ô˺�����Game������ʹ�ô�ģ���ָ�� */
//    virtual void Free() = 0;
//
//    int GetState()const { return m_module_state; }
//protected:
//    virtual ~IModule() {}
//    IInterfaceMgr* Interface() { return m_interface_mgr; }
//private:
//    IInterfaceMgr * m_interface_mgr;
//    int m_module_state;
};
#endif