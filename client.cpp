#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    const char *msg = "Hello from Client!";
    send(clientSocket, msg, strlen(msg), 0);
    close(clientSocket);
    return 0;
}
