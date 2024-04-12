#include "sc_typedef_tool.h"

#if defined(SC_CONFIG_ATT) && (SC_CONFIG_ATT == 1U)

/*函数指针参数不能为空 */
#define SC_ATT_NONNULL(x)   __attribute__((nonnull SC_DEFINE_ONLY(x)))

/*函数返回值不能被抛弃 */
#define SC_ATT_NODISCARD  __attribute__((warn_unused_result))

/*声明的函数将不会返回空指针 */
#define SC_ATT_RET_NONNULL  __attribute__((returns_nonnull))/* __attribute__((_Nullable_result))*/

/*声明的函数将不会返回 */
#define SC_ATT_RET_NORETURN __attribute__((noreturn))

/*alloc_size(N)表示参数number N等于返回指针的可用字节数。alloc_size(N, M)表示参数N和参数M的乘积等于返回指针的可用字节数。 */
#define SC_ATT_ALLOC_SIZE(x)  __attribute__((alloc_size SC_DEFINE_ONLY(x)))

/*malloc属性表明该函数的行为类似于系统内存分配函数，返回一个指向已分配存储的指针，该存储与调用者可访问的任何其他对象的存储不相连。*/
#define SC_ATT_MALLOC  __attribute__((malloc))


/* 主要用于 带参的回调函数 
下面是2种使用实例
__attribute__((callback (start_routine, arg)))
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
__attribute__((callback (3, 4)))
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
callback属性直接转换为回调元数据<http:--llvm.org/docs/LangRef.html#callback-metadata>，
在对带注释的函数的调用和回调被调用方之间建立连接。这可以实现程序间优化，否则是不可能的。
*/
#define SC_ATT_CALLBACK(x)  __attribute__((callback SC_DEFINE_ONLY(x)))

#else

#define SC_ATT_NONNULL(x)  
#define SC_ATT_NODISCARD  
#define SC_ATT_RET_NONNULL 
#define SC_ATT_RET_NORETURN 
#define SC_ATT_ALLOC_SIZE(x)
#define SC_ATT_MALLOC
#define SC_ATT_CALLBACK(x)


#endif







