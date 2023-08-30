#include <iostream>
#include <WinSock2.h>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")

#define PORT 5001
#define PACKET_SIZE 1024
#define SERVER_IP "127.0.0.1"

using namespace std;

int main(){
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET hSocket;
    hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN tAddr = {};
    tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    tAddr.sin_family = AF_INET;
    tAddr.sin_port = htons(PORT);

    connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

    char msg[] = "Client Send";
    send(hSocket, msg, strlen(msg), 0);

    char buf[PACKET_SIZE] = {};
    recv(hSocket, buf, PACKET_SIZE, 0);

    cout << "Recv Msg : " << buf << endl;

    closesocket(hSocket);

    WSACleanup();

    return 0;
}