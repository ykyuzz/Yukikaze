#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>

/*
THE DEFINITION OF FILE PROCESSING START
*/

/*
This programs includes functions as follow:
   ReadDataFromJSON()
   ReadDataFromCONF()
   saveFile()
   openFile()
*/

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


std::vector<std::string> ReadDataFromCONF(std::string file_path, std::string key) {
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


std::vector<std::string> openFile(std::string file_path){
    /*
    This function can open designated file, then return contents in file as the vector splited every row.
    If this function cannot find designated file, return "ERROR1" in the first index of return vec.
    THE FIRST ELEMENT IN RETURN VECTOR MEANS STATEMENT IN FILE PROCESSING.
    WARNING: THIS FUNCTION GET CONTENTS EVEN IF FILE SIZE IS TOO LARGE. PAY ATTENTION NOT TO OPEN TOO LARGE FILES.
    */
    std::vector<std::string> file_contents;
    std::ifstream ifs(file_path);
    std::string row;
    if (ifs.fail()){
        file_contents.push_back("ERROR1");
    } else {
        file_contents.push_back("SUCCESS");
        while(getline(ifs, row)) {
            file_contents.push_back(row);
        }
    }
    return file_contents;
}

bool saveFile(std::vector<std::string> contents, std::string file_path) {
    /*
    This function can save contents to designated file.
    If designated file cannot be found, this function will make new file.
    However, this function depends on ifstream (cpp module), so the behavior to unknown file may change.
    The argument "contents" must have following structure:
        one-dimmention array
    When processing ends, this will return bool.
    */
    std::ofstream writting_file(file_path);
    std::string row;

    for(size_t i=0;i<contents.size();i++) {
        row = contents[i];
        writting_file << row + "\n";
    }
    writting_file.close();
    return true;
}

/*
THE DEFINITION OF FILE PROCESSING END
*/


/*
THE DEFINITION OF FIELDS PROCESSING START --ONLY FOR WINDOWS--
*/






int WINAPI WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow){
    return 0;
}