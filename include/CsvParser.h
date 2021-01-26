#ifndef CSV_H_INCLUDED
#define CSV_H_INCLUDED


class csv{
public: 
	csv();
	csv(std::string filename);
	~csv();
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