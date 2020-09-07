// iLog3-Verification.c : Defines the entry point for the console application.
//

#ifdef _WIN32
#   include "stdafx.h"
#   include <Windows.h>
#   ifdef HAVE_VLD
#       include <vld.h>
#   endif
#endif

#include <stdio.h>
#include "LOG.h"

#define LOG_STYLES_HELLO        ( LOG_STYLE_DATETIMEMS | LOG_STYLE_LOGLEVEL | LOG_STYLE_PID | LOG_STYLE_TID | LOG_STYLE_SOURCE | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )

int test_hello()
{
    char                buffer[64 + 1] = "";
    long                buflen = sizeof(buffer) - 1;

    /* 创建日志句柄 */
    if (CreateLogHandleG() == NULL)
    {
        printf("创建日志句柄失败errno[%d]\n", errno);
        return -1;
    }
    else
    {
        printf("创建日志句柄成功\n");
    }

    /* 设置日志输出文件名 */
    SetLogOutputG(LOG_OUTPUT_FILE, "test_iLOG3.log", LOG_NO_OUTPUTFUNC);
    /* 设置当前日志过滤等级 */
    SetLogLevelG(LOG_LEVEL_INFO);
    /* 设置当前行日志风格方案 */
    SetLogStylesG(LOG_STYLES_HELLO, LOG_NO_STYLEFUNC);

    /* 以不同日志等级写行日志 */
    DEBUGLOGG("hello DEBUG"); /* 这行日志因等级不够，被华丽的过滤了 */
    INFOLOGG("hello INFO");
    WARNLOGG("hello WARN");
    ERRORLOGG("hello ERROR");
    FATALLOGG("hello FATAL");

    /* 以不同日志等级写十六进制块日志 */
    DEBUGHEXLOGG(buffer, buflen, "hello DEBUG buffer[%ld]", buflen); /* 又一个被华丽的过滤 */
    INFOHEXLOGG(buffer, buflen, "hello INFO buffer[%ld]", buflen);
    WARNHEXLOGG(buffer, buflen, "hello WARN buffer[%ld]", buflen);
    ERRORHEXLOGG(buffer, buflen, "hello ERROR buffer[%ld]", buflen);
    FATALHEXLOGG(buffer, buflen, "hello FATAL buffer[%ld]", buflen);

    /* 销毁日志句柄 */
    DestroyLogHandleG();
    printf("销毁日志句柄\n");

    return 0;
}


int main(int argc, char *argv[])
{
    return test_hello();
}

