#include <iostream>
#include <filesystem>

auto recursiveGetFileNamesByExtension = [](const std::filesystem::path& path, const std::string& extension){
    for(const auto& p: std::filesystem::recursive_directory_iterator("D:\\DDA\\Example"))
        if (!p.path().extension().compare(extension)) std::cout << p.path() << "\n";
};

int main() {
    std::filesystem::path fs("D:\\DDA\\Example");
    if (!std::filesystem::exists(fs)) {
        std::cerr << "Error ";
        std::exit(0);
    }
    recursiveGetFileNamesByExtension(fs,".txt");
    recursiveGetFileNamesByExtension(fs,".exe");
    recursiveGetFileNamesByExtension(fs,".dll");
    recursiveGetFileNamesByExtension(fs,".jpeg");
    return 0;
}