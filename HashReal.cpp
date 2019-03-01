#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector> 
#include <algorithm>

using namespace std;

#define ll long long

class Pic {
    public:
        char orientation;
        set<string> tags;
        int numTags;
        long line;
        
    Pic (char ori = 'A', int i = -1) {
        orientation = ori;
        numTags = 0;
        line = i;
    }
    void addTag(string tag){
        tags.insert(tag);
        numTags++;
    }
};
                 
class Slide{ 
public:

    long pic1Index;
    long pic2Index;
    
    set<string> tags;
    int numTags;
    
    Slide(Pic in1 = Pic(), Pic in2 = Pic()){
        numTags = 0;
        pic1Index = in1.line;
        tags.insert(in1.tags.begin(), in1.tags.end());
        
        if (in2.line != -1) {
            pic2Index = in2.line;
            tags.insert(in2.tags.begin(), in2.tags.end());
        }
        else 
            pic2Index = -1;
        
        numTags = tags.size();
            
    }
    
};


int main () {
    //string line;
    ifstream input ("d1.txt");
    ofstream outputFile ("outputD.txt");
    Pic lastV = Pic();
    Pic inPic;
    char type;
    int numTags;
    long slideCount = 0;
    vector<Slide> slides;
    
    string output;
    string inputString;
    if (input.is_open())
    { 
        long numPics; 
        input >> numPics;
        for(long picture = 0; picture < numPics; picture++){
            
            input >> type;
            input >> numTags;
            
            inPic = Pic(type, picture);
            
            for(int tag = 0; tag < numTags; tag++){
                input >> inputString;
                inPic.addTag(inputString);
            }
            
            if(type == 'V'){
                if(lastV.line == -1)
                    lastV = inPic;
                else{
                    slides.push_back(Slide(inPic, lastV));
                    slideCount++;
                    lastV.line = -1;  
                }
            }
            
            else{
                slides.push_back(Slide(inPic));
                slideCount++;
            }
        }
        
        input.close();
        
        //algorithm

        Slide current = slides[slides.size() -1];
        slides.pop_back(); 
        
        outputFile << slideCount;
        
        outputFile << '\n' << current.pic1Index;
        if (current.pic2Index != -1) {
            outputFile << ' ' << current.pic2Index;
        }
        
        while(slides.size() > 0) {
            if(!(slides.size() % 100))
                cout << slides.size() << '\n';

            int maxScore = -1;
            long maxSlide = 0; 
        
            for(long j = 0; j < slides.size(); j++){
                set<string> intersection;
                set_intersection(current.tags.begin(), current.tags.end(),
                                 slides[j].tags.begin(), slides[j].tags.end(), 
                                 inserter(intersection, intersection.begin()));
                
                int interSize = intersection.size();
                int size1 = slides[j].tags.size();
                int size2 = current.tags.size();
                int score = min(min(interSize,size1 - interSize),size2 - interSize);
                if (score > maxScore) {
                    maxScore = score;
                    maxSlide = j;
                }
            }
            outputFile << '\n' << slides[maxSlide].pic1Index;
            if(slides[maxSlide].pic2Index != -1)
                outputFile << ' ' << slides[maxSlide].pic2Index;
            current = slides[maxSlide];
            slides.erase(slides.begin() + maxSlide);
        }  
            
        outputFile.close();
    }
    

  return 0;
}