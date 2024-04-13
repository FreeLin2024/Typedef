
#include "sc_typedef_type_auto.h"

/*============================ var1_t基本宏定义 ============================*/


#if !defined(SC_CONF_TYPE_VAR1_BOOL) || SC_CONF_TYPE_VAR1_BOOL == 0
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ONE                     (1U)
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ZERO                    (0U)
#else
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ONE                     (3U>1U)
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_ZERO                    (2U>3U)
#endif

/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_TRUE                    SC_ONE
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_FALSE                   SC_ZERO
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_HIGH                    SC_ONE
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_LOW                     SC_ZERO
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_OPEN                    SC_ONE
/*cppcheck-suppress-macro [misra-c2012-10.4,misra-c2012-10.3]*/
#define  SC_CLOSE                   SC_ZERO

/*============================ var_t基本宏定义 ============================*/

/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VAR_IS_16                (sizeof(var_t) == sizeof(var16_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VAR_IS_32                (sizeof(var_t) == sizeof(var32_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VAR_IS_MAX               (sizeof(var_t) == sizeof(varmax_t))

/*============================ varptr_t基本宏定义 ============================*/

/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VARPTR_IS_16             (sizeof(varptr_t) == sizeof(var16_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VARPTR_IS_32             (sizeof(varptr_t) == sizeof(var32_t))
/*cppcheck-suppress-macro  misra-config    */ /*老是误报  添加加上*/
#define SC_VARPTR_IS_MAX            (sizeof(varptr_t) == sizeof(varmax_t))

/*============================ varmax_t 基本宏定义 ============================*/

#define SC_VARMAX_IS_32             (SC_CONF_64BIT_SUPPORT == 0U)
#define SC_VARMAX_IS_64             (SC_CONF_64BIT_SUPPORT == 1U)

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
#define SC_RESTRICT                 SC_CONFIG_RESTRICT_SET
#else
#if defined(SC_CONFIG_RESTRICT) && SC_CONFIG_RESTRICT != 0
/*cppcheck-suppress  misra-c2012-8.14    */
#define SC_RESTRICT                 restrict
#else
#define SC_RESTRICT     
/*cppcheck-suppress  misra-c2012-8.14    */
#define restrict                    SC_STATIC_ASSERT(0)
/*#define __restrict                SC_STATIC_ASSERT(0)*/
#endif
#endif

/*============================ 定义 ============================*/

typedef SC_CONF_TYPE_CHAR           varchar_t;
typedef SC_CONF_TYPE_VAR1           var1_t;

typedef SC_CONF_TYPE_VAR8           var8_t;
typedef SC_CONF_TYPE_VAR16          var16_t;
typedef SC_CONF_TYPE_VAR32          var32_t;

typedef SC_CONF_TYPE_SVAR8          svar8_t;
typedef SC_CONF_TYPE_SVAR16         svar16_t;
typedef SC_CONF_TYPE_SVAR32         svar32_t;

typedef SC_CONF_TYPE_VARPTR         varptr_t;
typedef SC_CONF_TYPE_SVARPTR        svarptr_t;

typedef SC_CONF_TYPE_VARMAX         varmax_t;
typedef SC_CONF_TYPE_SVARMAX        svarmax_t;

typedef SC_CONF_TYPE_VAR            var_t;
typedef SC_CONF_TYPE_SVAR           svar_t;

typedef SC_CONF_TYPE_WCHAR          varwchar_t;
typedef SC_CONF_TYPE_FLOAT          varfloat32_t;


typedef SC_CONF_TYPE_DOUBLE         vardouble_t;
typedef SC_CONF_TYPE_LONG_DOUBLE    varlongdouble_t;



/*============================ 快速指针 定义 ============================*/

/*  用 typedef 失败 改用 宏定义 */

/*  restrict 关键字用于告诉编译器，对象已经被指针所引用，
    不能通过除该指针外所有其他直接或间接的方式
    修改该对象的内容 修改该对象的内容 修改该对象的内容
    （并非强制性的规定，即用了其他指针访问该内存空间也不会报错）。
    对于有些编译器必须开到一定的优化等级 才会 使 restrict 关键字 生效 */
#define varchar_pfast_t     varchar_t*      SC_RESTRICT
#define var1_pfast_t        var1_t*         SC_RESTRICT

#define var8_pfast_t        var8_t*         SC_RESTRICT
#define var16_pfast_t       var16_t*        SC_RESTRICT
#define var32_pfast_t       var32_t*        SC_RESTRICT

#define svar8_pfast_t       svar8_t*        SC_RESTRICT
#define svar16_pfast_t      svar16_t*       SC_RESTRICT
#define svar32_pfast_t      svar32_t*       SC_RESTRICT

#define varptr_pfast_t      varptr_t*       SC_RESTRICT
#define svarptr_pfast_t     svarptr_t*      SC_RESTRICT

#define varmax_pfast_t      varmax_t*       SC_RESTRICT
#define svarmax_pfast_t     svarmax_t*      SC_RESTRICT

#define var_pfast_t         var_t*          SC_RESTRICT
#define svar_pfast_t        svar_t*         SC_RESTRICT

#define varwchar_pfast_t    varwchar_t*     SC_RESTRICT
#define varfloat_pfast_t    varfloat32_t*   SC_RESTRICT

/*============================ 定义常量 ============================*/

#define varchar_code_t     const varchar_t       SC_CONST
#define var1_code_t        const var1_t          SC_CONST

#define var8_code_t        const var8_t          SC_CONST
#define var16_code_t       const var16_t         SC_CONST
#define var32_code_t       const var32_t         SC_CONST

#define svar8_code_t       const svar8_t         SC_CONST
#define svar16_code_t      const svar16_t        SC_CONST
#define svar32_code_t      const svar32_t        SC_CONST

#define varptr_code_t      const varptr_t        SC_CONST
#define svarptr_code_t     const svarptr_t       SC_CONST

#define varmax_code_t      const varmax_t        SC_CONST
#define svarmax_code_t     const svarmax_t       SC_CONST

#define var_code_t         const var_t           SC_CONST
#define svar_code_t        const svar_t          SC_CONST

#define varwchar_code_t    const varwchar_t      SC_CONST
#define varfloat_code_t    const varfloat32_t    SC_CONST




