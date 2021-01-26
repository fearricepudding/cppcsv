project(cppcsv)
cmake_minimum_required(VERSION 3.13)

add_library(cppcsv
	src/CsvParser.cpp
)

set(cppcsv_include 
	"E:/git/Halifax-CSV-statement-analiser/CsvParser/include"
)

target_include_directories(cppcsv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})