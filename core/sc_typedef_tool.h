#include "sc_typedef_conf.h"
/*============================ 定义未使用的数据 ============================*/


#if defined(SC_CONFIG_UNUSED)
#define SC_UNUSED(in) SC_CONFIG_UNUSED(in)
#else
#define SC_UNUSED(in) ((void)(in))
#endif 

/*============================      定义常量    ============================*/

#if defined(SC_CONFIG_CONST)
#define SC_CONST SC_CONFIG_CONST
#else
#define SC_CONST
#endif 


/*============================ 定义函数取地址方式  ============================*/

#if defined(SC_CONFIG_ADDRFUN) && (SC_CONFIG_ADDRFUN == 1)
#define SC_ADDRFUN(fun) (fun)
#else
/*默认为这个 意思明确 */
#define SC_ADDRFUN(fun) (&(fun))
#endif



/*============================ 定义宏定义规则 ============================*/


/*cppcheck-suppress misra-c2012-20.10   */ /* 直接将输入的字符 转化为字符串 */
#define SC_DEFINE_SHOW_STR(in_str) #in_str

/*cppcheck-suppress misra-c2012-20.10   */ /*连接2个参数*/
#define SC_DEFINE_LINK(x, y) x##y

/*cppcheck-suppress misra-c2012-20.7    */ /* 参数 不带括号 */
#define SC_DEFINE_ONLY(x) x

/* 将输入的参数 经过一定的变化后 再转化为字符串 */
#define SC_DEFINE_SHOW_ARG_STR(x) SC_DEFINE_SHOW_STR(x)



