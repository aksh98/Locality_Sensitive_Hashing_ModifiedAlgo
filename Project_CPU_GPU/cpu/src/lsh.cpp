// #include <iostream>
// #include <vector>
// #include <random>
// #include <functional>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <unordered_map>
// #include <array>
// #include <vector>
// #include <stdlib.h>
// #include "lsh.h"

// using namespace std;


// std::unordered_map<std::string, std::vector<int> > table;


// float** data;
// //	Print text on the screen /

// void lsh::example_printf(int text)
// {
// 	cout << text;
// 	return;
// }

// //	Read input data set and return it as matrix 
// float ** lsh::read_data(std::string filename)
// {
// 	string line;
// 	int row=0;
// 	int col=0;	
// 	data = new float*[60000];
// 	for(int i = 0; i < 60000; ++i)
//     	data[i] = new float[2071];
	
// 	ifstream myfile (filename);
// 	if (myfile.is_open())
// 	{
// 		while ( getline (myfile,line) )
// 		{
// 			std::istringstream iss(line);
// 			int val;
// 			col=0;
// 			while ( iss >> val)
// 			{
			
// 				data[row][col]=val;
// 				col++;
// 			}
// 	  		row++;
// 		}
// 		myfile.close();
// 	}
// 	else cout << "Unable to open file"; 
// 	// cout << row << endl << col;
// 	return data;
// }

// //Hyperplane matrix generation algorithm and return the hyperplane matrix [TODO number generated by random algorithm is not in range of 0 to 1]
// float ** lsh::hyper_plane(int p, int rows)
// {
// 	data = new float*[p];
// 	for(int i = 0; i < p; ++i)
//     	data[i] = new float[rows];

// 	std::default_random_engine generator;
// 	std::normal_distribution<double> normal(0.0, 1.0);
// 	std::uniform_real_distribution<double> distribution(0.0,1.0);    
//     for (int i=0;i<p;i++)
// 	{
// 		for (int j = 0; j < rows; j++)
// 		{
// 			data[i][j]=normal(generator); // generate random numbers
// 		}
// 	}
	
// 	return data;
// }

// float ** lsh::hash_matrix(float **dataset , float ** hyperplane,int p ,int col, int rows)
// {
// 	// int count_col=0,row_col=0,count=0;
// 	for(int i = 0; i < p; i++)
// 	{
// 		for(int j = 0; j< col; j++)
// 		{
// 			float sum=0;
//             for(int k = 0; k <rows; k++)
//             {
//                 sum += hyperplane[i][k] * dataset[k][j]; // 
//                 if (sum >=0 ){
//                 	data[i][j]=1;
//                 } 
//                 else{
//                 	data[i][j]=0;
//                 }
//                 //sum=0;
//             }
//         }
// 	}
// 	// cout << sizeof(data)/sizeof(data[0][0]);
// 	// cout << row_col<<"\t" << count_col<<"\t" << "\t"<<count;
//     return data;    
// }

// std::unordered_map<std::string, std::vector<int>  > lsh::hash_table(float **matrix, int col,int p)
// {

// 	// cout <<col<<endl;
// 	for (int i = 0; i < col; i++)
// 	{
// 		std::vector<int> cols;
// 		string code = "";
// 		for(int j=0; j< p ; j++)
// 		{
// 			code.append(std::to_string((int)matrix[j][i]));
// 		}
		
// 		// cout << code <<"\t"<< i <<"\n";
// 		// del code;
// 		//hash code to be added to table if coming first time
//     	if (table.find(code) == table.end()){
//         	// add key and col into table
//         	// cout << i << "\t" << code <<endl;
//         	auto it = cols.begin();
//     		it = cols.insert(it, i);
//     		// print_vec(vec);
//         	// cols[0]=i;
//         	// cout << cols[i] << endl;
//         	table[code]=cols;
//         	//table.insert(make_pair(code, cols));
//         	// cols.clear();
//     	}
// 	    // If key found then iterator append the array value
// 	    else
// 	    {
// 	    	// cout <<"Else code" <<code<< i<< endl;
// 	        // cout << "Found " << key << "\n\n";
// 	        std::vector<int> value = table[code];
// 	        // cout<<"Size"<<value.size()-1 <<endl;
// 	        auto it = value.begin();
//     		it = value.insert(it, i);
//     		//cout <<"Else"<< value.size();
// 	        // value[value.size()-1]=i;
// 	        table[code]=value;
// 	        // table.insert(make_pair(code, value));
// 	    }
// 	}

// 	return table;
// }

// ///////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <stdlib.h>
#include "lsh.h"
///MINE :D 
using namespace std;
std::unordered_map<std::string, std::vector<int> > table;

float** data;
//	Print text on the screen 

void lsh::example_printf(int text)
{
	cout << text;
	return;
}

///	Read input data set and return it as matrix
float ** lsh::read_data(std::string filename)
{
	string line;
	int row=0;
	int col=0;	
	data = new float*[60000];
	for(int i = 0; i < 60000; ++i)
    	data[i] = new float[2071];
	
	ifstream myfile (filename);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			std::istringstream iss(line);
			int val;
			col=0;
			while ( iss >> val)
			{
				data[row][col]=val;
				col++;
			}
	  		row++;
		}
		myfile.close();
	}
	else cout << "Unable to open file"; 
	// cout << row << endl << col;
	return data;
}

// Hyperplane matrix generation algorithm and return the hyperplane matrix 
//[TODO number generated by random algorithm is not in range of 0 to 1] 
float ** lsh::hyper_plane(int p, int rows)
{
	data = new float*[p];
	for(int i = 0; i < p; ++i)
    	data[i] = new float[rows];

	std::default_random_engine generator;
	std::normal_distribution<double> normal(0.0, 1.0);
	std::uniform_real_distribution<double> distribution(0.0,1.0);    
    for (int i = 0;i < p;i++)
	{
		for (int j = 0; j < rows; j++)
		{
			data[i][j]=normal(generator); // generate random numbers
		}
	}
	cout << "data["<<p<< "]["<<rows<< "] - hyperplanes";
	// p hyperplanes created here.. dimensionality = rows !!  
	return data;
}
//determining left or right for one hyperplane
float ** lsh::hash_matrix(float **dataset, float **hyperplane,int p ,int col, int rows)
{
	// int count_col=0,row_col=0,count=0;
	for(int i = 0; i < p; i++)
	{
		for(int j = 0; j < col; j++)
		{
			float sum=0;
            for(int k = 0; k < rows; k++)
            {
                sum += hyperplane[i][k] * dataset[k][j]; // 
            }
            if (sum >= 0)
            	data[i][j]=1;
            else
            	data[i][j]=0;
        }
	}
	cout <<"data["<<p<< "] "<< "["<< col <<"] - hash_matrix"<<endl;
	 //cout << sizeof(data)/sizeof(data[0][0]);
	// cout << row_col<<"\t" << count_col<<"\t" << "\t"<<count;
    return data;    
}

//======================================================================================

// creates a hash table where you get the hash code - 10111 and you add it to index having same code.
std::unordered_map<std::string, std::vector<int>  > lsh::hash_table(float **matrix,int *test_matrix,
																			 int rows, int col, int p)
{

	// cout <<col<<endl;
	for (int i = 0; i < col; i++)
	{
		std::vector<int> cols;
		//good_bad_Hyperplane(float **matrix,int p);
		string code = "";
		for(int j = 0; j < p ; j++)
		{
			if(test_matrix[j] == 1)
				code.append(std::to_string((int)matrix[j][i]));
		}
		//you get a 01000101011
		//-------------------------------------------------------------------------------

		if (table.find(code) == table.end())
    	{
        	auto it = cols.begin();
    		it = cols.insert(it,i);
        	table[code]=cols;
    	}
	    // If key found then iterator append the array value
	    else
	    {
	        std::vector<int> value = table[code];
	        auto it = value.begin();
    		it = value.insert(it, i);
            table[code]=value;
	    }
	}

	return table;
}
