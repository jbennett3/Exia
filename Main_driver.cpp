#include<iostream>
#include<thread>
#include"Data_entry.h"
using namespace std;

int main()
{
	
	Image_db Computer1;
	string username;
	string path_of_entry;
	cout << "Enter the user name for entry" << endl;
	cin >> username;
   // C:\Users\justin\Desktop\images.jpg
	cout << "Enter the full path of files  " << endl;
	cout << "For example if file called image.jpg which is in C drive"<< endl;
    cout<<"then begin entry with C:\.. then whatever other subdirectories then \image.jpg"<< endl;
	cin >> path_of_entry;
	//put entry in 
	Computer1.Put(username, path_of_entry);
	//see what computer has mapped in memory
	//Computer1.Get();
	std::cin.get();
	return 0;

}