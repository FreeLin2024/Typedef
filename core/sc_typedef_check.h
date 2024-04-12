/*cppcheck-suppress-file  misra-c2012-20.4    */
/*cppcheck-suppress-file  misra-c2012-21.1    */
/*cppcheck-suppress-file  misra-c2012-20.7    */
#include "sc_typedef_type.h"


/*============================ 强制转换 定义 ============================*/
#if defined(SC_CONFIG_TYPE_CAST) && SC_CONFIG_TYPE_CAST != 0
#define SC_REINTERPRET_CAST(x,y)    (reinterpret_cast<x>(y))
#define SC_CONST_CAST(x,y)          (const_cast<x>(y))
#define SC_STATIC_CAST(x,y)         (static_cast<x>(y))
#else
#define SC_REINTERPRET_CAST(x,y)    ((x)(y))
#define SC_CONST_CAST(x,y)          ((x)(y))
#define SC_STATIC_CAST(x,y)         ((x)(y))
#endif


/*============================ restrict ============================*/

#if defined(SC_CONFIG_RESTRICT_SET)
#define SC_RESTRICT             SC_CONFIG_RESTRICT_SET
#else
#if defined(SC_CONFIG_RESTRICT) && SC_CONFIG_RESTRICT != 0
/*cppcheck-suppress  misra-c2012-8.14    */
#define SC_RESTRICT             restrict
#else
#define SC_RESTRICT     
/*cppcheck-suppress  misra-c2012-8.14    */
#define restrict                SC_STATIC_ASSERT(0)
/*#define __restrict              SC_STATIC_ASSERT(0)*/
#endif
#endif

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

