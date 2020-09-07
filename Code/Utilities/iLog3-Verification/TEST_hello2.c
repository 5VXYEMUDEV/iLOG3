#include "TEST_hello2.h"

#include <stdio.h>
#include <errno.h>

#include "LOG.h"

#define LOG_STYLES_HELLO	( LOG_STYLE_DATETIMEMS | LOG_STYLE_LOGLEVEL | LOG_STYLE_PID | LOG_STYLE_TID | LOG_STYLE_SOURCE | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )

int test_hello2()
{
    LOG		*g = NULL;

    char		buffer[64 + 1] = "";
    long		buflen = sizeof(buffer) - 1;

    g = create_log_handle();
    if (g == NULL)
    {
        printf("create log handle failed , errno[%d]\n", errno);
        return -1;
    }

    printf("create log handle ok\n");

    set_log_output(g, LOG_OUTPUT_FILE, "test_hello2.log", LOG_NO_OUTPUTFUNC);
    set_log_level(g, LOG_LEVEL_INFO);
    set_log_styles(g, LOG_STYLES_HELLO, LOG_NO_STYLEFUNC);

    DEBUGLOG(g, "hello DEBUG");
    INFOLOG(g, "hello INFO");
    WARNLOG(g, "hello WARN");
    ERRORLOG(g, "hello ERROR");
    FATALLOG(g, "hello FATAL");

    DEBUGHEXLOG(g, buffer, buflen, "buflen[%ld]", buflen);
    INFOHEXLOG(g, buffer, buflen, "buflen[%ld]", buflen);
    WARNHEXLOG(g, buffer, buflen, "buflen[%ld]", buflen);
    ERRORHEXLOG(g, buffer, buflen, "buflen[%ld]", buflen);
    FATALHEXLOG(g, buffer, buflen, "buflen[%ld]", buflen);

    destroy_log_handle(g);
    printf("destroy log handle\n");

    return 0;
}
