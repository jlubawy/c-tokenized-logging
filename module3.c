
#include "log.h"

LOG_MODULE_DEFINE( module3 );

#define TRUE  (1)
#define FALSE !(TRUE)

void
module3( void )
{
    LOG_ERROR(
        "Should log line 11"
    );

    LOG_VAR_ERROR( "Logging bool %u", 1, LOG_TYPE_BOOL, FALSE );
}
