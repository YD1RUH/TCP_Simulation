#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock1, sock2;
    struct sockaddr_in addr1, addr2;
    int addr_size;

    WSAStartup(MAKEWORD(2, 2), &wsa);
    
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    addr1.sin_family = AF_INET;
    addr1.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr1.sin_port = htons(9090);

    bind(sock1, (struct sockaddr *)&addr1, sizeof(addr1));
    listen(sock1, 3);

    printf("Menunggu koneksi simultan...\n");

    addr_size = sizeof(addr2);
    sock2 = accept(sock1, (struct sockaddr *)&addr2, &addr_size);

    printf("Koneksi dua arah tersinkronisasi dengan %s\n", inet_ntoa(addr2.sin_addr));

    closesocket(sock2);
    closesocket(sock1);
    WSACleanup();
    return 0;
}
