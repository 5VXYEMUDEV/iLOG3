#include "TEST_hello.h"

#include <stdio.h>
#include <errno.h>

#include "LOG.h"

#define LOG_STYLES_HELLO	( LOG_STYLE_DATETIMEMS | LOG_STYLE_LOGLEVEL | LOG_STYLE_PID | LOG_STYLE_TID | LOG_STYLE_SOURCE | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )


int test_hello()
{
    LOG		*g = NULL;

    char		buffer[4096 * 10 + 1] = "";
    long		buflen = sizeof(buffer) - 1;

    g = CreateLogHandle();
    if (g == NULL)
    {
        printf("������־���ʧ��errno[%d]\n", errno);
        return -1;
    }

    printf("������־����ɹ�\n");

    SetLogOutput(g, LOG_OUTPUT_FILE, "test_hello.log", LOG_NO_OUTPUTFUNC);
    SetLogLevel(g, LOG_LEVEL_INFO);
    SetLogStyles(g, LOG_STYLES_HELLO, LOG_NO_STYLEFUNC);

    WriteDebugLog(g, __FILE__, __LINE__, "hello DEBUG");
    WriteInfoLog(g, __FILE__, __LINE__, "hello INFO");
    WriteWarnLog(g, __FILE__, __LINE__, "hello WARN");
    WriteErrorLog(g, __FILE__, __LINE__, "hello ERROR");
    WriteFatalLog(g, __FILE__, __LINE__, "hello FATAL");

    WriteDebugHexLog(g, __FILE__, __LINE__, buffer, buflen, "������[%ld]", buflen);
    WriteInfoHexLog(g, __FILE__, __LINE__, buffer, buflen, "������[%ld]", buflen);
    WriteWarnHexLog(g, __FILE__, __LINE__, buffer, buflen, "������[%ld]", buflen);
    WriteErrorHexLog(g, __FILE__, __LINE__, buffer, buflen, "������[%ld]", buflen);
    WriteFatalHexLog(g, __FILE__, __LINE__, buffer, buflen, "������[%ld]", buflen);

    WriteInfoLog(g, __FILE__, __LINE__, "ok");

    DestroyLogHandle(g);
    printf("������־���\n");

    return 0;
}
