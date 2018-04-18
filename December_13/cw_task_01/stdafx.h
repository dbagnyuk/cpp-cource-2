// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h> //ws2_32.dll
#include <windows.h>

#define PORT 7007
#define BUFF_SIZE  200
struct ServerData
{
	SOCKET m_Sock;
	HANDLE m_Mutex;
	ServerData(SOCKET Sock, HANDLE Mutex);
};


// TODO: reference additional headers your program requires here
