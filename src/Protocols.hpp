#ifndef PROTOCOLS_HPP
#define PROTOCOLS_HPP

#include <Windows.h>
#include <TlHelp32.h>

DWORD GetProcID(char *exeName);
MODULEENTRY32 GetModule(DWORD dwProcID, char *moduleName);

#endif //PROTOCOLS_HPP
