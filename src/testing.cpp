
#include "cppcsv.h"
#include <iostream>
#include <json/json.h>

int main(int argc, char *argv[]){
	std::cout << "Reading file" << std::endl;
	
	csvReader *reader = new csvReader();
	Json::Value fileData = reader->readFile((std::string)"../test/MOCK_DATA.csv", ",");
	std::cout << "[*] read " << fileData.size() << " lines of data" << std::endl;
	std::cout << "==== Example ====\n";
	Json::Value firstLine = fileData[0];
	for(std::string key : firstLine.getMemberNames()){
		std::cout << key << " : " << firstLine[key] << std::endl;
	}
	std::cout << "=====" << std::endl;
}

