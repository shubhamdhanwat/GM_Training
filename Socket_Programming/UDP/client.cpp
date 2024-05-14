#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a UDP socket
    int client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (client_socket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Server address
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);                     // Server port number
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");   // Server IP address

    // Send data to server
    const char *message = "Hello from client!";
    sendto(client_socket, message, strlen(message), 0, (struct sockaddr *)&server_address, sizeof(server_address));

    // Receive response from server
    char buffer[1024];
    sockaddr_in from_address;
    socklen_t from_address_length = sizeof(from_address);
    int received_bytes = recvfrom(client_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&from_address, &from_address_length);
    if (received_bytes < 0) {
        std::cerr << "Error receiving response\n";
        return 1;
    }

    std::cout << "Response from server: " << buffer << std::endl;

    // Close socket
    close(client_socket);

    return 0;
}
