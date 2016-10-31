
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"

void
log_printf( uint8_t level, uint32_t module, uint32_t line, uint8_t nArgs, ... )
{
    printf( "^%"PRIu8",%"PRIu32",%"PRIu32",%"PRIu8",", level, module, line, nArgs );

    if ( nArgs > 0 )
    {
        int i;
        va_list vl;

        va_start( vl, nArgs );
        for ( i = 0; i < (2*nArgs); i += 2 )
        {
            uint8_t type = (uint8_t)va_arg( vl, uint32_t );
            printf( "%"PRIu8",", type );

            switch ( type )
            {
                case LOG_TYPE_U8:   printf( "%"PRIu8,   (uint8_t) va_arg( vl, uint32_t ) ); break;
                case LOG_TYPE_U16:  printf( "%"PRIu16,  (uint16_t)va_arg( vl, uint32_t ) ); break;
                case LOG_TYPE_U32:  printf( "%"PRIu32,  (uint32_t)va_arg( vl, uint32_t ) ); break;
                case LOG_TYPE_S8:   printf( "%"PRId8,   (int8_t)  va_arg( vl, int32_t  ) ); break;
                case LOG_TYPE_S16:  printf( "%"PRId16,  (int16_t) va_arg( vl, int32_t  ) ); break;
                case LOG_TYPE_S32:  printf( "%"PRId32,  (int32_t) va_arg( vl, int32_t  ) ); break;
                case LOG_TYPE_STR:  printf( "\\^%s\\$", (char*)   va_arg( vl, char*    ) ); break;
                case LOG_TYPE_BOOL: printf( "%"PRIu8,   (uint8_t) va_arg( vl, uint32_t ) ); break;
                default: assert( 0 ); break;
            }

            putchar( ',' );
        }
        va_end( vl );
    }

    fputs( "\r\n", stdout );
}
