# Project Exia
Project Exia
Imagedb_exia is a key value store database system for storing images using C++.
The program will use ask the user to enter the name of their database.
The user will created an Image_db object that will have the put() and get() operations.
The user will enter their name and the path to the image. The path of the image can be a path to a folder or a path to a signle image.
The user will enter the name and path to the put() and will then be asked to enter 1 or 2 indicating if the path is to a folder or
a single image. Once that is done if the path was to a folder the program will show the user the contents of each image and ask if all files
will be mapped into memory or a select few. The user can enter all or select which binaries to choose with -1 being the termination key. All 
contents that is mapped will be stored into a hashtable that store the user entries. The get() will show all entries currently stored.
The project is still in construction but will have later be developed to include multithreading to allow multiple users to use the database.
Also in the future boost Asio will be used to allow the information to be sent from various clients to a server.
