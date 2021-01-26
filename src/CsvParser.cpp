#include <json/json.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "../include/CsvParser.h"

csv::~csv(){};
csv::csv(std::string newpath){
	path = newpath;
}

std::string csv::getFilePath(){
	return path;
};

int csv::setFilePath(std::string newPath){
	path = newPath;
	return true;
};

bool csv::fileExists(std::string filepath){
	if (FILE *file = fopen(filepath.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
    	err = "Failed to open file: File doesn't exist.";
        return false;
    };
};

std::string csv::stringify(Json::Value in){
	Json::StreamWriterBuilder builder;
    builder.settings_["indentation"] = "";
    std::string out = Json::writeString(builder, in);
	return out;
};

Json::Value csv::loadStatement(std::string name){
	if(name.length() <= 0){
		return 1;
    };
	Json::Value statement = readFile();
	return statement;
};

Json::Value csv::readFile(){
	std::ifstream infile(path);
	std::string line;
	Json::Value final;
	std::vector<std::string> headdings;
	int valueLine = 0; 
	int lineNum = 1;
	while(std::getline(infile, line)){
        if(lineNum == 1){
			headdings = split(line, ",");
        }else{
			Json::Value currentObj;
			std::vector<std::string> currentValues = split(line, ",");
			 for(int i = 0; i < headdings.size(); i++){
			 currentObj[headdings[i]] = currentValues[i];
            };
			final[valueLine] = currentObj;
			valueLine++;
        };
		lineNum++;
    };
	return final;
};

std::vector<std::string> csv::split(std::string s, std::string delim){
	std::vector<std::string> results;
	int currentPos = 0; 
	int newpos;
	bool found = true;
	while(found){
        found = false;
		newpos = s.find(delim, currentPos);
		int length = newpos - currentPos;
		std::string token = s.substr(currentPos, length);
		results.push_back(token);
		if(newpos <= 0){
			break;
		}else{
			found = true;
        };
        currentPos = newpos+1;
    };
	return results;
};
