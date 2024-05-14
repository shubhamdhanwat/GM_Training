#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create socket
    int client_fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (client_fd == -1) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    // Connect to server
    struct sockaddr_in6 server_addr;
    server_addr.sin6_family = AF_INET6;
    inet_pton(AF_INET6, "::1", &server_addr.sin6_addr); // IPv6 loopback address
    server_addr.sin6_port = htons(8080); // Port number
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Connection failed\n";
        return 1;
    }

    // Receive data from server
    char buffer[1024] = {0};
    recv(client_fd, buffer, sizeof(buffer), 0);
    std::cout << "Message from server: " << buffer << std::endl;

    // Close socket
    close(client_fd);

    return 0;
}
