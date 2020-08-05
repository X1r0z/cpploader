#include <windows.h>
#include <iostream>

void encode(LPCSTR inFilename, LPCSTR outFilename)
{
	char buf[4096];
	HANDLE inFile = CreateFile(inFilename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	int size = GetFileSize(inFile, NULL);
	DWORD bytesRead = 0;
	ReadFile(inFile, buf, size, &bytesRead, NULL);
	CloseHandle(inFile);
	for (int i = 0; i != sizeof(buf) / sizeof(buf[0]); i++) {
		buf[i] = buf[i] ^ 'a';
	}
	HANDLE outFile = CreateFile(outFilename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	DWORD bytesWrite = 0;
	WriteFile(outFile, buf, size, &bytesWrite, NULL);
	CloseHandle(outFile);
}

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "cppencoder.exe calc.bin enc.bin" << std::endl;
	}
	else {
		encode(argv[1], argv[2]);
	}
	return 0;
}