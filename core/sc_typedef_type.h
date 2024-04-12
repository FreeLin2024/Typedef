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

typedef char    varchar_t;
typedef SC_CONF_TYPE_VAR1     var1_t;

typedef SC_CONF_TYPE_VAR8     var8_t;
typedef SC_CONF_TYPE_VAR16    var16_t;
typedef SC_CONF_TYPE_VAR32    var32_t;

typedef SC_CONF_TYPE_SVAR8    svar8_t;
typedef SC_CONF_TYPE_SVAR16   svar16_t;
typedef SC_CONF_TYPE_SVAR32   svar32_t;

typedef SC_CONF_TYPE_VARPTR   varptr_t;
typedef SC_CONF_TYPE_SVARPTR  svarptr_t;

typedef SC_CONF_TYPE_VARMAX   varmax_t;
typedef SC_CONF_TYPE_SVARMAX  svarmax_t;

typedef unsigned int    var_t;
typedef signed int     svar_t;

typedef wchar_t    varwchar_t;
typedef float    varfloat32_t;


typedef double          vardouble_t;    /*主要用于 printf 其他不应该使用 */
typedef long double     varlongdouble_t;


/*============================ var1_t基本宏定义 ============================*/


#if !defined(SC_CONF_TYPE_VAR1_BOOL) || SC_CONF_TYPE_VAR1_BOOL == 0
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ONE     (1U)
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ZERO    (0U)
#else
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ONE     (3U>1U)
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ZERO    (2U>3U)
#endif

/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_TRUE   SC_ONE
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_FALSE  SC_ZERO
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_HIGH   SC_ONE
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_LOW    SC_ZERO
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_OPEN   SC_ONE
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_CLOSE  SC_ZERO

/*============================ var_t基本宏定义 ============================*/

/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VAR_IS_16 (sizeof(var_t) == sizeof(var16_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VAR_IS_32 (sizeof(var_t) == sizeof(var32_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VAR_IS_MAX (sizeof(var_t) == sizeof(varmax_t))

/*============================ varptr_t基本宏定义 ============================*/

/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VARPTR_IS_16 (sizeof(varptr_t) == sizeof(var16_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VARPTR_IS_32 (sizeof(varptr_t) == sizeof(var32_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VARPTR_IS_MAX (sizeof(varptr_t) == sizeof(varmax_t))

/*============================ varmax_t 基本宏定义 ============================*/

#define SC_VARMAX_IS_32 (SC_CONF_64BIT_SUPPORT == 0U)
#define SC_VARMAX_IS_64 (SC_CONF_64BIT_SUPPORT == 1U)


/*============================ 静态检查实现 ============================*/

#define SC_CFG_STATIC_ASSERT_COVER   (-1) /*  覆盖设置  */
#define SC_CFG_STATIC_ASSERT_AUTO    0    /*  自动判断  */
#define SC_CFG_STATIC_ASSERT_GENERAL 1    /*  兼容模式  */
#define SC_CFG_STATIC_ASSERT_LINE    2    /*  LINE模式  */
#define SC_CFG_STATIC_ASSERT_C11     3    /*  C11模式   */

#if defined(SC_STATIC_ASSERT) /*使用已定义的*/
#define SC_CONF_STATIC_ASSERT SC_CFG_STATIC_ASSERT_COVER
#else

#if defined(SC_CONFIG_STATIC_ASSERT) &&                                  \
    SC_CONFIG_STATIC_ASSERT > SC_CFG_STATIC_ASSERT_AUTO &&          \
    SC_CONFIG_STATIC_ASSERT <= SC_CFG_STATIC_ASSERT_C11
#define SC_CONF_STATIC_ASSERT SC_CONFIG_STATIC_ASSERT
#elif defined(__LINE__)
#define SC_CONF_STATIC_ASSERT SC_CFG_STATIC_ASSERT_LINE
#else
#define SC_CONF_STATIC_ASSERT SC_CFG_STATIC_ASSERT_GENERAL
#endif

#if SC_CONF_STATIC_ASSERT == SC_CFG_STATIC_ASSERT_C11
#define SC_CONF_STATIC_ASSERT_CORE  _Static_assert
#endif

#if SC_CONF_STATIC_ASSERT == SC_CFG_STATIC_ASSERT_LINE
#define SC_CFG_STATIC_ASSERT_SRC(in, in_line) typedef void(SC_DEFINE_LINK(*sc_static_assert_fun, in_line)[((svar8_t)(((in) ? 1 : -1)))])(void)
#define SC_CONF_STATIC_ASSERT_CORE(in) SC_CFG_STATIC_ASSERT_SRC(in, __LINE__)
#endif

#if SC_CONF_STATIC_ASSERT == SC_CFG_STATIC_ASSERT_GENERAL
/*注意 该模式静态检查可能不通过 但是是符合 程序设计的 */
#define SC_CONF_STATIC_ASSERT_CORE(in) extern const var8_t sc_static_assert_data[((in) ? 1 : -1)]
#endif

#define SC_STATIC_ASSERT(in)  SC_CONF_STATIC_ASSERT_CORE(in)


#endif


/*============================ 检查 ============================*/

SC_STATIC_ASSERT(sizeof(var1_t) == 1U);

SC_STATIC_ASSERT(sizeof(varchar_t) == 1U);

SC_STATIC_ASSERT(sizeof(var8_t) == 1U);
SC_STATIC_ASSERT(sizeof(svar8_t) == 1U);

SC_STATIC_ASSERT(sizeof(var16_t) == 2U);
SC_STATIC_ASSERT(sizeof(svar16_t) == 2U);

SC_STATIC_ASSERT(sizeof(var32_t) == 4U);
SC_STATIC_ASSERT(sizeof(svar32_t) == 4U);


SC_STATIC_ASSERT(sizeof(svar_t) == sizeof(var_t));

SC_STATIC_ASSERT(sizeof(const void*) == sizeof( void*));

SC_STATIC_ASSERT(sizeof(varptr_t) >= sizeof( void*));
SC_STATIC_ASSERT(sizeof(varptr_t) >= sizeof(ptrdiff_t));
SC_STATIC_ASSERT(sizeof(varptr_t) >= sizeof(size_t));
SC_STATIC_ASSERT(sizeof(varptr_t) >= sizeof(var_t));
SC_STATIC_ASSERT(sizeof(varptr_t) == sizeof(svarptr_t));


SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof(var_t));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof(varfloat32_t));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof(varwchar_t));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof(ptrdiff_t));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof(size_t));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof(long));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof( svar32_t));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof(varptr_t));
SC_STATIC_ASSERT(sizeof(varmax_t) >= sizeof( void*));
SC_STATIC_ASSERT(sizeof(varmax_t) == sizeof(svarmax_t));
SC_STATIC_ASSERT(sizeof(varmax_t) <= 8U);

SC_STATIC_ASSERT(sizeof(varchar_t) == 1U);
SC_STATIC_ASSERT(sizeof(varchar_t) == sizeof(char));

SC_STATIC_ASSERT((sizeof(varwchar_t) == 1U) || (sizeof(varwchar_t) == 2U) || (sizeof(varwchar_t) == 4U )|| (sizeof(varwchar_t) == 8U));

#if defined(SC_CONFIG_WCHAR_SUPPORT)
SC_STATIC_ASSERT(sizeof(varwchar_t) == sizeof(L'\0'));
#endif

SC_STATIC_ASSERT(sizeof(varfloat32_t) == 4U);

#if defined(SC_CONF_LLONG_SUPPORT) && (SC_CONF_LLONG_SUPPORT ==1)
SC_STATIC_ASSERT(sizeof(long long ));
#endif

SC_STATIC_ASSERT((sizeof(var_t) == sizeof(var16_t)) || (sizeof(var_t) == sizeof(var32_t)) || (sizeof(var_t) == sizeof(varmax_t)));

SC_STATIC_ASSERT((sizeof(varmax_t) == 4U) || (sizeof(varmax_t) == 8U));
SC_STATIC_ASSERT(SC_CONF_64BIT_SUPPORT == (sizeof(varmax_t) == 8U));




