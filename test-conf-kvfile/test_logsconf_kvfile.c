#include "LOGSCONF_KVFILE.h"

int test_logsconf( char *program )
{
	LOGS	*gs = NULL ;
	char	buffer[ 64 + 1 ] = "" ;
	long	buflen = sizeof(buffer) - 1 ;
	
#if ( defined _WIN32 )
	if( strstr( program , ".exe" ) )
	{
		strstr( program , ".exe" )[0] = '\0' ;
	}
#endif
	
	gs = CreateLogsHandleFromKvFileG( program , ".conf" ) ;
	if( gs == NULL )
	{
		printf( "�������ļ�������־�������ʧ��\n" );
		return -1;
	}
	else
	{
		printf( "������־������ϳɹ�\n" );
	}
	
	DEBUGLOGSG( "debug LOGSCONF" );
	INFOLOGSG( "info LOGSCONF" );
	WARNLOGSG( "warn LOGSCONF" );
	ERRORLOGSG( "error LOGSCONF" );
	FATALLOGSG( "fatal LOGSCONF" );
	
	DEBUGHEXLOGSG( buffer , buflen , "������[%ld]" , buflen );
	INFOHEXLOGSG( buffer , buflen , "������[%ld]" , buflen );
	WARNHEXLOGSG( buffer , buflen , "������[%ld]" , buflen );
	ERRORHEXLOGSG( buffer , buflen , "������[%ld]" , buflen );
	FATALHEXLOGSG( buffer , buflen , "������[%ld]" , buflen );
	
	DestroyLogsHandleG( gs );
	printf( "������־�������\n" );
	
	return 0;
}

int main( int argc , char *argv[] )
{
	return -test_logsconf( argv[0] );
}
