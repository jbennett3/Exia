#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<filesystem>
#include<time.h>
#include<stdio.h>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<algorithm>
#include<unordered_map>
#include <chrono>
#include <cstdint>
namespace fs = std::filesystem;
class Data_entry
{

public:
	Data_entry(std::string = "", std::string = "");
	~Data_entry() { std::cout << username<<" object  has been destroyed" << std::endl; };
	std::string time_entry();
	std::vector<std::string>path_collector(std::string);
	std::string path_name();
	std::unordered_map<std::string, std::uintmax_t >data_bytes;
	std::string name() { return username;};
private:
	std::vector<std::string>image_path;
	std::string username;
	std::string time_stamp;
	std::string paths_named;
	//int bytes;
	std::unordered_map<std::string, std::uintmax_t >path_bytes;
	inline std::unordered_map<std::string, std::uintmax_t >bytes_of_image(std::string file_path, std::uintmax_t size_of_image)
	{ //map the file size to with file path
		path_bytes[file_path] = size_of_image;
		return path_bytes;
	}
	
	inline std::vector<std::string>get_filenames(fs::path path)
	{// show what file(s) are in the path that can be mapped
		std::cout << "Current contents that can be mapped into memory: " << std::endl;
		namespace file = std::filesystem;
		std::vector<std::string> filenames;
		const file::directory_iterator end{};
		int counter = 0;
		for (file::directory_iterator iter{ path }; iter != end; ++iter)
		{
			if (file::is_regular_file(*iter))
				filenames.push_back(iter->path().string());
			//std::cout << file::file_size(iter->path().string()) << std::endl;
			bytes_of_image(filenames[counter++], file::file_size(iter->path().string()));
		}
		data_bytes = path_bytes;
		return filenames;
	}


};