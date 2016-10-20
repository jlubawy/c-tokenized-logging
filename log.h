
#ifndef LOG_H
#define LOG_H

#include <stdint.h>
#include <stdio.h>

#include "log_modules.h"

/* Logging levels */
#define LOG_LEVEL_INFO     (0x00)
#define LOG_LEVEL_WARNING  (0x01)
#define LOG_LEVEL_ERROR    (0x02)

/* Type definitions */
#define LOG_TYPE_U8    (0x00)
#define LOG_TYPE_U16   (0x01)
#define LOG_TYPE_U32   (0x02)
#define LOG_TYPE_S8    (0x03)
#define LOG_TYPE_S16   (0x04)
#define LOG_TYPE_S32   (0x05)
#define LOG_TYPE_STR   (0x06)
#define LOG_TYPE_BOOL  (0x07)

#define LOG_MODULE_DEFINE( _name )  static uint32_t _log_module = LOG_MODULE_##_name

void
log_printf( uint8_t level, uint32_t module, uint32_t line, uint8_t nArgs, ... );

#define _LOG_BASE( _level, _nArgs, ... )  (log_printf( LOG_LEVEL_##_level, _log_module, __LINE__, _nArgs, __VA_ARGS__ ))
#define _LOG_BASE_0( _level )  (_LOG_BASE( _level, 0, NULL ))

/* String only */
#define LOG_INFO( _str )     (_LOG_BASE_0( INFO    ))
#define LOG_WARNING( _str )  (_LOG_BASE_0( WARNING ))
#define LOG_ERROR( _str )    (_LOG_BASE_0( ERROR   ))

/* Printf like macros */
#define LOG_VAR_INFO( _str, _nArgs, ... )     (_LOG_BASE( INFO,    _nArgs, __VA_ARGS__ ))
#define LOG_VAR_WARNING( _str, _nArgs, ... )  (_LOG_BASE( WARNING, _nArgs, __VA_ARGS__ ))
#define LOG_VAR_ERROR( _str, _nArgs, ... )    (_LOG_BASE( ERROR,   _nArgs, __VA_ARGS__ ))

#endif
