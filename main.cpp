#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Image
{
    int ImageNumber;
    int ImageId;
    bool OrientationHorizontal;
    vector<string> ImageTags;
};

struct Slide
{
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
    int HorizontalSlideCounter = 0;
    int VerticalSlideCounter = 0;
    vector<struct Image> HorizontalImages;
    vector<struct Image> VerticalImages;
    vector<struct Slide> HorizontalSlides;
    vector<struct Slide> VerticalSlides;

    void GetImages(vector<string> rawImages)
    {
        //Get all images.
    }

    vector<string> GetTagsFromTwoVerticalImages(vector<string> image1Tags, vector<string> image2Tags)
    {
        vector<string> result(image1Tags.begin(), image1Tags.end());
        result.insert(result.end(), image2Tags.begin(), image2Tags.end());
        vector<string>::iterator ip;
        ip = std::unique(result.begin(), result.begin() + result.size());
        result.resize(std::distance(result.begin(), ip));
        std::sort(result.begin(), result.end());
        return result;
    }

    void CreateSlides()
    {
        for (int i = 0; i < HorizontalImages.size(); i++)
        {
            Slide newSlide =
                {
                    HorizontalSlideCounter,
                    HorizontalImages[i].OrientationHorizontal,
                    vector<int>(HorizontalImages[i].ImageId),
                    HorizontalImages[i].ImageTags};

            HorizontalSlides.emplace_back(newSlide);
            HorizontalSlideCounter++;
        }

        for (int i = 0; i < VerticalImages.size(); i += 2)
        {
            Slide newSlide =
                {
                    VerticalSlideCounter,
                    VerticalImages[i].OrientationHorizontal,
                    vector<int>(VerticalImages[i].ImageId, VerticalImages[i + 1].ImageId),
                    GetTagsFromTwoVerticalImages(VerticalImages[i].ImageTags, VerticalImages[i + 1].ImageTags)};

            HorizontalSlides.emplace_back(newSlide);
            HorizontalSlideCounter++;
        }
    }
};

int main()
{
    string input;
    string givenInput;
    ifstream nameFile;
    vector<string> rawImages;
    nameFile.open("Input-Data-Sets\\a_example.txt");

    while (std::getline(nameFile, givenInput))
    {
        rawImages.emplace_back(givenInput);
        cout<<"input : "<<givenInput<<"\n";
    }
    nameFile.close();
    return 0;
}
