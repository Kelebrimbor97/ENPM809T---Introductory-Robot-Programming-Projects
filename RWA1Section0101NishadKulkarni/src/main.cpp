/**
 * @file main.cpp
 * @author Nishad Kulkarni (nkulkar2@umd.edu); UID- 117555431; Section 0101
 * @brief RWA 1 Solution project
 * @version 0.1
 * @date 2021-09-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
 * Including all the necessary header file(s) and namespace(s)
 */
#include <iostream>
#include <typeinfo>

using namespace std;

/**
 * @brief function prototyping
 */

unsigned int get_total_parts();

void get_total_boxes();

void get_parts_per_box();

void fill_up_boxes();

/**
 * @brief definition of user defined box structures with different sizes
 * The structures are labeled as per size type and include two fields- namely max parts 
 * that can be packed in the boxes, and maximum number of boxes of that type available
 */


struct XL{
	unsigned int max_parts{};
	unsigned int available_boxes{};
};


struct L{
	unsigned int max_parts{};
	unsigned int available_boxes{};
};


struct M{
	unsigned int max_parts{};
	unsigned int available_boxes{};
};


struct S{
	unsigned int max_parts{};
	unsigned int available_boxes{};
};

struct rwa1{
	XL member4{};
	L member3{};
	M member2{};
	S member1{};
};

/**
 * @brief function definition for getting total parts and checking if user enter a positive int
 * We use extra integers and string to check type and sign of input before assigning i to the structure values
 * We keep prompting the user to enter the proper values until conditions are satisfied. For this we use a boolean to check if input number is an unsigned integer
 */

unsigned int get_total_parts(){
	
	int a;
	string s1;
	bool is_uint = false;

	std::cout << "How many parts in total? : ";
	std::cin >> a;
	s1 = typeid(a).name();

	while (is_uint == false){
		if((s1=="i") && (a>=0)){
			is_uint = true;
			unsigned int b = a; 
			return b;
			}
		
		else{
			std::cout << "Entered invalid data type" << std::endl;
		}
	}

}

/**
 * @brief Get the total boxes
 * Same as before, we perform an input check
 * @param instance 
 */

void get_total_boxes(rwa1 &instance){
	
	bool is_uint = false;

	string s1;
	string s2;
	string s3;
	string s4;
	
	int a;
	int b;
	int c;
	int d;

	while(is_uint==false){
		std::cout<<"How many boxes for S/M/L/XL? ";
		std::cin >> a >> b >> c >> d;
		
		s1 = typeid(a).name();
		s2 = typeid(b).name();
		s3 = typeid(c).name();
		s4 = typeid(d).name();
		
		if((s1=="i") && (s2=="i") && (s3=="i") && (s4=="i") && (a >= 0) && (b >= 0) && (c >= 0) && (d >= 0)){
			
			instance.member1.available_boxes = a;
			instance.member2.available_boxes = b;
			instance.member3.available_boxes = c;
			instance.member4.available_boxes = d;
			
			is_uint = true;
		}
		
		else{
			std::cout << "Entered invalid data type. Do it again." << std::endl;
		}
	}
}

/**
 * @brief Get the parts per box object
 * We use same method as before. This time we also check if box capacities are in order of size
 * @param instance 
 */

void get_parts_per_box(rwa1 &instance){
	bool is_uint = false;

	string s1;
	string s2;
	string s3;
	string s4;
	
	int a;
	int b;
	int c;
	int d;

	while(is_uint==false){
		std::cout<<"How many parts per box for S/M/L/XL? ";
		std::cin >> a >> b >> c >> d;
		
		s1 = typeid(a).name();
		s2 = typeid(b).name();
		s3 = typeid(c).name();
		s4 = typeid(d).name();
		
		if((s1=="i") && (s2=="i") && (s3=="i") && (s4=="i") && (a >= 0) && (b >= 0) && (c >= 0) && (d >= 0)  && (a < b) && (b < c) && (c < d)){
			
			instance.member1.max_parts = a;
			instance.member2.max_parts = b;
			instance.member3.max_parts = c;
			instance.member4.max_parts = d;
			
			is_uint = true;
		}
		
		else{
			std::cout << "Entered invalid data type or value. Do it again." << std::endl;
		}
	}
}

void fill_up_boxes(const rwa1 &i){

	unsigned int parts{};
	unsigned int hold;

	unsigned int a1{};
	unsigned int a2{};
	unsigned int a3{};
	unsigned int a4{};

	unsigned int b1{i.member4.available_boxes};
	unsigned int b2{i.member4.available_boxes};
	unsigned int b3{i.member4.available_boxes};
	unsigned int b4{i.member4.available_boxes};

	unsigned int d1{i.member4.max_parts};
	unsigned int d2{i.member3.max_parts};
	unsigned int d3{i.member2.max_parts};
	unsigned int d4{i.member1.max_parts};

	parts = get_total_parts();

	std::cout<<"Boxes that can be built with " << parts << " parts:" << std::endl;
	std::cout<<"-----------------------------------------------------------"<<std::endl;

	a1 = parts/d1;
	if(a1>b1){
		a1 = b1;
		}
	parts = parts - (a1*d1);
	
	std::cout<< "XL box (" << i.member4.available_boxes << " x " << i.member4.max_parts <<"): " << a1 <<"-- remaining parts: "<< parts << std::endl;

	a2 = parts/d2;
	if(a2>b2){
		a2 = b2;
	}
	parts = parts - (a2*d2);

	std::cout<< "L box (" << i.member3.available_boxes << " x " << i.member3.max_parts <<"): " << a2 <<"-- remaining parts: "<< parts << std::endl;

	a3 = parts/d3;
	if(a3>b3){
		a3 = b3;
	}
	parts = parts - (a3*d3);

	std::cout<< "M box (" << i.member2.available_boxes << " x " << i.member2.max_parts <<"): " << a3 <<"-- remaining parts: "<< parts << std::endl;

	a4 = parts/d4;
	if(a4>b4){
		a4 = b4;
	}
	parts = parts - (a4*d4);

	std::cout<< "S box (" << i.member1.available_boxes << " x " << i.member1.max_parts <<"): " << a4 <<"-- remaining parts: "<< parts << std::endl;

	std::cout<<"parts not in the boxes: " << parts;
}
/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char *argv[])
{
	unsigned int parts{};
	
	rwa1 i;
	rwa1 *i1{&i};

	get_total_boxes(*i1);

	get_parts_per_box(*i1);

	fill_up_boxes(*i1);
}