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
    ifstream inputB ("b.txt");
    ofstream outputFileB ("outputB.txt");

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


    if (inputB.is_open())
    {
        long numPics; 
        inputB >> numPics;
        for(long picture = 0; picture < numPics; picture++){
            inputB >> type;
            inputB >> numTags;
            for(int tag = 0; tag < numTags; tag++){
                inputB >> nothing;
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




        if (outputFileB.is_open())
        {
            outputFileB << slideCount;
            for(long slide = 0; slide < slideCount; slide++){
                outputFileB << '\n' << outputArray[slide][0];
                if(outputArray[slide][1] != -1)
                    outputFileB << ' ' << outputArray[slide][1];
            }
            outputFileB.close();
        }
        
        inputB.close();
    }

    else cout << "Unable to open file"; 













    ifstream inputC ("c.txt");
    ofstream outputFileC ("outputC.txt");

    for(long i = 0; i < 90001; i++){
        outputArray[i][1] = -1;
    }

    lastV = -1;
    slideCount = 0;



    if (inputC.is_open())
    {
        long numPics; 
        inputC >> numPics;
        for(long picture = 0; picture < numPics; picture++){
            inputC >> type;
            inputC >> numTags;
            for(int tag = 0; tag < numTags; tag++){
                inputC >> nothing;
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




        if (outputFileC.is_open())
        {
            outputFileC << slideCount;
            for(long slide = 0; slide < slideCount; slide++){
                outputFileC << '\n' << outputArray[slide][0];
                if(outputArray[slide][1] != -1)
                    outputFileC << ' ' << outputArray[slide][1];
            }
            outputFileC.close();
        }
        
        inputC.close();
    }

    else cout << "Unable to open file";






    ifstream inputD ("d.txt");
    ofstream outputFileD ("outputD.txt");

    for(long i = 0; i < 90001; i++){
        outputArray[i][1] = -1;
    }

    lastV = -1;
    slideCount = 0;



    if (inputD.is_open())
    {
        long numPics; 
        inputD >> numPics;
        for(long picture = 0; picture < numPics; picture++){
            inputD >> type;
            inputD >> numTags;
            for(int tag = 0; tag < numTags; tag++){
                inputD >> nothing;
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




        if (outputFileD.is_open())
        {
            outputFileD << slideCount;
            for(long slide = 0; slide < slideCount; slide++){
                outputFileD << '\n' << outputArray[slide][0];
                if(outputArray[slide][1] != -1)
                    outputFileD << ' ' << outputArray[slide][1];
            }
            outputFileD.close();
        }
        
        inputD.close();
    }

    else cout << "Unable to open file";







    ifstream inputE ("e.txt");
    ofstream outputFileE ("outputE.txt");

    for(long i = 0; i < 90001; i++){
        outputArray[i][1] = -1;
    }

    lastV = -1;
    slideCount = 0;



    if (inputE.is_open())
    {
        long numPics; 
        inputE >> numPics;
        for(long picture = 0; picture < numPics; picture++){
            inputE >> type;
            inputE >> numTags;
            for(int tag = 0; tag < numTags; tag++){
                inputE >> nothing;
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




        if (outputFileE.is_open())
        {
            outputFileE << slideCount;
            for(long slide = 0; slide < slideCount; slide++){
                outputFileE << '\n' << outputArray[slide][0];
                if(outputArray[slide][1] != -1)
                    outputFileE << ' ' << outputArray[slide][1];
            }
            outputFileE.close();
        }
        
        inputE.close();
    }

    else cout << "Unable to open file";

    

    return 0;
}