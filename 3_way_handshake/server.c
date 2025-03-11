#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int client_size;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    listen(server_socket, 3);

    printf("Menunggu koneksi...\n");
    client_size = sizeof(client);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &client_size);

    printf("Koneksi diterima dari %s\n", inet_ntoa(client.sin_addr));

    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
    return 0;
}
