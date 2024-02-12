/*
This programs includes functions as follow:
   ReadJSON()

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

std::string ReadJSON(std::string file_path, std::string name) {
    std::ifstream ifs("./test.txt");
    std::string element;

    if (ifs.fail()) {
        return "ERROR: FILE DOES NOT EXIST";
    } else {
        while(getline(ifs, element)){
            std::cout << element << std::endl;
        }
        return "CORRECT";
    }
};

int main(void){
    std::string state;
    state = ReadJSON("test.txt", "faa");
    return 0;
}