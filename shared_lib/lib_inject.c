#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>

int printf(const char *format, ...) {
    static int (*real_vprintf)(const char *, va_list) = NULL;
    if (!real_vprintf)
        real_vprintf = dlsym(RTLD_NEXT, "vprintf");

    fputs("[+] Intercepted printf: ", stderr);
    fputs(format, stderr);


    va_list args;
    va_start(args, format);
    int ret = real_vprintf(format, args);
    va_end(args);
    return ret;
}

