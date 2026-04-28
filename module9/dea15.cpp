

#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
#include <chrono>

// Shared resources
int data = 0;
std::shared_mutex rw_mutex;

void reader(int id) {
    for (int i = 0; i < 5; ++i) {
        // Shared lock allows multiple readers to enter simultaneously
        std::shared_lock<std::shared_mutex> lock(rw_mutex);

        std::cout << "[Reader " << id << "] reads data = " << data << std::endl;

        // Sleep to simulate work and let other readers join in
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void writer() {
    for (int i = 0; i < 5; ++i) {
        // Unique lock provides exclusive access (blocks all readers and other writers)
        std::unique_lock<std::shared_mutex> lock(rw_mutex);

        data++;
        std::cout << "[Writer] updated data to = " << data << std::endl;

        // Sleep to simulate a heavy write operation
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

int main() {
    std::vector<std::thread> threads;

    // Launch 3 reader threads
    for (int i = 1; i <= 3; ++i) {
        threads.emplace_back(reader, i);
    }

    // Launch 1 writer thread
    threads.emplace_back(writer);

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Simulation complete." << std::endl;
    return 0;
}