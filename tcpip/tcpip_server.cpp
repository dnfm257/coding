#include <iostream>
#include <WinSock2.h>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")

#define PORT 5001
#define PACKET_SIZE 1024

using namespace std;

int main(){
    WSADATA wsaData; // 소켓 정보 넣는 구조체
    WSAStartup(MAKEWORD(2, 2), &wsaData); // ver2.2

    SOCKET hListen; // 핸들러
    hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // IPv4, 연결지향형 소켓, TCP(프로토콜)

    // 서버(본인) 주소 정보
    SOCKADDR_IN tListenAddr = {};
    tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 리틀엔디안 -> 빅엔디안(네트워크 통신), INADDR_ANY = local
    tListenAddr.sin_family = AF_INET;
    tListenAddr.sin_port = htons(PORT); // 리틀엔디안 -> 빅엔디안(네트워크 통신)
    
    // 소켓 준비
    bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));
    
    // 응답 대기
    listen(hListen, SOMAXCONN);

    // 연결된 클라이언트 주소 정보
    SOCKADDR_IN tClntAddr = {};
    int iClntSize = sizeof(tClntAddr);

    // 접속 요청 수락
    SOCKET hClient = accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize);

    // 서버에게 받은 메세지(recv)
    char buf[PACKET_SIZE] = {};
    recv(hClient, buf, PACKET_SIZE, 0);
    cout << "Recv Msg : " << buf << endl;

    // 서버에 보내는 메세지(send)
    char msg[] = "Server Send";
    send(hClient, msg, strlen(msg), 0);

    // 소켓 닫기
    closesocket(hClient);
    closesocket(hListen);

    WSACleanup(); // 소켓 구조체 소멸자

    return 0;
}