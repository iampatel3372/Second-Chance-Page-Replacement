#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stdio.h>
using namespace std;
class second_chance{
	private :
			vector<int>slots;
			int no_of_blocks;
			vector<int>reference_bit_array;
			int replacement;
			vector<int>replaced;
	public : 
			second_chance(int no_of_blocks)
			{
				this->no_of_blocks = no_of_blocks;
				this->slots=vector<int>(no_of_blocks);
				this->reference_bit_array = vector<int> (no_of_blocks);
				this->replacement=0;

			}

			bool findAndUpdate(int x) 
			{ 
			    int i; 
			      
			    for(i = 0; i < this->no_of_blocks; i++) 
			    { 
			          
			        if(this->slots[i] == x) 
			        { 
			            
			            this->reference_bit_array[i] = true; 
			            return true; 
			        } 
			    } 
			    return false; 
			      
			} 
			int replaceAndUpdate(int x,int pointer) 
			{ 
			    while(true) 
			    { 
			        if(!this->reference_bit_array[pointer]) 
			        { 
			            if(this->slots[pointer]!=0)
			            {
			            	this->replaced.push_back(this->slots[pointer]);
			        		this->replacement++;
			            }
			            this->slots[pointer] = x; 
			            return (pointer + 1) % this->no_of_blocks; 
			        } 
			        this->reference_bit_array[pointer] = false;
			        pointer = (pointer + 1) % this->no_of_blocks; 
			    } 
			} 
			void printHitsAndFaults(vector<int>reference_string) 
			{ 
			    int pointer, i, l=0, x, pf; 
			    pointer = 0;
			    pf = 0;
			    this->slots.clear();
			    for(i = 0; i < reference_string.size(); i++) 
			    { 
			        x = reference_string[i];
			        if(!findAndUpdate(x)) 
			        {
			            pointer = replaceAndUpdate(x,pointer); 
			            pf++; 
			        } 
			    }
			    cout<<"\nReplaced blocks are : ";
			    for(int i = 0; i < this->replaced.size(); i++)
			    {
			    	cout << this->replaced[i] << " ";
			    } 
			    cout << "\n";
			    cout << "Total replacements were " << this->replacement << "\n";

			}


};
void header()
{
    cout<<"CS558 : COMPUTER SYSTEM LAB ASSIGNMENT - 05\n";
    cout<<"Instructor : Dr. Manas Khatua and Dr. Moumita Patra\n";
    cout<<"TA's : Alakesh Kalita, Arunav Saikia, Meenu Rani Dey, Priya Undriwade, Vinay Kumar Gupta\n";
    cout<<"Sumbittted By : Himanshu Patel(204101029), Ketan Karnakota(204101030)\n";
}
int main()
{
	header();
	cout<<"Enter the number of slots : ";
	int f;
	cin>>f;
	second_chance S=second_chance(f);
	vector<int>pages;
	cout<<"Enter the blocks : \n";
	string s;
	cin.ignore();
	getline(cin,s);
	std::stringstream ss( s );
	int num;
	while(ss>>num)
		pages.push_back(num);
	S.printHitsAndFaults(pages);
	
	return 0;
}