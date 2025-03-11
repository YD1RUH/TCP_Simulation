#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    printf("Menghubungkan ke server...\n");
    connect(client_socket, (struct sockaddr *)&server, sizeof(server));

    printf("Terhubung ke server!\n");

    closesocket(client_socket);
    WSACleanup();
    return 0;
}
