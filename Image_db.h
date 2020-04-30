#pragma once
#pragma once
#include<iostream>
#include"Person.h"
#include<memory>
#include<boost/iostreams/device/mapped_file.hpp>
#include<boost/interprocess/file_mapping.hpp>
#include<boost/interprocess/mapped_region.hpp>
#include<fstream>
#include<memory>
#include<vector>
#include<unordered_map>
#include<cstddef>
class Image_db
{
public:
	Image_db();
	~Image_db();
	void close_database();
	void Get();
	void Put(std::string,std::string);
	void open_database();
	//void Delete(std::string);
private:
	std::string database_name;
	std::string user;
	std::vector<int>map_selections;
	std::vector<std::string>table;
	std::unordered_map<std::string, std::string>data_table;
	std::unordered_map<std::string, std::uintmax_t>byte_tables;
	std::ofstream record;
	int edit_options = 0;
	std::string choice;
	std::string entry_selecting;
	std::vector<std::string>selection;
	std::string map_type_choice;
	Data_entry entry;
	//when the path of the user enters contains more than one image (like a folder of images)
	inline void map_file_multiple(std::string life,std::unordered_map<std::string,std::uintmax_t> byte_table)
	{
		using boost::interprocess::mapped_region;
		using boost::interprocess::file_mapping;
		//file_mapping::remove(life.c_str());
		const char* path = life.c_str();
		boost::interprocess::file_mapping* file_mapped = new file_mapping(path, boost::interprocess::read_only);
		boost::interprocess::mapped_region* region_mapped = new mapped_region(*file_mapped, boost::interprocess::read_only);

		//file_mapping m_file(path, boost::interprocess::mode_t::read_write);
		//std::unique_ptr<mapped_region>file_object = std::make_unique<mapped_region>(m_file, boost::interprocess::mode_t::read_write,1,byte_table[life]);
		//mapped_region us(m_file, boost::interprocess::mode_t::read_write,1, byte_table[life]);
		//byte_table[life]
		//uint32_t address = reinterpret_cast<uint32_t>(us.get_address());
		std::cout<<"Entry: " <<life<<" has been mapped with: " << region_mapped->get_size() << " bytes" << std::endl;
		//std::cout << "Location: " << address << std::endl;
		data_table[life] = entry.time_entry();
		region_mapped->flush();
		delete file_mapped;
		delete region_mapped;
		
	}
	inline void map_file_single(std::string life)
	{//when the user is entering a single file 
		using boost::interprocess::mapped_region;
		using boost::interprocess::file_mapping;
		const char* path = life.c_str();
		file_mapping m_file(path, boost::interprocess::mode_t::read_write);
		std::unique_ptr<mapped_region>file_object = std::make_unique<mapped_region>(m_file, boost::interprocess::mode_t::read_write);
		//mapped_region us(m_file, boost::interprocess::mode_t::read_write);
		//uint32_t address = reinterpret_cast<uint32_t>(us.get_address());
		std::cout << "Entry: " << life << " has been mapped with: " << file_object->get_size() << " bytes" << std::endl;
		//std::cout << "Location: " << address << std::endl;
		data_table[life] = entry.time_entry();
		file_object->flush();
	}
	//std::vector<char>data_memory;
	//void open_database();
	//data_memory.reserve(1048576);
};
