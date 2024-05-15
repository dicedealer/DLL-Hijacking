// Note that we will compile this to test.exe

#include <windows.h>
#include <stdio.h>

int main (void)
{
    HINSTANCE hDLL;
    //Loading DLL
    hDLL = LoadLibrary(TEXT("example.dll"));

    //Check whether DLL was Loaded or not loaded
    if (hDLL != NULL){
            printf("DLL Found\n");
    } else {
            print("DLL Not Found\n");
    }
return 0;
}
