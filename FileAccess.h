/*
N-Rage`s Dinput8 Plugin
(C) 2002, 2006  Norbert Wladyka

Author`s Email: norbert.wladyka@chello.at
Website: http://go.to/nrage

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef _FILEACCESS_H_
#define _FILEACCESS_H_

#include <string>

#include "NRagePluginV2.h"
#include "Version.h"

using std::string;

bool GetDirectory( LPTSTR pszDirectory, WORD wDirID );
bool CheckFileExists( LPCTSTR FileName );
void GetAbsoluteFileName( LPTSTR szAbsolute, LPCTSTR szFileName, const WORD wDirID );

BOOL SendFilestoList( HWND hDlgItem, WORD wType );
bool StoreConfigToINI();
bool LoadConfigFromINI();
LANGID GetLanguageFromINI();

bool LoadProfileFile( LPCTSTR pszFileName, int iController, LPTSTR pszGameDevice, LPBYTE bGameDeviceNr );
bool LoadShortcutsFile( LPCTSTR pszFileName );
void FormatProfileBlock( FILE * fFile, const int iController );
void FormatShortcutsBlock( FILE * fFile, bool bIsINI );
bool BrowseFolders( HWND hwndParent, LPTSTR pszHeader, LPTSTR pszDirectory );
bool BrowseFile( HWND hDlg, LPTSTR pszFileName, DWORD dwType, bool fSave );
bool ReadMemPakFile( LPTSTR pszMemPakFile, BYTE *aMemPak, bool fCreate );
bool WriteMemPakFile( LPTSTR pszMemPakFile, BYTE *aMemPak, bool fCreate );
bool LoadProfileFromResource( int indexController, bool bIsInterface );
bool LoadShortcutsFromResource( bool bIsInterface );
inline void GUIDtoStringA( char * szGUIDbuf, const GUID guid );
inline bool StringtoGUIDA( LPGUID guid, const char * szGUIDbuf );
unsigned long djbHash(const char *str);

#ifdef _UNICODE
#define TCHAR_TO_CHAR(x,y,z)    wcstombs(x,y,z)
#define CHAR_TO_TCHAR(x,y,z)    mbstowcs(x,y,z)
#else
#define TCHAR_TO_CHAR(x,y,z)    strncpy(x,y,z)
#define CHAR_TO_TCHAR(x,y,z)    strncpy(x,y,z)
#endif

#define STRING_DEF_MEMPAKFILE   _T("MemPaks")
#define STRING_DEF_GBROMFILE    _T("GBxRoms")
#define STRING_DEF_GBROMSAVE    _T("GBxSaves")

#define STRING_INI_HEADER       "# Generated by NRage input plugin V2 version " VER_FILE_VERSION_STR "\n"
// We use these names for loading from INI files and N-Rage config files
#define STRING_INI_GENERAL      "General"
#define STRING_INI_CONTROLLER   "Controller"
#define STRING_INI_FOLDERS      "Folders"
#define STRING_INI_BROWSER      "lastBrowserDir"
#define STRING_INI_CONTROLS     "Controls"
#define STRING_INI_SHORTCUTS    "Shortcuts"
#define STRING_INI_MODIFIERS    "Modifiers"

#define STRING_INI_LANGUAGE     "Language"
#define STRING_INI_SHOWMESSAGES "ShowMessages"

#define STRING_INI_BRPROFILE    "Profile"
#define STRING_INI_BRNOTE       "Note"
#define STRING_INI_BRMEMPAK     "Mempak"
#define STRING_INI_BRGBROM      "GBxRom"
#define STRING_INI_BRGBSAVE     "GBxSave"
// #define STRING_INI_BRSHORTCUTS   STRING_INI_SHORTCUTS

#define STRING_INI_PLUGGED      "Plugged"
#define STRING_INI_XINPUT       "xInput"
#define STRING_INI_N64MOUSE     "N64Mouse"
#define STRING_INI_BACKGROUNDINPUT      "BackgroundInput"
#define STRING_INI_RAWDATA      "RawData"
#define STRING_INI_PAKTYPE      "PakType"
#define STRING_INI_REALN64RANGE "RealN64Range"
#define STRING_INI_RAPIDFIREENABLED "RapidFireEnabled"
#define STRING_INI_RAPIDFIRERATE    "RapidFireRate"
#define STRING_INI_STICKRANGE   "StickRange"
#define STRING_INI_MOUSEMOVEX   "MouseMoveX"
#define STRING_INI_MOUSEMOVEY   "MouseMoveY"
#define STRING_INI_AXISSET      "AxisSet"
#define STRING_INI_KEYABSOLUTEX "KeyAbsoluteX"
#define STRING_INI_KEYABSOLUTEY "KeyAbsoluteY"
#define STRING_INI_PADDEADZONE  "PadDeadZone"
#define STRING_INI_MOUSESENSX   "MouseSensitivityX"
#define STRING_INI_MOUSESENSY   "MouseSensitivityY"
#define STRING_INI_RUMBLETYPE   "RumbleType"
#define STRING_INI_RUMBLESTRENGTH   "RumbleStrength"
#define STRING_INI_VISUALRUMBLE "VisualRumble"
#define STRING_INI_FFDEVICEGUID "FFDeviceGUID"
#define STRING_INI_MEMPAKFILE   "MemPakFile"
#define STRING_INI_GBROMFILE    "GBRomFile"
#define STRING_INI_GBROMSAVE    "GBRomSave"

#define STRING_INI_DINPUTGUID   "DInputGUID"
#define STRING_INI_BUTTON       "Button"
#define STRING_INI_MODIFIER     "Modifier"

// The following are not found in INI files; only profile and shortcuts files
#define STRING_PROFILEVERSION22 "Controller Profile 2.2"
#define STRING_PROFILEVERSION   STRING_PROFILEVERSION22

#define STRING_INI_FFDEVICENAME "FFDeviceName"
#define STRING_INI_FFDEVICENR   "FFDeviceNr"
#define STRING_INI_DINPUTNAME   "DInputName"
#define STRING_INI_DINPUTNR     "DInputNr"


// The following are hashes for the string values above

// Version strings, including the @ in front
#define CHK_PROFILEVERSION20            2278962538UL
#define CHK_PROFILEVERSION21            2278962539UL
#define CHK_PROFILEVERSION22            2278962540UL

// Categories
#define CHK_GENERAL                       63249731UL
#define CHK_FOLDERS                     3455681620UL
#define CHK_LASTBROWSERDIR              2659654652UL
#define CHK_CONTROLLER_1                3910856026UL
#define CHK_CONTROLLER_2                3910856027UL
#define CHK_CONTROLLER_3                3910856028UL
#define CHK_CONTROLLER_4                3910856029UL
#define CHK_CONTROLS                    3459743001UL
#define CHK_SHORTCUTS                   2945387732UL
#define CHK_MODIFIERS                     95935975UL

// Assignments (to the left of the '=' sign)
#define CHK_LANGUAGE                    3857633481UL
#define CHK_SHOWMESSAGES                 638097246UL

#define CHK_MEMPAK                      3230166560UL
#define CHK_GBXROM                      2992194388UL
#define CHK_GBXSAVE                     4253155349UL

#define CHK_PROFILE                     3606499382UL
#define CHK_NOTE                        2089365563UL

#define CHK_PLUGGED                     3378836077UL
#define CHK_XINPUT                      3665436173UL
#define CHK_N64MOUSE                     863329606UL
#define CHK_BACKGROUNDINPUT             2660742997UL
#define CHK_RAWDATA                     1238573385UL
#define CHK_PAKTYPE                     2936974691UL
#define CHK_REALN64RANGE                1279831790UL
#define CHK_RAPIDFIREENABLED            1491009894UL
#define CHK_RAPIDFIRERATE               1576165031UL
#define CHK_STICKRANGE                  4145501776UL
#define CHK_MOUSEMOVEX                  1825694205UL
#define CHK_MOUSEMOVEY                  1825694206UL
#define CHK_AXISSET                     1642523718UL
#define CHK_KEYABSOLUTEX                 958566277UL
#define CHK_KEYABSOLUTEY                 958566278UL
#define CHK_PADDEADZONE                 2913910084UL
#define CHK_MOUSESENSITIVITYX           1513071697UL
#define CHK_MOUSESENSITIVITYY           1513071698UL
#define CHK_RUMBLETYPE                  3440038446UL
#define CHK_RUMBLESTRENGTH              3038086267UL
#define CHK_VISUALRUMBLE                1795686016UL
#define CHK_FFDEVICEGUID                2645316746UL
#define CHK_MEMPAKFILE                  2373591360UL
#define CHK_GBROMFILE                   2409678172UL
#define CHK_GBROMSAVE                   2410136971UL

#define CHK_DINPUTGUID                  1452894242UL
#define CHK_BUTTON                      2818908353UL
#define CHK_MODIFIER                    4037573396UL


// The following are not found in INI files; only profile and shortcuts files
#define CHK_FFDEVICENAME                2645546658UL
#define CHK_FFDEVICENR                  2037510273UL
#define CHK_DINPUTNAME                  1453124154UL
#define CHK_DINPUTNR                    3965009433UL


// If any of the following values conflict with djbHash return values (such as a blank string), there will be problems!

// Nothing
#define PL_NOHIT                0
// [Category]
#define PL_CATEGORY             1
// @STRING_PROFILEVERSION
#define PL_VERSIONSTRING        10

// Resets the static vars in ProcessKey
#define PL_RESET            200

#define DIRECTORY_MEMPAK        0
#define DIRECTORY_GBROMS        1
#define DIRECTORY_GBSAVES       2
#define DIRECTORY_CONFIG        252
#define DIRECTORY_LOG           253
#define DIRECTORY_DLL           254
#define DIRECTORY_APPLICATION   255
#define DIRECTORY_INVALID       256

#define FILIST_MEM          1
#define FILIST_TRANSFER     2

#define BF_LOAD             false
#define BF_SAVE             true

#define BF_MEMPAK           0
#define BF_GBROM            1
#define BF_GBSAVE           2
#define BF_PROFILE          3
#define BF_NOTE             4
#define BF_SHORTCUTS        5

// 32 hex characters, 4 hyphens, 2 end braces
#define GUID_STRINGLENGTH   32+4+2

#endif // #ifndef _FILEACCESS_H_
