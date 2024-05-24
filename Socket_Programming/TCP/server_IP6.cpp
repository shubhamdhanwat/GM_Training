#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // Create socket
    int server_fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    // Bind socket to IP and port
    struct sockaddr_in6 server_addr;
    server_addr.sin6_family = AF_INET6;
    server_addr.sin6_addr = in6addr_any; // Listen on any IPv6 address
    server_addr.sin6_port = htons(8080); // Port number
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Bind failed\n";
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        std::cerr << "Listen failed\n";
        return 1;
    }

    // Accept connections
    struct sockaddr_in6 client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd == -1) {
        std::cerr << "Accept failed\n";
        return 1;
    }

    // Send data to client
    const char *message = "Hello from server!";
    send(client_fd, message, strlen(message), 0);

    // Close sockets
    close(client_fd);
    close(server_fd);

    return 0;
}
