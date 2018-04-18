// NetTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h> //ws2_32.dll
#pragma comment(lib, "ws2_32.lib")

enum NetRole { SERVER_ROLE, CLIENT_ROLE };
//#define  SERVER
#define  CLIENT
#define DEF_HOSTADDR "127.0.0.1"
#define BUFF_SIZE  200

int main()
{
	int PORT = 3182; 	
	 
	sockaddr_in Addr; 
	WSADATA Wsa; 
	if(WSAStartup(0x0202, &Wsa))
	{
		cout << "Cannot init WinSock  " << endl;
		return 0;
	}
	cout << "WinSock is initialized!! " << endl;
	Addr.sin_family = AF_INET;	
	Addr.sin_port = htons(PORT);

#ifdef SERVER
	SOCKET s, work;
	Addr.sin_addr.s_addr = INADDR_ANY;
	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	char * pErrText = 0;
	if (bind(s, (sockaddr*)&Addr, sizeof(Addr)) == SOCKET_ERROR)
		pErrText = "Cannot bind socket";	
	if (listen(s, SOMAXCONN) == SOCKET_ERROR)
		pErrText = "Cannot switch to listen mode";
	if(pErrText != 0)
	{
		closesocket(s);
		s = 0;
		cout << pErrText<< endl;
		return 0;
	}

	//открытие потока для ожидания соединения клиента
	//if (s)
	///	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, &dwCount, 0, &dwThreadId);
	cout <<" server bind listen OK... server is waiting..." << endl;
	work = accept(s, (sockaddr*)&Addr, NULL);

	if (work == INVALID_SOCKET)
	{		
		closesocket(s);
		s = 0;
		cout << "Cannot accept socket"<<endl;
		return 0;		
	}
	cout << "Connection is established!!!" << endl;

	char sBuff[BUFF_SIZE], sSendBuff[BUFF_SIZE];
	while (true)
	{
		int nRecvBytes = recv(work, sBuff, BUFF_SIZE, 0);
		if (nRecvBytes == SOCKET_ERROR)
		{
			closesocket(work);                             //при разъединении клиента с сервером, сервер заново переинициализирует функцию соединения, для ожидания следующего конекта
			work = 0;
			break;
		}
		if (_stricmp(sBuff, "close") == 0)
		{
			break;
		}
		cout << "server recv: " << nRecvBytes << " bytes: " << sBuff << endl;
		int nMessCount = 0;
		sprintf_s(sSendBuff, "server recv mess# %d == %s", ++nMessCount, sBuff);
		int nMessLen = strlen(sSendBuff) + 1;
		send(work, sSendBuff, nMessLen, 0);
	}
	
	cout << "End of network session.." << endl;
	closesocket(s);
#endif

#ifdef CLIENT
	SOCKET c;
	cout << "Enter IP address of the server in format: 192.168.13.201"<< endl;
	char sAddress[BUFF_SIZE];
	cin >> sAddress;
	cin.ignore(1);
	Addr.sin_addr.S_un.S_addr = inet_addr(sAddress);
	c = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(connect(c, (LPSOCKADDR)&Addr, sizeof(Addr)) == SOCKET_ERROR)
	{
		closesocket(c);
		c = 0;
		cout << "Cannot connect socket" << endl;
		return 0;
	}
	cout << "Connection is established!!!" << endl;

	while (true)
	{
		cout << "enter some text to send" << endl;
		cout << "if close connection - enter \"close\"" << endl;
		cin.getline(sAddress, BUFF_SIZE);		
		int nLen = strlen(sAddress) + 1;
		send(c, sAddress, nLen, 0);
		if (_stricmp(sAddress, "close") == 0)
		{
			break;
		}
		recv(c, sAddress, BUFF_SIZE, 0);
		cout << "Client have received: " << sAddress << endl;
	}

	cout << "End of network session.." << endl;
	closesocket(c);
#endif
	cout << "To exit - press any key" << endl;
	_getch();
	WSACleanup();

    return 0;
}

