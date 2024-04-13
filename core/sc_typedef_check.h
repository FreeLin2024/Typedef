/*cppcheck-suppress-file  misra-c2012-20.4    */
/*cppcheck-suppress-file  misra-c2012-21.1    */
/*cppcheck-suppress-file  misra-c2012-20.7    */
#include "sc_typedef_type.h"


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

#if defined(SC_CONF_LLONG_SUPPORT)
SC_STATIC_ASSERT(sizeof(long long ));
#endif

SC_STATIC_ASSERT((sizeof(var_t) == sizeof(var16_t)) || (sizeof(var_t) == sizeof(var32_t)) || (sizeof(var_t) == sizeof(varmax_t)));

SC_STATIC_ASSERT((sizeof(varmax_t) == 4U) || (sizeof(varmax_t) == 8U));
SC_STATIC_ASSERT(SC_CONF_64BIT_SUPPORT == (sizeof(varmax_t) == 8U));





/*============================ 禁止使用 检查 列表 ============================*/

#if defined(SC_CONFIG_USE_CHECKLISTS) && SC_CONFIG_USE_CHECKLISTS == 1U

/*--------------  C 关键字   --------------*/

#define register            SC_STATIC_ASSERT(0)
#define int                 SC_STATIC_ASSERT(0)
#define char                SC_STATIC_ASSERT(0)
#define short               SC_STATIC_ASSERT(0)
#define long                SC_STATIC_ASSERT(0)
#define float               SC_STATIC_ASSERT(0)
#define double              SC_STATIC_ASSERT(0)

#define unsigned            SC_STATIC_ASSERT(0)
#define signed              SC_STATIC_ASSERT(0)


/*--------------  C 额外关键字   --------------*/

#define ptrdiff_t           SC_STATIC_ASSERT(0)
#define size_t              SC_STATIC_ASSERT(0)
#define wchar_t             SC_STATIC_ASSERT(0)

/*--------------  C 默认关键字   --------------*/
#define auto                SC_STATIC_ASSERT(0)


#define _Bool               SC_STATIC_ASSERT(0)
#define _Complex            SC_STATIC_ASSERT(0)
#define _Imaginary          SC_STATIC_ASSERT(0)
#define inline              SC_STATIC_ASSERT(0)


#define _Alignas            SC_STATIC_ASSERT(0)
#define _Alignof            SC_STATIC_ASSERT(0)
#define _Atomic             SC_STATIC_ASSERT(0)
#define _Generic            SC_STATIC_ASSERT(0)
#define _Noreturn           SC_STATIC_ASSERT(0)
#define _Static_assert      SC_STATIC_ASSERT(0)
#define _Thread_local       SC_STATIC_ASSERT(0)


/*--------------  C 额外   --------------*/
#define typeof(x)           SC_STATIC_ASSERT(0)
#define asm                 SC_STATIC_ASSERT(0)


/*--------------  keilC51 相关  --------------*/
#define _at_                SC_STATIC_ASSERT(0)
#define alien               SC_STATIC_ASSERT(0)
#define bdata               SC_STATIC_ASSERT(0)
#define bit                 SC_STATIC_ASSERT(0)
#define code                SC_STATIC_ASSERT(0)
#define compact             SC_STATIC_ASSERT(0)
#define data                SC_STATIC_ASSERT(0)
#define far                 SC_STATIC_ASSERT(0)
#define idata               SC_STATIC_ASSERT(0)
#define interrupt           SC_STATIC_ASSERT(0)
#define large               SC_STATIC_ASSERT(0)
#define pdata               SC_STATIC_ASSERT(0)
#define _priority_          SC_STATIC_ASSERT(0)
#define reentrant           SC_STATIC_ASSERT(0)
#define sbit                SC_STATIC_ASSERT(0)
#define sfr                 SC_STATIC_ASSERT(0)
#define sfr16               SC_STATIC_ASSERT(0)
#define small               SC_STATIC_ASSERT(0)
#define _task_              SC_STATIC_ASSERT(0)
#define using               SC_STATIC_ASSERT(0)
#define xdata               SC_STATIC_ASSERT(0)


/*--------------  C++ 默认关键字   --------------*/
#define new                 SC_STATIC_ASSERT(0)
#define this                SC_STATIC_ASSERT(0)
#define operator            SC_STATIC_ASSERT(0)
#define throw               SC_STATIC_ASSERT(0)
#define bool                SC_STATIC_ASSERT(0)
#define explicit            SC_STATIC_ASSERT(0)
#define private             SC_STATIC_ASSERT(0)
#define true                SC_STATIC_ASSERT(0)
#define export              SC_STATIC_ASSERT(0)
#define protected           SC_STATIC_ASSERT(0)
#define try                 SC_STATIC_ASSERT(0)
#define public              SC_STATIC_ASSERT(0)
#define catch               SC_STATIC_ASSERT(0)
#define false               SC_STATIC_ASSERT(0)
#define typeid              SC_STATIC_ASSERT(0)
#define class               SC_STATIC_ASSERT(0)
#define friend              SC_STATIC_ASSERT(0)
#define virtual             SC_STATIC_ASSERT(0)
#define delete              SC_STATIC_ASSERT(0)
#define mutable             SC_STATIC_ASSERT(0)
#define dynamic_cast        SC_STATIC_ASSERT(0)
#define namespace           SC_STATIC_ASSERT(0)
#define template            SC_STATIC_ASSERT(0)

#endif  

