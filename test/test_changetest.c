#include <stdio.h>
#include <errno.h>

#include "LOG.h"

#define LOG_STYLES_HELLO	( LOG_STYLE_DATETIMEMS | LOG_STYLE_LOGLEVEL | LOG_STYLE_PID | LOG_STYLE_TID | LOG_STYLE_SOURCE | LOG_STYLE_FORMAT | LOG_STYLE_NEWLINE )

int test_changetest()
{
	LOG		*g = NULL ;
	
	g = CreateLogHandle() ;
	if( g == NULL )
	{
		printf( "������־���ʧ��errno[%d]\n" , errno );
		return -1;
	}
	
	printf( "������־����ɹ�\n" );
	
	SetLogOutput( g , LOG_OUTPUT_FILE , "$HOME$/log/test_changetest.log" , LOG_NO_OUTPUTFUNC );
	SetLogLevel( g , LOG_LEVEL_INFO );
	SetLogStyles( g , LOG_STYLES_HELLO , LOG_NO_STYLEFUNC );

	SetLogOptions( g , LOG_OPTION_CHANGE_TEST );
	SetLogRotateMode( g , LOG_ROTATEMODE_SIZE );
	SetLogRotateSize( g , 10 );
	
	SetLogFileChangeTest( g , 1 );
	WriteInfoLog( g , __FILE__ , __LINE__ , "hello INFO" );
	
	printf( "�����������..." );
	fgetc( stdin );

	SetLogFileChangeTest( g, 1 );
	WriteInfoLog(g, __FILE__, __LINE__, "hello INFO");

	DestroyLogHandle( g );
	printf( "������־���\n" );
	
	return 0;
}

int main()
{
	return -test_changetest();
}
