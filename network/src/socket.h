#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "define.h"

#ifdef WIN32
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

#define PI_SD_BOTH			SD_BOTH

#elif LINUX
typedef int SOCKET
#define INVALID_SOCKET (int)(~0)
#define SOCKET_ERROR (-1)
#endif

typedef uint16 Port;
typedef uint32 Host;
typedef uint32 NetID;

namespace Socket {
    // ��ʼ����
    int startup();
    // ��������
    int cleanup();

    // ��ʼ���׽���
    SOCKET createSocket(int family, int type, int protocol);

    // �ر��׽���
    int clostSocket(SOCKET sock);

    // ����Ŀ���ַ
    int connect(SOCKET sock, const struct sockaddr *addr);

    // ֹͣ�׽���
    int shutdown(SOCKET sock, int mode);

    // �󶨶˿�
    int bind(SOCKET sock, const struct sockaddr *addr);

    // ������Ϣ
    int listen(SOCKET sock, int count);

    // ��������
    SOCKET accept(SOCKET sock, struct sockaddr *addr);

    // �����׽��ֲ���
    int setSockopt(SOCKET sock, int level, int optname, const char *optval, int optlen);

    // ����ioctlsocket����������������
    int ioctl(SOCKET sock, long cmd, unsigned long *argp);

    // ȡ���׽��������ӵ�ַ
    int peerName(SOCKET sock, struct sockaddr_in *addr);

    // ��ȡ������ַ
    ulong getHostByName(const char* host);

    // ������Ϣ
    int send(SOCKET sock, const void *buf, int size, int mode);

    // ������Ϣ
    int recv(SOCKET sock, void *buf, int size, int mode);
}

#endif