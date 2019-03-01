#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define ll long long

int main () {
    //string line;
    ifstream input ("e_shiny_selfies.txt");
    ofstream outputFile ("outputE.txt");
    long lastV = -1;
    char type;
    int numTags;
    long slideCount = 0;
    string output;
    string nothing;
    if (input.is_open())
    {
        long numPics; 
        input >> numPics;
        for(long picture = 0; picture < numPics; picture++){
            input >> type;
            input >> numTags;
            for(int tag = 0; tag < numTags; tag++){
                input >> nothing;
            }
            if(type == 'V'){
                if(lastV == -1)
                    lastV = picture;
                else{
                    output += "\n" + to_string(lastV) + " " + to_string(picture);
                    lastV = -1;  
                    slideCount++;
                }
            }
            else{
                output += "\n" + to_string(picture);
                slideCount++;
            }
        }

        if (outputFile.is_open())
        {
            outputFile << slideCount <<  output;
            outputFile.close();
        }
        
        input.close();
    }

  else cout << "Unable to open file"; 

  return 0;
}