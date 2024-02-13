/*
This programs includes functions as follow:
   ReadDataFromJSON()

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

std::vector<std::string> ReadDataFromJSON(std::string file_path, std::string name) {
    /*
    This function firstly open file in "file_path" and search key named argument "name", then return element related to the key.
    If designated file cannot be found, this function will return "ERROR1".
    If designated key cannot be found, this function will return "ERROR2". 
    */
    std::ifstream ifs(file_path);
    std::string element;
    std::vector<std::string> element_list(2);
    std::regex re("(" + name +")");
    std::smatch index;
    bool sig = false;

    if (ifs.fail()) {
        element_list[0] = "ERROR";
        element_list[1] = "1";
    } else {
        while(getline(ifs, element)){
            //std::cout << element << std::endl;
            std::cout << std::regex_search(element, re) << std::endl;
            if (std::regex_search(element, re)){
                std::cout << element << std::endl;
                sig = true;
                break;
            }
        }
        std::cout << index[0] << std::endl;
        std::cout << index[1] << std::endl;
        if(sig){
            element_list[0] = index[1];
            element_list[1] = index[2];
        }
        else{
            element_list[0] = "ERROR";
            element_list[1] = "2";
        }
    }
    return element_list;
};

int main(void){
    std::vector<std::string> state;
    state = ReadDataFromJSON("settings/UserSetting.json", "display_row");
    std::cout << state[1] << std::endl;
    return 0;
}