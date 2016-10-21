
#include <stdint.h>

#include "log.h"

LOG_MODULE_DEFINE( module1 );

void
module1( void )
{
    const uint8_t x = 255;

    LOG_INFO( "Will log line 9" );
    LOG_VAR_INFO( "Logging uint8_t %u", 1, LOG_TYPE_U8, x );
}
