#include<memory>
#include<iostream>
#include<iterator>
#include"Data_entry.h"
#include<unordered_map>
#include<stdint.h>
Image_db::Image_db()
{
	std::cout << "***********************************************************"<<std::endl;
	std::cout << "Welcome to Image_db what would like to title your database?" << std::endl;
	std::cin >> database_name;
	std::cout << "Image_db object created named: "<<database_name<<" database at: "<<entry.time_entry()<< std::endl;
	std::cout << "**************************************************************"<< std::endl;
	std::cout << "\n" << std::endl;
}
Image_db::~Image_db()
{
	std::cout << "************************************************************" << std::endl;
	std::cout << "Image_db object for: "<<database_name<< std::endl;
	std::cout << "Image_db object destroyed at: "<<entry.time_entry()<< std::endl;
	std::cout << "*************************************************************" << std::endl;
	std::cout << "\n" << std::endl;
}
/*void Image_db::open_database()
{
	std::cout << "Opening the Database: " << std::endl;
	

}*/
void Image_db::close_database()
{
	this->~Image_db();
}
void Image_db::Put(std::string name, std::string path_of_entry)
{//enter entry into database
	std::cout << "****************************************************************" << std::endl;
	std::shared_ptr<Data_entry>v = std::make_shared<Data_entry>(name, path_of_entry);
	entry.time_entry() = v->time_entry();//mark when entry is made
	//have user indicate if the path contains multiple or a single file 
	std::cout << "Is path single image or folder? "<<std::endl;
	std::cout << "Enter 1 for single entry."<<std::endl;
	std::cout << "Enter 2 for folder with multiple entries."<< std::endl;
	std::cin >> choice;
	//map the entries based on file decision
	if (choice == "1")
	{
		map_file_single(path_of_entry);
	}
	else if (choice == "2")
	{//when mapping multiple files user is given choice to map all the files in that path or a select few
        table = v->path_collector(path_of_entry);
		std::cout << "Here are all the files that can be mapped into memory:" << std::endl;

		for (unsigned int num_of_files = 0; num_of_files < table.size(); num_of_files++)
		{
			std::cout <<"#" <<num_of_files<<". " <<table[num_of_files] << std::endl;	
		}
		std::cout <<"Would you like to select certain files or map all files in folder?" << std::endl;
		std::cout << "Enter all for the memory mapping of all files or enter selection to select certain files" << std::endl;
		std::cin >> map_type_choice;
		//map all files 
		if(map_type_choice=="all"||map_type_choice=="All")
		{
			
			for (unsigned int num_of_files = 0; num_of_files < table.size(); num_of_files++)
			{
			  map_file_multiple(table[num_of_files],v->data_bytes);
			}
		}
		// map only the selected few by the user
		 if (map_type_choice == "selection" || map_type_choice == "SELECTION")
		{
			 std::cout << "There are " << table.size() << " entries" << std::endl;
			while (edit_options!=-1)
			{
				//entry_selecting != "No" || entry_selecting != "no" || entry_selecting != "NO" || entry_selecting != "nO"
				std::cout << "Enter number for the selected file to map into memory:" << std::endl;
				std::cout << "If you wish to terminate selection process enter -1 otherwise process continues." << std::endl;
				std::cin >> edit_options;
				/*std::cout << "If you wish to terminate selection process enter -1 otherwise process continues." << std::endl;
				std::cin >> entry_selecting;*/
				if (edit_options == -1)
				{
					std::cout << " Exited operation " << std::endl;
					break;
				}
				else
				{
					map_selections.push_back(edit_options);
				}
				if (edit_options<0 || edit_options>table.size())
				{
					
					std::cout << "You entered an invaild choice for mapping!!!"<< std::endl;
					
				}
				
			}
			//begin process for mapping the files
			for (int num_of_files = 0; num_of_files < map_selections.size(); num_of_files++)
			{
				selection.push_back(table[map_selections[num_of_files]]);
			}
			for (int num_of_files = 0; num_of_files < selection.size(); num_of_files++)
			{
				map_file_multiple(selection[num_of_files], v->data_bytes);
			}
		}
		
	}
	//indicate if user gives invaild choice 
	else
	{
		std::cout << "Invalid choice:!!" << std::endl;
		
	}
	
}
//show all contents that has been mapped into memory
void Image_db::Get()
{
	std::cout << "***********************************" << std::endl;
	std::cout << "Files that were mapped to memory!!!" << std::endl;
	std::unordered_map<std::string, std::string>::iterator itr;
	for (itr = data_table.begin(); itr != data_table.end(); itr++)
	{
		std::cout << "time_stamp: " << itr->first << "  " << "entry " << itr->second << std::endl;
	}
	
}