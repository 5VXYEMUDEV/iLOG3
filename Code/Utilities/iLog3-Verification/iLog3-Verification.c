#ifdef _WIN32
#   include "stdafx.h"
#   include <Windows.h>
#   ifdef HAVE_VLD
#       include <vld.h>
#   endif
#endif

#include "TEST_hello.h"
#include "TEST_logs.h"

int main()
{
    return test_logs();
}
