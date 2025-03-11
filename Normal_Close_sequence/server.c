#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int client_size;
    char buffer[1024];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(7070);

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    listen(server_socket, 3);

    printf("Menunggu koneksi...\n");
    client_size = sizeof(client);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &client_size);
    printf("Koneksi diterima dari %s\n", inet_ntoa(client.sin_addr));

    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Pesan diterima: %s\n", buffer);
    
    send(client_socket, "Goodbye", 7, 0);

    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
    return 0;
}
