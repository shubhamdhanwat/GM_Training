#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    /*
    socket() creates a new socket.
    AF_INET specifies the address family (IPv4).
    SOCK_STREAM specifies the socket type (TCP).
    0 specifies the protocol (default protocol for the given address family and socket type).
    */
    if (server_socket == -1)
    {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    
    // Bind socket to port
    //set up the server address structure (sockaddr_in) 
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);       // Port number(host to network short)
    server_address.sin_addr.s_addr = INADDR_ANY; // Bind to any available IP
    
    /*
    sin_family is set to AF_INET for IPv4,
    sin_port is set to the port number (converted to network byte order using htons()),
    and sin_addr.s_addr is set to INADDR_ANY,
    which means the server will accept connections on any of the host's network interfaces.
    */
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        std::cerr << "Binding failed\n";
        return 1;
    }

    // Listen for connections
    if (listen(server_socket, 5) < 0)
    {
        std::cerr << "Listening failed\n";
        return 1;
    }

    std::cout << "Server listening...\n";

    // Accept incoming connections
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket < 0)
    {
        std::cerr << "Error accepting connection\n";
        return 1;
    }

    // Send and receive data
    char buffer[1024] = {0};
    std::cout << "Waiting for message from client...\n";
    read(client_socket, buffer, 1024);
    std::cout << "Message from client: " << buffer << "\n";

    const char *response = "Hello from server!";
    send(client_socket, response, strlen(response), 0);
    std::cout << "Response sent to client\n";

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
