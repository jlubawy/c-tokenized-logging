
#include "module1.h"
#include "module2.h"
#include "module3.h"

#include "log.h"

LOG_MODULE_DEFINE( main );

int
main( void )
{
    LOG_INFO( "In main, line 13" );
    module1();
    module2();
    module3();
}
