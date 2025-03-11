#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in addr;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9090);

    printf("Menghubungkan secara simultan...\n");
    connect(sock, (struct sockaddr *)&addr, sizeof(addr));

    printf("Koneksi simultan berhasil!\n");

    closesocket(sock);
    WSACleanup();
    return 0;
}
