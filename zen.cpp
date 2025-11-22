#include <iostream>

// Detect C++ standard version

#if __cplusplus >= 201703L
#define CPP_VERSION "C++17 or later"
#else
#define CPP_VERSION "Before C++17"
#endif

// Detect compiler

#if defined(__GNUC__)
#define COMPILER "GCC"
#elif defined(__clang__)
#define COMPILER "Clang"
#elif defined(_MSC_VER)
#define COMPILER "MSVC"
#endif

// Detect operating system

#if defined(__linux__)
#define OS "Linux"
#elif defined(_WIN32)
#define OS "Windows"
#elif defined(__APPLE__)
#define OS "macOS"
#endif

// Define NODISCARD attribute based on compiler support

#if defined(__has_cpp_attribute)
#elif __has_cpp_attribute(nodiscard)
#define NODISCARD [[nodiscard]]
#elif __has_cpp_attribute(clang::nodiscard)
#define NODISCARD [[clang::nodiscard]]
#endif

// Fallback definitions if NODISCARD is not defined yet

#if !defined(NODISCARD)
#elif defined(__GNUC__) || defined(__clang__)
#define NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
#define NODISCARD _Check_return__
#else
#define NODISCARD
#endif

int main()
{
    std::cout << "C++ Version: " << CPP_VERSION << std::endl;
    std::cout << "Compiler: " << COMPILER << std::endl;
    std::cout << "Operating System: " << OS << std::endl;
    return 0;
}