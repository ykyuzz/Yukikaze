/*
This programs includes functions as follow:
   ReadDataFromJSON()

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> ReadDataFromJSON(std::string file_path, std::string key) {
    /*
    This function firstly open file in "file_path" and search key named argument "key", then return element related to the key.
    If designated file cannot be found, this function will return "ERROR1".
    If designated key cannot be found, this function will return "ERROR2". 
    */
    std::ifstream ifs(file_path);
    std::string element;
    std::vector<std::string> element_list(2);
    int index;
    int colon_index;
    bool sig = false;

    if (ifs.fail()) {
        element_list[0] = "ERROR";
        element_list[1] = "1";
    } else {
        while(getline(ifs, element)){
            index = element.find(key);
            if (index != -1){
                sig = true;
                break;
            }
        }
        if(sig){
            element = element.erase(element.size()-1);
            colon_index = element.find(":");
            element_list[0] = element.substr(0, colon_index);
            element_list[1] = element.substr(colon_index+1);
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
    state = ReadDataFromJSON("settings/UserSetting.json", "desplay_row");
    std::cout << state[0] << std::endl;
    std::cout << state[1] << std::endl;
    return 0;
}