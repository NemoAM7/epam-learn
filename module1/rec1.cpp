#include <iostream>
#include <filesystem>
#include <string>
#include <stdio.h>

// specific namespace alias for ease of use
namespace fs = std::filesystem;

// Helper function to print indentation based on depth level
void printIndent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  "); // 2 spaces per level
    }
}

// The Recursive Function
// Takes character pointer as input representing the path
// 'level' is used to track the depth for indentation (defaulting to 0)
void recursiveDirectoryTraversal(const char* pathPtr, int level = 0) {
    
    // convert char* to filesystem path object
    fs::path path(pathPtr);

    // check if the path exists and is a directory
    if (!fs::exists(path) || !fs::is_directory(path)) {
        return;
    }

    // Attempt to iterate through the directory
    // We use a try-catch block because accessing some system folders 
    // might throw a "Permission Denied" error.
    try {
        // iterate over the directory entries
        for (const auto& entry : fs::directory_iterator(path)) {
            
            // print indentation first
            printIndent(level + 1);

            // check if the current entry is a directory or a file
            if (entry.is_directory()) {
                // Print directory name with a colon
                printf("%s:\n", entry.path().filename().string().c_str());

                // RECURSION: Call the function again for this sub-directory
                // We convert the path back to string/char* and increase the level
                recursiveDirectoryTraversal(entry.path().string().c_str(), level + 1);
            }
            else {
                // It is a file, just print the name
                printf("%s\n", entry.path().filename().string().c_str());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        // Handle permission errors (common in system roots)
        printIndent(level + 1);
        printf("[Access Denied]\n");
    }
}

int main(int argc, char* argv[]) {

    // Check if user provided the directory argument
    if (argc < 2) {
        printf("Usage: %s <DirectoryPath>\n", argv[0]);
        printf("Example: %s C:\\Users\\Name\\Documents\n", argv[0]);
        return 1;
    }

    // Get the root path from command line arguments
    char* rootPath = argv[1];

    printf("Root: %s\n", rootPath);

    // Start the recursive traversal
    recursiveDirectoryTraversal(rootPath);

    return 0;
}