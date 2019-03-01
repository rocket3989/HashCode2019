#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

#define ll long long

int main () {
    srand(time(NULL));
    //string line;
    ifstream input ("d_pet_pictures.txt");
    ofstream outputFile ("outputD.txt");

    long outputArray[100000][2];

    for(long i = 0; i < 90001; i++){
        outputArray[i][1] = -1;
    }

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
                    outputArray[slideCount][0] = lastV;
                    outputArray[slideCount++][1] = picture;
                    lastV = -1;
                }
            }
            else{
                outputArray[slideCount++][0] = picture;
            }
        }
        for(long slide = 0; slide < slideCount; slide++){
            long swapSlide = rand() % slideCount;
            int temp = outputArray[swapSlide][0];
            outputArray[swapSlide][0] = outputArray[slide][0];
            outputArray[slide][0] = temp;
            temp = outputArray[swapSlide][1];
            outputArray[swapSlide][1] = outputArray[slide][1];
            outputArray[slide][1] = temp;
        }




        if (outputFile.is_open())
        {
            outputFile << slideCount;
            for(long slide = 0; slide < slideCount; slide++){
                outputFile << '\n' << outputArray[slide][0];
                if(outputArray[slide][1] != -1)
                    outputFile << ' ' << outputArray[slide][1];
            }
            outputFile.close();
        }
        
        input.close();
    }

  else cout << "Unable to open file"; 

  return 0;
}