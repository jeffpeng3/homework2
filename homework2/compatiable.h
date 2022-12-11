#pragma once
#ifdef __linux__
#define scanf_s(format,...) scanf(format,__VA_ARGS__)
#define clearOutput() system("clear")
#elif _WIN32
#define clearOutput() system("cls")
#else
#error Platform not supported
#endif

