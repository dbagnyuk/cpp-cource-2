// stdafx.cpp : source file that includes just the standard includes
// NetTest_Tread.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
ServerData::ServerData(SOCKET Sock, HANDLE Mutex): m_Sock(Sock), m_Mutex(Mutex)
{	
};