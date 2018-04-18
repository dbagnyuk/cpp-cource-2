// Network_Thread-hw3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib, "ws2_32.lib")
#define DEF_HOSTADDR "127.0.0.1" //������� LOOPBACK-��� IP ������, �.�. ���������� ������ ���������� ��� ������� ���������

void OnClient();
void OnClose();

char def[256] = "\0";
char def2[512] = "\0";

HANDLE hThread;
DWORD dwCount, dwThreadId;

int PORT = 3182; //���� TCP, ������ ��� ����������� ����
char S[256] = "\0"; //����� ��� �������� � �� ������������ � ���������� ���������
char Stemp[256] = "\0";//��������� �����
SOCKET ss, cc, r; //������ ��� ����������� ����
sockaddr_in Addr; ////���������� ��������� ������ � ����� ��� �������� � ����� ������
WSADATA Wsa; //���������� ��� ������������� winsock
bool server; //���������� ��� ����������� ������ ������ ���������: ������ ��� ������


int main()
{
	std::cout << "Enter the message you want to send: ";
	std::cin >> S;

	OnClient();

	if (!server)
	{
		if (send(cc, S, 256, 0) == SOCKET_ERROR) std::cout << "Server not respond." << std::endl;//�������� ������
		else recv(cc, Stemp, 256, 0);
	}
	else std::cout << "Server not send" << std::endl;

	OnClose();
	
	return 0;
}

void OnClient() //������� ��� ������������� � ������ �������
{
	if (hThread) TerminateThread(hThread, 0);
	if (ss) closesocket(ss);
	if (r) closesocket(r);
	if (cc) closesocket(cc);

	//�������� ���������� ��� �������� ������
	cc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (cc == SOCKET_ERROR)
	{
		closesocket(cc);
		cc = 0;
		std::cout << "Cannot create socket" << std::endl;
	}

	//���������� � ������ �������
	SOCKADDR_IN servsin = { AF_INET };
	servsin.sin_port = htons(u_short(PORT));

	DWORD dwAddr;
	//m_IPAddr.GetAddress(dwAddr);
	//ULONG ulAddr = htonl(dwAddr);
	//servsin.sin_addr.S_un.S_addr = ulAddr;//inet_addr(m_Address);
	servsin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (connect(cc, (LPSOCKADDR)&servsin, sizeof(servsin)) == SOCKET_ERROR)
	{
		closesocket(cc);
		cc = 0;
		std::cout << "Cannot connect socket" << std::endl;
	}

	server = FALSE;
}

void OnClose() //�������� �������� ����������
{
	if (ss) closesocket(ss);
	if (cc) closesocket(cc);
	if (r) closesocket(r);
}
