#include <stdio.h>
#include <errno.h>
#include "LOG.h"

struct tm *localtime_r(const time_t *timep, struct tm *result);

funcLogStyle MyLogStyleFunc ;
int MyLogStyleFunc( LOG *p , LOGBUF *logbuf , char *c_filename , long c_fileline , int log_level , char *format , va_list valist )
{
	long		tt ;
	struct tm	stime ;
	
	time( & tt );
	LOCALTIME( tt , stime )
	
	FormatLogBuffer( p , GetLogBuffer(p) , "%02d%02d %02d%02d%02d " , stime.tm_mon+1 , stime.tm_mday , stime.tm_hour , stime.tm_min , stime.tm_sec );
	FormatLogBufferV( p , GetLogBuffer(p) , format , valist );
	FormatLogBuffer( p , GetLogBuffer(p) , "%s" , LOG_NEWLINE );
	
	return 0;
}

int test_stylesfunc()
{
	LOG		*g = NULL ;
	
	g = CreateLogHandle() ;
	if( g == NULL )
	{
		printf( "������־���ʧ��errno[%d]\n" , errno );
		return -1;
	}
	else
	{
		printf( "������־����ɹ�\n" );
	}
	
	SetLogOutput( g , LOG_OUTPUT_FILE , "test_stylesfunc.log" , LOG_NO_OUTPUTFUNC );
	SetLogLevel( g , LOG_LEVEL_DEBUG );
	SetLogStyles( g , LOG_STYLE_CALLBACK , & MyLogStyleFunc );
	
	WriteDebugLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteInfoLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteWarnLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteErrorLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteFatalLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	
	DestroyLogHandle( g );
	printf( "������־���\n" );
	
	return 0;
}

int main()
{
	return -test_stylesfunc();
}
