#include <stdio.h>

int main() {
#ifdef _WIN32
    printf("_WIN32 is defined. Running on Windows.\n");
#else
    printf("_WIN32 is NOT defined. Running on Linux/Mac.\n");
#endif
    return 0;
}

