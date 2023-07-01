#include <Windows.h>

int main()
{
    HKEY hKey;
    DWORD value = 0;

    if (RegOpenKeyEx(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS)
    {
        RegSetValueEx(hKey, L"AppsUseLightTheme", 0, REG_DWORD, (const BYTE*)&value, sizeof(DWORD));

        RegSetValueEx(hKey, L"SystemUsesLightTheme", 0, REG_DWORD, (const BYTE*)&value, sizeof(DWORD));

        RegCloseKey(hKey);
    }

    return 0;
}
