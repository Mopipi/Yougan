#ifndef _NET_CALLBACK_H_
#define _NET_CALLBACK_H_

#include "define.h"
#include "socket.h"

class Network;

class NetCallback
{
public:
    /*
    ��������acceptʱ��ص��ú���
    @netid			�����ӵ�netid
    @ip			Զ�˵�ַ��������
    @port			Զ�˶˿ں�
    */
    virtual void onAccept(Port listen_port, NetID netid, Host host, Port port) = 0;

    /*
    ���յ�������Ϣʱ�ص��ú���
    @netid			������Ϣ��Դ��netid
    @data			��������
    @length		���ݳ���
    */
    virtual void onRecv(NetID netid, const char *data, int length) = 0;

    /*
    ��������Ͽ���ʱ��ص��ú���
    @netid			�Ͽ����������ӵ�netid
    */
    virtual void onDisconnect(NetID netid) = 0;

    /*
    �������첽ConnectAsyn������غ�ص�
    @result		���ӽ���Ƿ�ɹ�
    @handle		ConnectAsynʱ���������handle
    @netid			���ӳɹ�ʱ��netidʱ�������ӵ������id
    @ip			����ip
    @port			����port
    */
    virtual void onConnect(bool result, uint32 handle, NetID netid, Host host, Port port) = 0;
};

#endif