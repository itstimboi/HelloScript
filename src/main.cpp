#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

std::string currentFilename;

bool OpenFile(const char* filename)
{
    fs::path path(filename);

    // Check extension
    if (path.extension() != ".hs")
    {
        std::cerr
            << "Invalid file format. Expected a .hs file.\n";

        return false;
    }

    // Check that the file exists
    if (!fs::exists(path))
    {
        std::cerr
            << "File does not exist: "
            << filename
            << '\n';

        return false;
    }

    currentFilename = filename;

    return true;
}

void Execute(const std::string& source)
{
    if (source.find("HelloWorld(print);") != std::string::npos)
    {
        std::cout << "Hello World\n";
    }
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {

        std::string filename = argv[1];

        if (!OpenFile(filename.c_str()))
            return 1;

        Execute(filename);

    }

    return 0;
}