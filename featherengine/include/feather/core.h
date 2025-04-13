#ifdef COMPILER_MSVC
    #define FT_DEBUG_BREAK() __debugbreak()
#else
    #define FT_DEBUG_BREAK() __builtin_trap()
#endif

#ifdef _WIN32
    #ifdef FT_BUILD_DLL
        #define FEATHER_API __declspec(dllexport)
    #else
        #define FEATHER_API __declspec(dllimport)
    #endif
#else
    #define FEATHER_API
#endif