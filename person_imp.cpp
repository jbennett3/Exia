#include<iostream>
#include<filesystem>
#include"Person.h"
#include <sstream> 
#include"boost/date_time/posix_time/posix_time.hpp"
namespace Entry_Time = boost::posix_time;
namespace fs = std::filesystem;
using namespace std;
Data_entry::Data_entry(std::string use, std::string pa)
	:username(use), paths_named(pa)
{	
}

std::string Data_entry::path_name()
{//return the path name
	return paths_named;
}

std::vector<std::string>Data_entry::path_collector(std::string path_device)
{// store the image paths entered by the user
	string name;
	for (const auto& name : get_filenames(path_device))
	{
		image_path.push_back(name);
	}
	return image_path;
}

std::string Data_entry::time_entry()
{//time stamp of entries that are evaluated by the milliseconds
	Entry_Time::ptime current_date_microseconds = Entry_Time::microsec_clock::local_time();
	long milliseconds = current_date_microseconds.time_of_day().total_milliseconds();
	Entry_Time::time_duration current_time_milliseconds = Entry_Time::milliseconds(milliseconds);
	Entry_Time::ptime current_date_milliseconds(current_date_microseconds.date(),current_time_milliseconds);
	ostringstream ss;
	ss << current_date_milliseconds;
	return ss.str();
	
}