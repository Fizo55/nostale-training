#include <iostream>
#include "PatternScan.hpp"
#include "Protocols.hpp"
#include "Memhack.hpp"

int main()
{
    DWORD processID = GetProcID("latest-localhost.exe");

    if (processID == NULL) {
        std::cerr << "Failed to get process id." << std::endl;
        return 1;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, processID);
    if (hProcess == INVALID_HANDLE_VALUE || hProcess == NULL) {
        std::cerr << "Failed to open process." << std::endl;
        return  1;
    }

    char hp_pattern[] = "\x89\x43\x00\x8b\x53\x00\x3b\xc2";
    char hp_mask[] = "xx?xx?xx";

    void *address = PatternScanExModule(hProcess, "latest-localhost.exe", "latest-localhost.exe", hp_pattern, hp_mask);

    if (address) {
        NopEx(hProcess, address, 8),
        std::cout << "Pattern found at address: 0x" << std::hex << address << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }

    CloseHandle(hProcess);
    return 0;
}
