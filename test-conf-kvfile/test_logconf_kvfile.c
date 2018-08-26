#include "LOGCONF_KVFILE.h"

int test_logconf()
{
	LOG	*g = NULL ;
	char	buffer[ 64 + 1 ] = "" ;
	long	buflen = sizeof(buffer) - 1 ;
	
	g = CreateLogHandleFromKvFileG( "test_logconf_kvfile.conf" , NULL ) ;
	if( g == NULL )
	{
		printf( "�������ļ�������־���ʧ��\n" );
		return -1;
	}
	else
	{
		printf( "������־����ɹ�\n" );
	}
	
	DEBUGLOGG( "debug LOGCONF" )
	INFOLOGG( "info LOGCONF" )
	WARNLOGG( "warn LOGCONF" )
	ERRORLOGG( "error LOGCONF" )
	FATALLOGG( "fatal LOGCONF" )
	
	DEBUGHEXLOGG( buffer , buflen , "������[%ld]" , buflen )
	INFOHEXLOGG( buffer , buflen , "������[%ld]" , buflen )
	WARNHEXLOGG( buffer , buflen , "������[%ld]" , buflen )
	ERRORHEXLOGG( buffer , buflen , "������[%ld]" , buflen )
	FATALHEXLOGG( buffer , buflen , "������[%ld]" , buflen )
	
	DestroyLogHandleG();
	printf( "������־���\n" );
	
	return 0;
}

int main()
{
	return -test_logconf();
}
