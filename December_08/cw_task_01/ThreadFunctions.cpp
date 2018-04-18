#include "stdafx.h"
#include "ThreadFunctions.h"

DWORD WINAPI ServerFunc(void * pData)
{
	sockaddr_in Addr;
	Addr.sin_family = AF_INET;
	Addr.sin_port = htons(PORT);
	Addr.sin_addr.s_addr = INADDR_ANY;

	SOCKET work, acceptSock;
	acceptSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	HANDLE Mutex = CreateMutex(NULL, FALSE, L"name");

	char * pErrText = 0;
	try
	{
		if (bind(acceptSock, (sockaddr*)&Addr, sizeof(Addr)) == SOCKET_ERROR)
			throw  "Cannot bind socket";
		if (listen(acceptSock, SOMAXCONN) == SOCKET_ERROR)
			throw"Cannot switch to listen mode";
	}
	catch(const char * pErrText)
	{
		closesocket(acceptSock);
		acceptSock = 0;
		cout << pErrText << endl;
		return 0;
	}
	
	while (true)
	{
		cout << "Server is waiting..." << endl;
		work = accept(acceptSock, (sockaddr*)&Addr, NULL);

		if (work == INVALID_SOCKET)
		{			
			cout << "Cannot accept socket" << endl;
			continue;
		}
		cout << "Connection is established!!!" << endl;
		ServerData * pSData = new ServerData(work, Mutex);
		HANDLE hTh = CreateThread(0, 0, WorkThreadFunc, pSData, 0, 0);
		CloseHandle(hTh);
	}
	CloseHandle(Mutex);
	return 0;
}
DWORD WINAPI WorkThreadFunc(void * pData)
{
	ServerData * pServerData = (ServerData*)pData;
	char sRecvBuff[BUFF_SIZE], sSendBuff[BUFF_SIZE];
	int nMessCount = 0;

	int cnt_attempts;
	int nRecvBytes = recv(pServerData->m_Sock, (char *)&cnt_attempts, BUFF_SIZE, 0);
	if (nRecvBytes == SOCKET_ERROR)
	{
		closesocket(pServerData->m_Sock);
		pServerData->m_Sock = 0;
		cout << "End of network session.." << endl;
		closesocket(pServerData->m_Sock);
	}
	else if (nRecvBytes > sizeof(int))
	{
		cout << "Bytes more than needed." << endl;
	}
	cout << "Server recieved " << cnt_attempts << " number of attempts." << endl;

	while (cnt_attempts != 0)
	{
		nRecvBytes = recv(pServerData->m_Sock, sRecvBuff, BUFF_SIZE, 0);
		if (nRecvBytes == SOCKET_ERROR)
		{
			closesocket(pServerData->m_Sock);
			pServerData->m_Sock = 0;
			break;
		}
		sprintf_s(sSendBuff, "Server recieve message #%d == %s", ++nMessCount, sRecvBuff);
		int nMessLen = strlen(sSendBuff) + 1;
		send(pServerData->m_Sock, sSendBuff, nMessLen, 0);

		WaitForSingleObject(pServerData->m_Mutex, INFINITE);
		cout << "Server recieve: " << nRecvBytes << " bytes: " << sRecvBuff << endl;
		ReleaseMutex(pServerData->m_Mutex);

		--cnt_attempts;
	}

	cout << "End of network session.." << endl;
	closesocket(pServerData->m_Sock);

	delete pServerData;
	return 0;
}