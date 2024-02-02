#ifndef MEMHACK_HPP
#define MEMHACK_HPP

#include <Windows.h>

void Patch(void *dst, void *src, unsigned int size);

void PatchEx(HANDLE hProcess, void *dst, void *src, unsigned int size);

void Nop(HANDLE hProcess, void *dest, unsigned int size);

void NopEx(HANDLE hProcess, void *dst, unsigned int size);

#endif //MEMHACK_HPP
