#include <stdio.h>
#include <errno.h>

#include "LOG.h"

#define LOG_STYLES_DEMO	( LOG_STYLE_DATETIMEMS | LOG_STYLE_LOGLEVEL | LOG_STYLE_PID | LOG_STYLE_TID | LOG_STYLE_SOURCE | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )
#define LOG_STYLES_DEMO2	( LOG_STYLE_DATETIME | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )
#define LOG_STYLES_EVENT	( LOG_STYLE_DATETIME | LOG_STYLE_CUSTLABEL1 | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )
#define LOG_STYLES_SIMPLE	( LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )

int test_demo()
{
	LOG		*g = NULL , *g3 = NULL , *g4 = NULL ;
#if ( defined __STDC_VERSION__ ) && ( __STDC_VERSION__ >= 199901 )
	LOG		*g2 = NULL ;
#endif
	
	char		buffer[ 64 + 1 ] = "" ;
	long		buflen = sizeof(buffer) - 1 ;
	
	g = CreateLogHandle() ;
	if( g == NULL )
	{
		printf( "������־���ʧ��errno[%d]\n" , errno );
		return -1;
	}
	
	SetLogOutput( g , LOG_OUTPUT_FILE , "test_demo.log" , LOG_NO_OUTPUTFUNC );
	SetLogOutput2( g , LOG_OUTPUT_FILE , LOG_NO_OUTPUTFUNC , "%s/test_demo.log" , getenv("HOME") );
	SetLogLevel( g , LOG_LEVEL_INFO );
	SetLogStyles( g , LOG_STYLES_DEMO , LOG_NO_STYLEFUNC );
	
#if ( defined __STDC_VERSION__ ) && ( __STDC_VERSION__ >= 199901 )
	g2 = CreateLogHandle() ;
	if( g2 == NULL )
	{
		printf( "������־���ʧ��errno[%d]\n" , errno );
		return -1;
	}
	
	SetLogOutput( g2 , LOG_OUTPUT_FILE , "$HOME$/test_hello2.log" , LOG_NO_OUTPUTFUNC );
	SetLogLevel( g2 , LOG_LEVEL_INFO );
	SetLogStyles( g2 , LOG_STYLES_DEMO , LOG_NO_STYLEFUNC );
#endif
	
#if ( defined _WIN32 ) || ( defined __linux__ ) || ( defined _AIX )
	g3 = CreateLogHandleG() ;
	if( g3 == NULL )
	{
		printf( "������־���ʧ��errno[%d]\n" , errno );
		return -1;
	}
	
	SetLogOutputG( LOG_OUTPUT_STDOUT , NULL , LOG_NO_OUTPUTFUNC );
	SetLogLevelG( LOG_LEVEL_INFO );
	SetLogStylesG( LOG_STYLES_EVENT , LOG_NO_STYLEFUNC );
	SetLogCustLabelG( 1 , "COREIB1_SERVICE" );
#endif
	
	g4 = CreateLogHandle() ;
	if( g4 == NULL )
	{
		printf( "������־���ʧ��errno[%d]\n" , errno );
		return -1;
	}
	
	SetLogOutput( g4 , LOG_OUTPUT_SYSLOG , "test" , LOG_NO_OUTPUTFUNC );
	SetLogLevel( g4 , LOG_LEVEL_INFO );
	SetLogStyles( g4 , LOG_STYLES_SIMPLE , LOG_NO_STYLEFUNC );
	
	printf( "������־����ɹ�\n" );
	
	WriteDebugLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteInfoLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteWarnLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteErrorLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteFatalLog( g , __FILE__ , __LINE__ , "hello iLOG3" );
	
	WriteDebugHexLog( g , __FILE__ , __LINE__ , buffer , buflen , "������[%ld]" , buflen );
	WriteInfoHexLog( g , __FILE__ , __LINE__ , buffer , buflen , "������[%ld]" , buflen );
	WriteWarnHexLog( g , __FILE__ , __LINE__ , buffer , buflen , "������[%ld]" , buflen );
	WriteErrorHexLog( g , __FILE__ , __LINE__ , buffer , buflen , "������[%ld]" , buflen );
	WriteFatalHexLog( g , __FILE__ , __LINE__ , buffer , buflen , "������[%ld]" , buflen );
	
#if ( defined __STDC_VERSION__ ) && ( __STDC_VERSION__ >= 199901 )
	DEBUGLOG( g2 , "hello iLOG3" );
	INFOLOG( g2 , "hello iLOG3" );
	WARNLOG( g2 , "hello iLOG3" );
	ERRORLOG( g2 , "hello iLOG3" );
	FATALLOG( g2 , "hello iLOG3" );
	
	DEBUGHEXLOG( g2 , buffer , buflen , "������[%ld]" , buflen );
	INFOHEXLOG( g2 , buffer , buflen , "������[%ld]" , buflen );
	WARNHEXLOG( g2 , buffer , buflen , "������[%ld]" , buflen );
	ERRORHEXLOG( g2 , buffer , buflen , "������[%ld]" , buflen );
	FATALHEXLOG( g2 , buffer , buflen , "������[%ld]" , buflen );
#endif
	
#if ( defined _WIN32 ) || ( defined __linux__ ) || ( defined _AIX )
	WriteDebugLogG( __FILE__ , __LINE__ , "hello iLOG3" );
	WriteInfoLogG( __FILE__ , __LINE__ , "hello iLOG3" );
	WriteWarnLogG( __FILE__ , __LINE__ , "hello iLOG3" );
	WriteErrorLogG( __FILE__ , __LINE__ , "hello iLOG3" );
	WriteFatalLogG( __FILE__ , __LINE__ , "hello iLOG3" );
#if ( defined __STDC_VERSION__ ) && ( __STDC_VERSION__ >= 199901 )
	DEBUGHEXLOGG( buffer , buflen , "������[%ld]" , buflen );
	INFOHEXLOGG( buffer , buflen , "������[%ld]" , buflen );
	WARNHEXLOGG( buffer , buflen , "������[%ld]" , buflen );
	ERRORHEXLOGG( buffer , buflen , "������[%ld]" , buflen );
	FATALHEXLOGG( buffer , buflen , "������[%ld]" , buflen );
#endif
#endif
	
	WriteDebugLog( g4 , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteInfoLog( g4 , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteWarnLog( g4 , __FILE__ , __LINE__ , "hello iLOG3" );
	WriteErrorLog( g4 , __FILE__ , __LINE__ , "hello iLOG3" );
	
	DestroyLogHandle( g );
#if ( defined __STDC_VERSION__ ) && ( __STDC_VERSION__ >= 199901 )
	DestroyLogHandle( g2 );
#endif
#if ( defined _WIN32 ) || ( defined __linux__ ) || ( defined _AIX )
	DestroyLogHandleG();
#endif
	DestroyLogHandle( g4 );
	printf( "������־���\n" );
	
	return 0;
}

int main()
{
	return -test_demo();
}
