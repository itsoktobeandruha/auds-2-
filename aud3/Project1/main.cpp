#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

size_t find_directory_size(std::string path)
{
    size_t size = 0;
    for (fs::recursive_directory_iterator it(path);
        it != fs::recursive_directory_iterator();
        ++it)
    {
        if (!fs::is_directory(*it))
            size += fs::file_size(*it);
    }

    return size;
}

int main()
{
    std::string path = "C:\\dir";
    std::string check = "C:\\dir\\1";
    std::cout << "Opening:" << path << std::endl;
    int i = 0;
    std::string prev_path;
    if (fs::exists(check) == true)
    {
        std::cout << "dir is already created, delete them to continue" << std::endl;
        return 0;
    }
    for (const auto& entry : fs::directory_iterator(path))
    {
        i++;
        std::string path = "C:\\dir\\";
        path += std::to_string(i);
        std::cout << entry.path() << std::endl;
        if (i != 1)
        {
            std::cout << "check previous folder size" << std::endl;
                if (find_directory_size(prev_path) < 100000)
                {
                    fs::copy(entry.path(), prev_path);
                    std::cout << "succesfully copied" << std::endl;
                    i--;
                }
                else
                {
                    fs::create_directory(path);
                    fs::copy(entry.path(), path);
                    std::cout << "succesfully copied" << std::endl;
                    prev_path = path;
                }
        }
        else
        {
            fs::create_directory(path);
            fs::copy(entry.path(), path);
            std::cout << "succesfully copied" << std::endl;
            prev_path = path;
        }
    }
    return 0;
}