/*
This programs includes functions as follow:
   ReadDataFromJSON()

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

std::string ReadDataFromJSON(std::string file_path, std::string name) {
    /*
    This function firstly open file in "file_path" and search key named argument "name", then return element related to the key.
    If designated file cannot be found, this function will return "ERROR1".
    If designated key cannot be found, this function will return "ERROR2". 
    */
    std::ifstream ifs("./test.txt");
    std::string element;
    int sig = 0;

    if (ifs.fail()) {
        return "ERROR1";
    } else {
        while(getline(ifs, element)){
            if (element == name){
                sig = 1;
            } else if (sig == 1){
                return element;
                break;
            }
        }
        return "ERROR2";
    }
};

int main(void){
    std::string state;
    state = ReadDataFromJSON("test.txt", "faa");
    return 0;
}