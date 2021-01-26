#ifndef CSVPARSER_H_INCLUDED
#define CSVPARSER_H_INCLUDED


class CsvParser{
public: 
	CsvParser();
	CsvParser(std::string filename);
	~CsvParser();
	int setFilePath(std::string filepath);
	std::string getFilePath();
	std::string err;
	Json::Value readFile();
	Json::Value loadStatement(std::string name);
private:
	std::string path;
	bool fileExists(std::string filepath);
	std::vector<std::string> split(std::string s, std::string delim);
	std::string stringify(Json::Value in);
};

#endif