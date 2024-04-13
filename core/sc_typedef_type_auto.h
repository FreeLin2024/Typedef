/*cppcheck-suppress-file  misra-c2012-21.1    */

#include "sc_typedef_attribute.h"

/*============================ 库类型基本规则 ============================*/

#define SC_CFG_TYPE_C89                 0                       /* C89头文件 自动判断           */
#define SC_CFG_TYPE_C99                 1                       /* C99头文件 自动判断           */
#define SC_CFG_TYPE_CUSTOM              2                       /* 手动定义数据类型             */

#if defined(SC_CONFIG_TYPE) && SC_CONFIG_TYPE < 4 && SC_CONFIG_TYPE >= 0
#define SC_CONF_TYPE SC_CONFIG_TYPE        /* 接口                  */
#else
#define SC_CONF_TYPE                    0
#endif



/*============================ 有数字的则宏定义 ============================*/

#define SC_VAR1_MAX     (1U)

#define SC_VAR8_MAX     (0XFFU)
#define SC_SVAR8_MAX    (0X7F)
#define SC_SVAR8_MIN    ((-0X7F)-1)

#define SC_VAR16_MAX    (0XFFFFU)
#define SC_SVAR16_MAX   (0X7FFF)
#define SC_SVAR16_MIN   ((-0X7FFF)-1)

#define SC_VAR32_MAX    (0XFFFFFFFFU)
#define SC_SVAR32_MAX   (0X7FFFFFFF)
#define SC_SVAR32_MIN   ((-0X7FFFFFFF)-1)


/*============================ setjmp 标准库 判断 默认不设置 ============================*/
#define SC_CFG_SETJMP_OFF 0
#define SC_CFG_SETJMP_EN  1
#if  (defined(SC_CONFIG_SETJMP)==1 &&  SC_CONFIG_SETJMP == SC_CFG_SETJMP_EN) 
#if !defined(SC_CONFIG_SETJMP_INCLUDE)
#include <setjmp.h>
#endif /*SC_CONFIG_SETJMP_INCLUDE*/
#endif 

/*============================ stddef 标准库 判断 必须支持 ============================*/

#if !defined(SC_CONFIG_STDDEF_INCLUDE)
#include <stddef.h>
#endif /*SC_CONFIG_STDDEF_H*/

/*============================ stdarg 标准库 判断 必须支持 ============================*/

#if !defined(SC_CONFIG_STDARG_INCLUDE)
#include <stdarg.h>
#endif /*SC_CONFIG_STDARG_H*/

/*============================ C99 ============================*/

#if (SC_CONF_TYPE == SC_CFG_TYPE_C99)

#if !defined(__STDC_FORMAT_MACROS)
#define __STDC_FORMAT_MACROS
#endif /*__STDC_FORMAT_MACROS*/
#if !defined(__STDC_LIMIT_MACROS)
#define __STDC_LIMIT_MACROS
#endif /*__STDC_LIMIT_MACROS*/
#if !defined(__STDC_CONSTANT_MACROS)
#define __STDC_CONSTANT_MACROS
#endif /*__STDC_CONSTANT_MACROS*/


#if !defined(SC_CONFIG_STDINT_INCLUDE)
#include <stdint.h>
#endif /*SC_CONFIG_STDINT_INCLUDE*/

#if !defined(SC_CONFIG_STDBOOL_INCLUDE)
#include <stdbool.h>
#endif /*SC_CONFIG_STDINT_INCLUDE*/


#if defined(SC_CONFIG_TYPE_VAR1_BOOL) && SC_CONFIG_TYPE_VAR1_BOOL == 0U
#define SC_CONF_TYPE_VAR1     uint8_t     
#else
#define SC_CONF_TYPE_VAR1_BOOL     1
#define SC_CONF_TYPE_VAR1     bool     
#endif


#define SC_CONF_TYPE_VAR8     uint8_t     
#define SC_CONF_TYPE_VAR16    uint16_t    
#define SC_CONF_TYPE_VAR32    uint32_t    

#define SC_CONF_TYPE_SVAR8    int8_t    
#define SC_CONF_TYPE_SVAR16   int16_t   
#define SC_CONF_TYPE_SVAR32   int32_t   

#define SC_CONF_TYPE_VARPTR   uintptr_t
#define SC_CONF_TYPE_SVARPTR  intptr_t

#define SC_CONF_TYPE_VARMAX   uintmax_t
#define SC_CONF_TYPE_SVARMAX  intmax_t

#endif

/*============================ C89 自动补全 ============================*/

#if !defined(SC_CONF_TYPE_VAR1_BOOL)
#if defined(SC_CONFIG_TYPE_VAR1_BOOL)
#define SC_CONF_TYPE_VAR1_BOOL     SC_CONFIG_TYPE_VAR1_BOOL
#else
#define SC_CONF_TYPE_VAR1_BOOL     0
#endif
#endif

#if !defined(SC_CONF_TYPE_VAR1)
#if defined(SC_CONFIG_TYPE_VAR1)
#define SC_CONF_TYPE_VAR1     SC_CONFIG_TYPE_VAR1
#else
#define SC_CONF_TYPE_VAR1     unsigned char     
#endif
#endif

#if !defined(SC_CONF_TYPE_VAR8)
#if defined(SC_CONFIG_TYPE_VAR8)
#define SC_CONF_TYPE_VAR8     SC_CONFIG_TYPE_VAR8
#else
#define SC_CONF_TYPE_VAR8     unsigned char   
#endif  
#endif  

#if !defined(SC_CONF_TYPE_SVAR8)
#if defined(SC_CONFIG_TYPE_SVAR8)
#define SC_CONF_TYPE_SVAR8    SC_CONFIG_TYPE_SVAR8
#else
#define SC_CONF_TYPE_SVAR8    signed char     
#endif  
#endif  

#if !defined(SC_CONF_TYPE_VAR16)
#if defined(SC_CONFIG_TYPE_VAR16)
#define SC_CONF_TYPE_VAR16    SC_CONFIG_TYPE_VAR16
#else
#define SC_CONF_TYPE_VAR16    unsigned short    
#endif  
#endif  

#if !defined(SC_CONF_TYPE_SVAR16)
#if defined(SC_CONFIG_TYPE_SVAR16)
#define SC_CONF_TYPE_SVAR16    SC_CONFIG_TYPE_SVAR16
#else
#define SC_CONF_TYPE_SVAR16    signed short      
#endif  
#endif  



#if SC_CONF_TYPE == SC_CFG_TYPE_C89 \
    ||(!defined(SC_CONF_TYPE_VAR32) && !defined(SC_CONFIG_TYPE_VAR32))\
    ||(!defined(SC_CONF_TYPE_SVAR32) && !defined(SC_CONFIG_TYPE_SVAR32))\
    ||(!defined(SC_CONF_TYPE_VARPTR) && !defined(SC_CONFIG_TYPE_VARPTR))\
    ||(!defined(SC_CONF_TYPE_SVARPTR) && !defined(SC_CONFIG_TYPE_SVARPTR))\
    ||(!defined(SC_CONF_TYPE_SVARMAX) && !defined(SC_CONFIG_TYPE_SVARMAX))\
    ||(!defined(SC_CONF_TYPE_VARMAX) && !defined(SC_CONFIG_TYPE_VARMAX))

#if !defined(SC_CONFIG_LIMITS_INCLUDE)
#include <limits.h>
#endif /*SC_CONFIG_LIMITS_INCLUDE*/



#if (defined(SC_CONFIG_LLONG_SUPPORT) && SC_CONFIG_LLONG_SUPPORT != 0U) \
    || defined(LLONG_MIN) || defined(LLONG_MAX) || defined(ULLONG_MAX)  \
    || defined(LONG_LONG_MAX) || defined(LONG_LONG_MIN)|| defined(ULONG_LONG_MAX)
#define SC_CONF_LLONG_SUPPORT 1
#endif

#endif  



#if !defined(SC_CONF_TYPE_VAR32)
#if defined(SC_CONFIG_TYPE_VAR32)
#define SC_CONF_TYPE_VAR32    SC_CONFIG_TYPE_VAR32
#else

#if   INT_MAX == SC_SVAR32_MAX
#define SC_CONF_TYPE_VAR32    unsigned int
#elif LONG_MAX == SC_SVAR32_MAX
#define SC_CONF_TYPE_VAR32    unsigned long
#else
#define SC_CONF_TYPE_VAR32    unsigned long long
#endif 

#endif  
#endif  


#if !defined(SC_CONF_TYPE_SVAR32)
#if defined(SC_CONFIG_TYPE_SVAR32)
#define SC_CONF_TYPE_SVAR32    SC_CONFIG_TYPE_SVAR32
#else

#if   INT_MAX == SC_SVAR32_MAX
#define SC_CONF_TYPE_SVAR32    signed int
#elif LONG_MAX == SC_SVAR32_MAX
#define SC_CONF_TYPE_SVAR32    signed long
#else
#define SC_CONF_TYPE_SVAR32    signed long long
#endif 


#endif  
#endif  


#if !defined(SC_CONF_TYPE_VARMAX)
#if defined(SC_CONFIG_TYPE_VARMAX)
#define SC_CONF_TYPE_VARMAX    SC_CONFIG_TYPE_VARMAX
#else

#if defined(SC_CONF_LLONG_SUPPORT)
#define SC_CONF_TYPE_VARMAX    unsigned long long
#else
#define SC_CONF_TYPE_VARMAX    unsigned long 
#endif

#endif  
#endif  

#if !defined(SC_CONF_TYPE_SVARMAX)
#if defined(SC_CONFIG_TYPE_SVARMAX)
#define SC_CONF_TYPE_SVARMAX    SC_CONFIG_TYPE_SVARMAX
#else

#if defined(SC_CONF_LLONG_SUPPORT)
#define SC_CONF_TYPE_SVARMAX    signed long long
#else
#define SC_CONF_TYPE_SVARMAX    signed long 
#endif

#endif  
#endif  



#if !defined(SC_CONF_TYPE_VARPTR)
#if defined(SC_CONFIG_TYPE_VARPTR)
#define SC_CONF_TYPE_VARPTR    SC_CONFIG_TYPE_VARPTR
#else

#define SC_CONF_TYPE_VARPTR    SC_CONF_TYPE_VARMAX

#endif  
#endif  

#if !defined(SC_CONF_TYPE_SVARPTR)
#if defined(SC_CONFIG_TYPE_SVARPTR)
#define SC_CONF_TYPE_SVARPTR    SC_CONFIG_TYPE_SVARPTR
#else

#define SC_CONF_TYPE_SVARPTR    SC_CONF_TYPE_SVARMAX

#endif  
#endif  

/*============================ 64位支持定义 ============================*/

#if defined(SC_CONFIG_64BIT_SUPPORT)
#define SC_CONF_64BIT_SUPPORT    SC_CONFIG_64BIT_SUPPORT
#else
#if (defined(INTMAX_MAX) && (INTMAX_MAX  >  SC_SVAR32_MAX))||\
    (defined(LONG_LONG_MAX) && (LONG_LONG_MAX  >  SC_SVAR32_MAX) )||\
    (defined(LLONG_MAX) && (LLONG_MAX  >  SC_SVAR32_MAX) )||\
    (defined(LONG_MAX) && (LONG_MAX  >  SC_SVAR32_MAX) )
#define SC_CONF_64BIT_SUPPORT    1U
#else
#define SC_CONF_64BIT_SUPPORT    0U
#endif  
#endif  




/*============================ 定义 ============================*/

#define  SC_CONF_TYPE_CHAR          char
#define  SC_CONF_TYPE_VAR           unsigned int
#define  SC_CONF_TYPE_SVAR          signed int

#define  SC_CONF_TYPE_WCHAR         wchar_t
#define  SC_CONF_TYPE_FLOAT         float
#define  SC_CONF_TYPE_DOUBLE        double
#define  SC_CONF_TYPE_LONG_DOUBLE   long double






