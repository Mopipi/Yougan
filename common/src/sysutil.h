#ifndef _SYS_UTIL_H_
#define _SYS_UTIL_H_

#include <string>

#include "define.h"

namespace SysUtil {
    // ��ȡ����Ŀ¼
    bool getProcDir(std::string &path);

    // ��ȡ·��Ŀ¼
    bool getPathDir(std::string &path);

    // ����·��Ŀ¼
    bool makePathDir(std::string &path);
};

#endif
