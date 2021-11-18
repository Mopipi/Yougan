#include "os.h"

uint32 GetTickTime() {
#ifdef WIN32
    return timeGetTime(); // timeGetTime() ��Ƶ�ʸ�С��ȷ
    //return GetTickCount(); // GetTickCount() ����ȷ������Ϊsleep()ʹcpuƵ��ֹͣ��ֹͣ
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
#endif
}