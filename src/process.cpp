#include "process.hpp"
#include <Windows.h>
#include <tlhelp32.h>
#include <string>

namespace process {

    bool isRunning(const char* processName) {

        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        if (snapshot == INVALID_HANDLE_VALUE)
            return false;

        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(entry);

        if (!Process32First(snapshot, &entry)) {
            CloseHandle(snapshot);
            return false;
        }

        do {

            // so sánh tên process
            if (_stricmp(entry.szExeFile, processName) == 0) {
                CloseHandle(snapshot);
                return true;
            }

        } while (Process32Next(snapshot, &entry));

        CloseHandle(snapshot);
        return false;
    }

}