#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Server connection settings
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080); // Port number
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    //inet_pton() is a function used to convert an IPv4 or IPv6 address from its text representation (e.g., "127.0.0.1") to its binary form. The name stands for "Internet address presentation to network address structure".

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection failed\n";
        return 1;
    }

    // Send and receive data
    const char *message = "Hello from client!";
    send(client_socket, message, strlen(message), 0);
    std::cout << "Message sent to server\n";

    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    std::cout << "Response from server: " << buffer << "\n";

    // Close socket
    close(client_socket);

    return 0;
}
