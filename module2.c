
#include "log.h"

LOG_MODULE_DEFINE( module2 );

void
module2( void )
{
    LOG_WARNING( "Will log line 9" );

    LOG_VAR_WARNING( "Logging string %s", 1, LOG_TYPE_STR, "module2" );
}
