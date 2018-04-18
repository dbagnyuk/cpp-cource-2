// Network_Thread-hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib, "ws2_32.lib")
#define DEF_HOSTADDR "127.0.0.1" //задание LOOPBACK-ого IP адреса, т.е. локального адреса изначально при запуске программы

DWORD ThreadFunc(LPVOID lParam);
void OnServer();
void OnClose();


char def[256] = "\0";
char def2[512] = "\0";

HANDLE hThread;
DWORD dwCount, dwThreadId;


int PORT = 3182; //порт TCP, служит для организации сети
char S[256] = "\0"; //буфер для хранения в нём отправляемых и получаемых сообщений
char Stemp[256] = "\0";//временный буфер
SOCKET ss, cc, r; //сокеты для организации сети
sockaddr_in Addr; ////обьявление структуры адреса и порта для передачи и приёма данных
WSADATA Wsa; //переменная для инициализации winsock
bool server; //переменная для определения режима работы программы: сервер или клиент


int main()
{


	OnServer();
	
	
	
	
	
	return 0;
}

void OnServer() //функция для инициализации и работы сервера
{
	if (cc) closesocket(cc);
	server = TRUE;

	//создание соединения для приёма данных
	ss = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	//привязывание созданного соединения к порту и к IP адресу
	if (bind(ss, (sockaddr*)&Addr, sizeof(Addr)) == SOCKET_ERROR)
	{
		closesocket(ss);
		ss = 0;
		std::cout << "Cannot bind socket" << std::endl;
		return;
	}

	//инициализация для приёма данных  
	if (listen(ss, SOMAXCONN) == SOCKET_ERROR)
	{
		closesocket(ss);
		ss = 0;
		std::cout << "Cannot listen socket" << std::endl;
	}

	//открытие потока для ожидания соединения клиента
	if (ss) hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, &dwCount, 0, &dwThreadId);

}

//поток для открытия соединения с клиентом
DWORD ThreadFunc(LPVOID lParam)
{
	LPDWORD lpdwCount = (LPDWORD)lParam;
	*lpdwCount = 0;

	//функция ожидает соединение клиента, используется для сервера
	if (!r) r = accept(ss, (sockaddr*)&Addr, NULL);

	if (r == INVALID_SOCKET) std::cout << "Cannot accept socket" << std::endl;

	if ((r != 0) && server)
	{
		Stemp[0] = '\0';
		if (recv(r, Stemp, 256, 0) == SOCKET_ERROR) //функция приёма сообщений
		{
			closesocket(r); //при разъединении клиента с сервером, сервер заново переинициализирует функцию соединения, для ожидания следующего конекта
			r = 0;
		}
		else {
			if (Stemp[0] == '\0') {
				closesocket(r); //при разъединении клиента с сервером, сервер заново переинициализирует функцию соединения, для ожидания следующего конекта
				r = 0;
			}
			strcpy_s(S, Stemp);
			send(r, "Server recieved", 256, 0);//посылка подтверждения приёма   
		}
	}

	//создание нового потока, старый закрывается
	if (r != INVALID_SOCKET) hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, &dwCount, 0, &dwThreadId);
	return *lpdwCount;
}

void OnClose() //закрытие активных соединений
{
	if (ss) closesocket(ss);
	if (cc) closesocket(cc);
	if (r) closesocket(r);
}
