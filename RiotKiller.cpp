#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <iostream>

void startup(LPTSTR lpApplicationName ) {
   // additional information
   STARTUPINFO si;     
   PROCESS_INFORMATION pi;

   // set the size of the structures
   ZeroMemory( &si, sizeof(si) );
   si.cb = sizeof(si);
   ZeroMemory( &pi, sizeof(pi) );
   
  //--launch-product=league_of_legends --launch-patchline=live
  // start the program up
  CreateProcess( NULL,   // the path
    lpApplicationName,        // Command line
    NULL,           // Process handle not inheritable
    NULL,           // Thread handle not inheritable
    FALSE,          // Set handle inheritance to FALSE
    0,              // No creation flags
    NULL,           // Use parent's environment block
    NULL,           // Use parent's starting directory 
    &si,            // Pointer to STARTUPINFO structure
    &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
    );
    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}

bool IsProcessRunning(const TCHAR* const executableName) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (!Process32First(snapshot, &entry)) {
        CloseHandle(snapshot);
        return false;
    }

    do {
        if (!_tcsicmp(entry.szExeFile, executableName)) {
            CloseHandle(snapshot);
            return true;
        }
    } while (Process32Next(snapshot, &entry));

    CloseHandle(snapshot);
    return false;
}

void kill(const char *filename) {
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof (pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (strcmp(pEntry.szExeFile, filename) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                                          (DWORD) pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

bool launchLol() {
   std::cout << "Starting League of Legends. Waiting 30 seconds for it to be open...\n" << std::endl;

   char lol[] = "C:\\Riot Games\\Riot Client\\RiotClientServices.exe --launch-product=league_of_legends --launch-patchline=live";
   startup(lol);
   
   // set number of attempts at checking for lol launch
   int attempts=30; 
   for (int i = 1; i <= attempts; i++) {
      //std::cout << "Attempt " + std::to_string(i) << std::endl;
      if (IsProcessRunning("LeagueClientUx.exe")) {
         return true;
      }
      Sleep(1000);
   }
   return false;
}

int main() {

   if (launchLol()) {
        std::cout << "League of Legends has been started!" << std::endl;
        std::cout << "Once you close LoL, it will attempt to kill RiotClient before it spawns.\n" << std::endl;
        std::cout << "DON'T CLOSE ME. Just keep me minimized and I will do the trick.\n" << std::endl;
   } else {
       std::cout << "League never launched successfully :(\n" << std::endl;
       system("pause");
       return 0;
   }
   
   // checking for LeagueClientUx instead of LeagueClient because it will
   // shutdown earlier and chances of killing riot client sooner are greater.
   while(IsProcessRunning("LeagueClientUx.exe")) {
      //std::cout << "League of Legends check" << std::endl;
      Sleep(1000);
   }

   std::cout << "League of Legends has been closed! Killing RiotClient..." << std::endl;
   kill("LeagueClient.exe");
   kill("RiotClientServices.exe");
   std::cout << "SUCCESS. gg ez.\n" << std::endl;
   Sleep(2000);

   return 0;
}
