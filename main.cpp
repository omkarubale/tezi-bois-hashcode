#include <iostream>
#include <math.h>
#include <string>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

struct Image {
    int ImageNumber;
    int ImageId;
    bool OrientationHorizontal;
    vector<string> ImageTags;
};

struct Slide {
    int SlideId;
    bool IsHorizontalImage;
    vector<int> ImageIds;
    vector<string> SlideTags;
};

class Solution
{
    int N;
    int HorizontalImageCounter = 0;
    int VerticalImageCounter = 0;
    int SlideCounter = 0;
    vector<struct Image> HorizontalImages;
    vector<struct Image> VerticalImages;
    vector<struct Slide> Slides; 

    void GetImages(string input)
    {
        //Get all images.
    }

    void CreateSlides()
    {
        for(int i = 0; i < HorizontalImages.size(); i++)
        {
            
            Slide newSlide = 
            { 
                SlideCounter, 
                HorizontalImages[i].OrientationHorizontal, 
                vector<int>(HorizontalImages[i].ImageId), 
                HorizontalImages[i].ImageTags
            };
            
            Slides.emplace_back(newSlide);
            SlideCounter++;
        }
    }
};

int main()
{
    std::cout << "Hello World" << "\n";
    return 0;
}
