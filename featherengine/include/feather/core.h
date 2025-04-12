#ifdef COMPILER_MSVC
    #define FT_DEBUG_BREAK() __debugbreak()
#else
    #define FT_DEBUG_BREAK() __builtin_trap()
#endif