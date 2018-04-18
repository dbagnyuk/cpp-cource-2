// Network_Thread-hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib, "ws2_32.lib")
#define DEF_HOSTADDR "127.0.0.1" //������� LOOPBACK-��� IP ������, �.�. ���������� ������ ���������� ��� ������� ���������

DWORD ThreadFunc(LPVOID lParam);
void OnServer();
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


	OnServer();
	
	
	
	
	
	return 0;
}

void OnServer() //������� ��� ������������� � ������ �������
{
	if (cc) closesocket(cc);
	server = TRUE;

	//�������� ���������� ��� ����� ������
	ss = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	//������������ ���������� ���������� � ����� � � IP ������
	if (bind(ss, (sockaddr*)&Addr, sizeof(Addr)) == SOCKET_ERROR)
	{
		closesocket(ss);
		ss = 0;
		std::cout << "Cannot bind socket" << std::endl;
		return;
	}

	//������������� ��� ����� ������  
	if (listen(ss, SOMAXCONN) == SOCKET_ERROR)
	{
		closesocket(ss);
		ss = 0;
		std::cout << "Cannot listen socket" << std::endl;
	}

	//�������� ������ ��� �������� ���������� �������
	if (ss) hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, &dwCount, 0, &dwThreadId);

}

//����� ��� �������� ���������� � ��������
DWORD ThreadFunc(LPVOID lParam)
{
	LPDWORD lpdwCount = (LPDWORD)lParam;
	*lpdwCount = 0;

	//������� ������� ���������� �������, ������������ ��� �������
	if (!r) r = accept(ss, (sockaddr*)&Addr, NULL);

	if (r == INVALID_SOCKET) std::cout << "Cannot accept socket" << std::endl;

	if ((r != 0) && server)
	{
		Stemp[0] = '\0';
		if (recv(r, Stemp, 256, 0) == SOCKET_ERROR) //������� ����� ���������
		{
			closesocket(r); //��� ������������ ������� � ��������, ������ ������ ������������������ ������� ����������, ��� �������� ���������� �������
			r = 0;
		}
		else {
			if (Stemp[0] == '\0') {
				closesocket(r); //��� ������������ ������� � ��������, ������ ������ ������������������ ������� ����������, ��� �������� ���������� �������
				r = 0;
			}
			strcpy_s(S, Stemp);
			send(r, "Server recieved", 256, 0);//������� ������������� �����   
		}
	}

	//�������� ������ ������, ������ �����������
	if (r != INVALID_SOCKET) hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, &dwCount, 0, &dwThreadId);
	return *lpdwCount;
}

void OnClose() //�������� �������� ����������
{
	if (ss) closesocket(ss);
	if (cc) closesocket(cc);
	if (r) closesocket(r);
}
