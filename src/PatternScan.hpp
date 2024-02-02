#ifndef PATTERN_SCANNER_HPP
#define PATTERN_SCANNER_HPP

#include <Windows.h>
#include <TlHelp32.h>

void *PatternScan(char *base, size_t size, char *pattern, char *mask);

void *PatternScanEx(HANDLE hProcess, uintptr_t begin, uintptr_t end, char *pattern, char *mask);

void *PatternScanExModule(HANDLE hProcess, char *exeName, char *module, char *pattern, char *mask);

#endif // PATTERN_SCANNER_HPP
