/*
 * HTTP Server in C
 * ----------------
 * Servidor web HTTP con sockets TCP (Winsock2 / POSIX).
 * Soporta peticiones GET para archivos estaticos y endpoint JSON.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    typedef int socklen_t;
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>
    #define SOCKET int
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket close
#endif

#define PORT 8080
#define BUFFER_SIZE 2048

void handle_client(SOCKET client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

    if (bytes_read <= 0) {
        closesocket(client_socket);
        return;
    }

    buffer[bytes_read] = '\0';
    printf("\n[Peticion HTTP]:\n%.100s...\n", buffer);

    char http_response[BUFFER_SIZE];

    if (strstr(buffer, "GET /api/status") != NULL) {
        const char* json_body = "{\"status\": \"ok\", \"server\": \"c-http-server\", \"port\": 8080}";
        snprintf(http_response, sizeof(http_response),
                 "HTTP/1.1 200 OK\r\n"
                 "Content-Type: application/json; charset=UTF-8\r\n"
                 "Content-Length: %zu\r\n"
                 "Access-Control-Allow-Origin: *\r\n"
                 "Connection: close\r\n\r\n"
                 "%s",
                 strlen(json_body), json_body);
    } else if (strstr(buffer, "GET / ") != NULL || strstr(buffer, "GET /index.html") != NULL) {
        const char* html_body =
            "<!DOCTYPE html>"
            "<html>"
            "<head><title>Servidor C HTTP</title></head>"
            "<body>"
            "<h1>Servidor Web HTTP en C</h1>"
            "<p>Servidor HTTP nativo mediante sockets TCP.</p>"
            "<p>API Endpoint: <a href='/api/status'>/api/status</a></p>"
            "</body>"
            "</html>";

        snprintf(http_response, sizeof(http_response),
                 "HTTP/1.1 200 OK\r\n"
                 "Content-Type: text/html; charset=UTF-8\r\n"
                 "Content-Length: %zu\r\n"
                 "Connection: close\r\n\r\n"
                 "%s",
                 strlen(html_body), html_body);
    } else {
        const char* not_found_body = "<html><body><h1>404 Not Found</h1></body></html>";
        snprintf(http_response, sizeof(http_response),
                 "HTTP/1.1 404 Not Found\r\n"
                 "Content-Type: text/html; charset=UTF-8\r\n"
                 "Content-Length: %zu\r\n"
                 "Connection: close\r\n\r\n"
                 "%s",
                 strlen(not_found_body), not_found_body);
    }

    send(client_socket, http_response, (int)strlen(http_response), 0);
    closesocket(client_socket);
}

int main(void) {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Error de inicialización Winsock.\n");
        return 1;
    }
#endif

    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        printf("Error creando socket.\n");
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Error bind en puerto %d.\n", PORT);
        closesocket(server_fd);
        return 1;
    }

    if (listen(server_fd, 10) == SOCKET_ERROR) {
        printf("Error en listen.\n");
        closesocket(server_fd);
        return 1;
    }

    printf("Servidor HTTP escuchando en http://localhost:%d\n", PORT);

    for (int i = 0; i < 3; i++) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);

        SOCKET client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket != INVALID_SOCKET) {
            handle_client(client_socket);
        }
    }

    closesocket(server_fd);
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}
