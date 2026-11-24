#ifndef MAT_LIB_H
#define MAT_LIB_H

#include <stdio.h>

#define MAT_LIB_VERSION "1.0.0"

#ifdef DEBUG
#define LOG(message) printf("[DEBUG] %s\n", message)
#else
#define LOG(message) ((void)0)
#endif

int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);

#endif // MAT_LIB_H