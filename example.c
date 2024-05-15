// We will compile this to example.dll

#include <windows.h>

BOOL WINAPI
DllMain (Handle hDll, DWORD dwReason, LPVOID lpReserved)

{ 
switch (dwReason){
  case DLL_PROCESS_ATTACH:
    MessageBox(NULL, //Owner
                "The DLL has been loaded", //Message
                "COMPROMISED!!", //Title
                MB_ICONERROR | MB_OK //TYPE
                );
break;
}
return TRUE;
}
