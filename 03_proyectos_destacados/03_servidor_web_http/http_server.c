/*
 * ============================================================================
 * Proyecto   : Micro Servidor Web HTTP y API REST en C
 * Nivel      : Avanzado / Portafolio Senior (Sistemas Distribuidos & Sockets TCP)
 * Archivo    : http_server.c
 * Descripción: Servidor Web HTTP multiplataforma (Windows Winsock2 / Linux Sockets)
 *              capaz de servir archivos HTML y responder a llamadas a una API REST (JSON).
 * ============================================================================
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
    printf("\n[PETICIÓN HTTP RECIBIDA]:\n%.100s...\n", buffer);

    char http_response[BUFFER_SIZE];

    // Endpoint API REST JSON
    if (strstr(buffer, "GET /api/status") != NULL) {
        const char* json_body = "{\"status\": \"online\", \"server\": \"Micro-HTTP C Server\", \"code\": 200}";
        snprintf(http_response, sizeof(http_response),
                 "HTTP/1.1 200 OK\r\n"
                 "Content-Type: application/json; charset=UTF-8\r\n"
                 "Content-Length: %zu\r\n"
                 "Access-Control-Allow-Origin: *\r\n"
                 "Connection: close\r\n\r\n"
                 "%s",
                 strlen(json_body), json_body);
    }
    // Página principal / (HTML)
    else if (strstr(buffer, "GET / ") != NULL || strstr(buffer, "GET /index.html") != NULL) {
        const char* html_body =
            "<!DOCTYPE html>"
            "<html>"
            "<head><title>Servidor C HTTP</title><style>body{font-family:sans-serif;background:#0f172a;color:#fff;text-align:center;padding:50px;}h1{color:#38bdf8;}</style></head>"
            "<body>"
            "<h1>🚀 Micro Servidor HTTP en C</h1>"
            "<p>Este servidor fue construido en C puro utilizando sockets TCP multiplataforma.</p>"
            "<p>API Endpoint activo: <a href='/api/status' style='color:#38bdf8;'>/api/status</a></p>"
            "</body>"
            "</html>";

        snprintf(http_response, sizeof(http_response),
                 "HTTP/1.1 200 OK\r\n"
                 "Content-Type: text/html; charset=UTF-8\r\n"
                 "Content-Length: %zu\r\n"
                 "Connection: close\r\n\r\n"
                 "%s",
                 strlen(html_body), html_body);
    }
    // 404 Not Found
    else {
        const char* not_found_body = "<html><body><h1>404 Recurso No Encontrado</h1></body></html>";
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
        printf("Error al inicializar Winsock.\n");
        return 1;
    }
#endif

    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        printf("Error creando el socket.\n");
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Error haciendo bind al puerto %d.\n", PORT);
        closesocket(server_fd);
        return 1;
    }

    if (listen(server_fd, 10) == SOCKET_ERROR) {
        printf("Error al escuchar en el socket.\n");
        closesocket(server_fd);
        return 1;
    }

    printf("========================================================\n");
    printf(" 🚀 SERVIDOR HTTP EN C CORRIENDO EN http://localhost:%d \n", PORT);
    printf("========================================================\n");
    printf("Presiona Ctrl+C para detener el servidor.\n");

    // Bucle para aceptar peticiones
    for (int i = 0; i < 3; i++) { // Ejecuta 3 ciclos de demostración o cliente
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        printf("\nEsperando conexiones activas...\n");

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
