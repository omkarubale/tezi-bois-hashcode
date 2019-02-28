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
  public:
    int N;
    int HorizontalImageCounter = 0;
    int VerticalImageCounter = 0;
    int HorizontalSlideCounter = 0;
    int VerticalSlideCounter = 0;
    vector<struct Image> HorizontalImages;
    vector<struct Image> VerticalImages;
    vector<struct Slide> HorizontalSlides;
    vector<struct Slide> VerticalSlides;

  public:
    void GetImages(vector<string> rawImages)
    {
        N = stoi(rawImages[0]);
        for (int i = 1; i < rawImages.size(); i++)
        {
            // Used to split string around spaces.
            istringstream ss(rawImages[i]);
            vector<string> currentRawImage;
            // Traverse through all words
            do
            {
                // Read a word
                string word;
                ss >> word;
                
                currentRawImage.emplace_back(word);
                // While there is more to read
            } while (ss);

            if (currentRawImage[0][0] == 'H')
            {
                Image HImage = {
                    HorizontalImageCounter,
                    i-1,
                    true,
                    vector<string>(currentRawImage.begin()+2,currentRawImage.end())
                };
                HorizontalImages.emplace_back(HImage);
                HorizontalImageCounter++;
            }
            else
            {
                Image VImage = {
                    VerticalImageCounter,
                    stoi(currentRawImage[1]),
                    false,
                    vector<string>(currentRawImage.begin()+2,currentRawImage.end())
                };
                VerticalImages.emplace_back(VImage);
                VerticalImageCounter++;
            }
        }
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

  public:
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

  public:
    void displaySlides()
    {
        for (int i = 0; i < HorizontalSlides.size(); i++)
        {
            cout << HorizontalSlides[i].ImageIds[0] << "\n";
        }

        for (int i = 0; i < VerticalSlides.size(); i++)
        {
            cout << VerticalSlides[i].ImageIds[0] << " " << VerticalSlides[i].ImageIds[1] << "\n";
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
        //cout<<"input : "<<givenInput<<"\n";
    }

    nameFile.close();

    Solution attempt;
    attempt.GetImages(rawImages);
    attempt.CreateSlides();
    attempt.displaySlides();

    return 0;
}
