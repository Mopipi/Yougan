#include "socket.h"

namespace Socket {

#ifdef WIN32
    typedef int SOCKLEN;
#elif LINUX
    typedef socklen_t SOCKLEN;
#endif

    // ��ʼ����
    int startup() {
        int ret = 0;
#ifdef WIN32
        struct WSAData wsa;
        WORD sockVersion = MAKEWORD(2, 2);
        ret = (int)WSAStartup(sockVersion, &wsa);
#elif LINUX
        signal(SIGPIPE, SIG_IGN);
#endif
        return ret;
    }

    // ��������
    int cleanup() {
        int ret = 0;
#ifdef WIN32
        ret = (int)WSACleanup();
#endif
        return ret;
    }

    // ��ʼ���׽���
    SOCKET createSocket(int family, int type, int protocol) {
        return (SOCKET)socket(family, type, protocol);
    }

    // �ر��׽���
    int clostSocket(SOCKET sock) {
        int ret = 0;
        if (sock < 0) return 0;
#ifdef WIN32
        ret = closesocket(sock);
#elif LINUX
        ret = close(sock);
#endif
        return ret;
    }

    // ����Ŀ���ַ
    int connect(SOCKET sock, const struct sockaddr *addr) {
        SOCKLEN len = sizeof(struct sockaddr);
        return ::connect(sock, addr, len);
    }

    // ֹͣ�׽���
    int shutdown(SOCKET sock, int mode) {
        return ::shutdown(sock, mode);
    }

    // �󶨶˿�
    int bind(SOCKET sock, const struct sockaddr *addr) {
        SOCKLEN len = sizeof(struct sockaddr);
        return ::bind(sock, addr, len);
    }

    // ������Ϣ
    int listen(SOCKET sock, int count) {
        return ::listen(sock, count);
    }

    // ��������
    SOCKET accept(SOCKET sock, struct sockaddr *addr) {
        SOCKLEN len = sizeof(struct sockaddr);
        return ::accept(sock, addr, &len);
    }

    // �����׽��ֲ���
    int setSockopt(SOCKET sock, int level, int optname, const char *optval, int optlen) {
        SOCKLEN len = optlen;
        return setsockopt(sock, level, optname, optval, len);
    }

    // ����ioctlsocket����������������
    int ioctl(SOCKET sock, long cmd, unsigned long *argp) {
        int ret;
#ifdef WIN32
        ret = ioctlsocket((SOCKET)sock, cmd, argp);
#elif LINUX
        ret = ioctl(sock, cmd, argp);
#endif
        return ret;
    }

    // ȡ���׽��������ӵ�ַ
    int peerName(SOCKET sock, struct sockaddr_in *addr) {
        SOCKLEN len = sizeof(struct sockaddr);
        return getpeername(sock, (sockaddr*)addr, &len);
    }

    ulong getHostByName(const char* host) {
        ulong addr = 0x00;
        struct addrinfo *info = NULL;
        struct addrinfo hints;

        memset(&hints, 0, sizeof(hints));
        hints.ai_family = PF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;

        uint32 ret = getaddrinfo(host, NULL, &hints, &info);
        if (ret != 0)
            return INADDR_NONE;

        if (info != NULL) {
            addr = ((struct sockaddr_in*)info->ai_addr)->sin_addr.s_addr;
        }

        freeaddrinfo(info);
        return addr;
    }

    // ������Ϣ
    int send(SOCKET sock, const void *buf, int size, int mode) {
        return ::send(sock, (char*)buf, size, mode);
    }

    // ������Ϣ
    int recv(SOCKET sock, void *buf, int size, int mode) {
        return ::recv(sock, (char*)buf, size, mode);
    }
}
