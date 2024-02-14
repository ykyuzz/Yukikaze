#ifdef FILEPROCESSING_HPP
#define FILEPROCESSING_HPP

std::vector<std::string> ReadDataFromJSON(std::string file_path, std::string key);
std::vector<std::string> ReadDataFromCONF(std::string file_path, std::string key);
std::vector<std::string> openFile(std::string file_path)
bool saveFile(std::vector<std::string> contents, std::string file_path)


#endif