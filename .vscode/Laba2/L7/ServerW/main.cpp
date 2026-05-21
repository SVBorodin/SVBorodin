#include <iostream>
#include <map>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <sstream>
#include <winsock2.h>
#include <cstdlib>

struct Player {
    int id;
    std::string color;
    int x;
    int y;
};

std::map<int, Player> database;
std::string current_weather = "Clear";
bool running = true;

std::string getDesktopPath() {
    char* userProfile = std::getenv("USERPROFILE");
    if (userProfile != nullptr) {
        return std::string(userProfile) + "\\Desktop\\databaseW.txt";
    }
    return "databaseW.txt";
}

void loadDatabase() {
    std::string path = getDesktopPath();
    std::ifstream file(path);
    if (!file.is_open()) return;
    Player p;
    while (file >> p.id >> p.color >> p.x >> p.y) {
        database[p.id] = p;
    }
    file.close();
    std::cout << "Database loaded from Desktop. Total players: " << database.size() << std::endl;
}

void saveDatabase() {
    std::string path = getDesktopPath();
    std::ofstream file(path);
    if (!file.is_open()) return;
    for (auto const& [id, p] : database) {
        file << p.id << " " << p.color << " " << p.x << " " << p.y << "\n";
    }
    file.close();
    std::cout << "Database auto-saved on Desktop: " << path << std::endl;
}

void weatherThread() {
    std::vector<std::string> weathers = {"Clear", "Cloudy", "Rainy"};
    int index = 0;
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        index = (index + rand() % 2 + 1) % 3;
        current_weather = weathers[index];
        std::cout << "Weather status: " << current_weather << std::endl;
    }
}

BOOL WINAPI ConsoleHandler(DWORD ctrlType) {
    if (ctrlType == CTRL_C_EVENT || ctrlType == CTRL_CLOSE_EVENT) {
        running = false;
        saveDatabase();
        ExitProcess(0);
        return TRUE;
    }
    return FALSE;
}

int main() {
    SetConsoleCtrlHandler(ConsoleHandler, TRUE);
    loadDatabase();

    std::thread(weatherThread).detach();

    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345);

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, SOMAXCONN);

    std::cout << "Server active on port 12345..." << std::endl;

    while (running) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) continue;

        char buffer[1024] = {0};
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead > 0) {
            std::string msg(buffer);
            std::stringstream ss(msg);
            std::string type;
            int id;

            if (ss >> type >> id) {
                if (type == "LOGIN") {
                    if (database.count(id) == 0) {
                        database[id] = {id, "#0000FF", 0, 0};
                        saveDatabase();
                    }
                }
                else if (type == "UPDATE") {
                    std::string color;
                    int x, y;
                    if (ss >> color >> x >> y) {
                        database[id] = {id, color, x, y};
                        saveDatabase();
                    }
                }

                std::stringstream response;
                response << current_weather << "|" << database[id].color << "," << database[id].x << "," << database[id].y;

                for (auto const& [p_id, player] : database) {
                    if (p_id != id) {
                        response << ";" << player.id << "," << player.color << "," << player.x << "," << player.y;
                    }
                }

                std::string resStr = response.str();
                send(clientSocket, resStr.c_str(), resStr.length(), 0);
            }
        }
        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}