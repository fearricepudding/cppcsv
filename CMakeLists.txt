add_library(CsvParser
	src/CsvParser.cpp
)
set(csvparser_include E:/git/Halifax-CSV-statement-analiser/CsvParser/include)

target_include_directories(CsvParser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})