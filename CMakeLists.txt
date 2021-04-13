project(cppcsv)

add_executable(testing
	"src/testing.cpp"
)

target_link_libraries(testing jsoncpp)
