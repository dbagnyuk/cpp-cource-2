// NetTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")

enum NetRole { SERVER_ROLE, CLIENT_ROLE };
#define DEF_HOSTADDR "127.0.0.1"


int main()
{
	WSADATA Wsa;
	if (WSAStartup(0x0202, &Wsa))
	{
		cout << "Cannot init WinSock  " << endl;
		return 0;
	}
	cout << "WinSock is initialized!! " << endl;

	sockaddr_in Addr;
	Addr.sin_family = AF_INET;
	Addr.sin_port = htons(PORT);
	SOCKET c;
	char sRecvBuff[BUFF_SIZE], sSendBuff[BUFF_SIZE];
	cout << "Enter IP address of the server in format: 192.168.13.201" << endl;
	char sAddress[BUFF_SIZE] = { DEF_HOSTADDR };
	//cout << "IP address is " << sAddress << endl;
	cin >> sAddress;
	cin.ignore(1);
	Addr.sin_addr.S_un.S_addr = inet_addr(sAddress);

	c = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connect(c, (LPSOCKADDR)&Addr, sizeof(Addr)) == SOCKET_ERROR)
	{
		closesocket(c);
		c = 0;
		cout << "Cannot connect socket" << endl;
		return 0;
	}
	cout << "Connection is established!" << endl;

	int nCountBytes = recv(c, sRecvBuff, BUFF_SIZE, 0);
	if (nCountBytes < BUFF_SIZE)
		sRecvBuff[nCountBytes] = 0;
	else
		sRecvBuff[BUFF_SIZE - 1] = 0;
	cout << "Recieved from server " << nCountBytes << " , " << sRecvBuff << endl;
	//int nLen = strlen(sSendBuff) + 1;
	//send(c, sSendBuff, nLen, 0);

	cout << "Server have received: " << sRecvBuff << endl;

	cout << "End of network session.." << endl;
	closesocket(c);
	c = 0;

	cout << "To exit - press any key" << endl;
	_getch();
	WSACleanup();

	return 0;
}

