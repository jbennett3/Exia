#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<thread>
#include"Person.h"
#include"Data_entry.h"
class image_store
{
public:
	image_store(std::string, std::string, std::string, std::string)
	{
		std::cout << "Image store is created " << std::endl;
	}
	~image_store()
	{
		std::cout << "image store detroyed" << std::endl;
	}
private:
	std::string database_name;
	std::string path_name;
};