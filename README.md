# DLL-Hijacking
We will perform DLL hijacking on some applications and also detect it using Volatility.

# Step-1 : Understanding how a DLL is loaded
We start off by creating a basic application and a DLL that displays a custom message box when loaded.
We then place both of them in the same directory on a windows VM (Make sure to turn off your Windows defender).

Now we execute the application and see the results. This is how a DLL is loaded:

![Screenshot_8](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/1dff3e98-60fa-4763-85f0-3f7623ce1670)

Learn more about DLL search order in windows: https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order

# Step-2 Performing Out test on a Legitimate Application

We can launch process monitor and after applying necessary filters to see how DLLs are being loaded, we can observe which applications are loading which DLLs. This is how we observed that explorer.exe was loading "cscapi.dll" from a wrong path.

![Explorer Filters](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/c2428a87-d7c1-45b6-b402-03a6ecd140bb)


We will place our DLL in this path and name it "cscapi.dll". Then we will kill "explorer.exe" and restart it. Now we see our DLL is being loaded and the message box is displayed

![Explorer Hijacked](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/6aa44493-3395-4fa1-b315-8a31f8853326)

