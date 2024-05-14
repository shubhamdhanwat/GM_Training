#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a UDP socket
    int server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (server_socket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Bind the socket to a port
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);         // Port number
    server_address.sin_addr.s_addr = INADDR_ANY;   // Bind to any available IP

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Binding failed\n";
        return 1;
    }

    std::cout << "Server listening for UDP messages...\n";

    // Receive and send data
    char buffer[1024];
    sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    while (true) {
        int received_bytes = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_address, &client_address_length);
        if (received_bytes < 0) {
            std::cerr << "Error receiving data\n";
            continue;
        }

        std::cout << "Message from client: " << buffer << std::endl;

        const char *response = "Hello from server!";
        sendto(server_socket, response, strlen(response), 0, (struct sockaddr *)&client_address, client_address_length);
        std::cout << "Response sent to client\n";
    }

    // Close socket
    close(server_socket);

    return 0;
}
