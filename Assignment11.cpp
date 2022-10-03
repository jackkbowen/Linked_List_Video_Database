
#include <iostream>
#include <fstream>
#include <string>
#include "videoType.h"
#include "videoListType.h"
using namespace std;


void createVideoList(ifstream &infile, videoListType& videoList);

void displayMenu();


int main()
{
    videoListType videoList;
    int choice;
    char ch;
    string title;

    ifstream infile;

    // open the input file
    infile.open("c:/Users/jackb/desktop/videoDat.txt");

    if (!infile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    //create the video list
    createVideoList(infile, videoList);
    infile.close();

    // show the menu
    displayMenu();
    cout << "Enter your choice: " << endl;
    cin >> choice;
    cin.get(ch);
    cout << endl;


    //process the requests
    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
                cout << "The store carries " << title << endl;

            else
                cout << "The store does not carry " << title << endl;
            break;

        case 2:
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                {
                    videoList.videoCheckOut(title);
                    cout << "Enjoy your movie: " << title << endl;
                }
                else
                    cout << "Currently " << title << " is out of stock." << endl;
            }

            else
                cout << "The store does not carry " << title << endl;

            break;

        case 3:
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                videoList.videoCheckIn(title);
                cout << "Thanks for returning " << title << endl;
            }
            else
                cout << "The store does not carry " << title << endl;

            break;

        case 4:
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                    cout << title << " is currently in " << "stock." << endl;
                else
                    cout << title << " is currently out " << "of stock." << endl;
            }
            else
                cout << "The store does not carry " << title << endl;

            break;

        case 5:
            videoList.videoPrintTitle();
            break;

        case 6:
            videoList.print();
            break;

        default:
            cout << "Invalid selection." << endl;
        }//end switch

        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;
        cin.get(ch);
        cout << endl;
    }

    return 0;
}

void createVideoList(ifstream& infile, videoListType& videoList)
{
    string title;
    string starl;
    string star2;
    string producer;
    string director;
    string productionCo;
    char ch;
    int instock;

    videoType newVideo;

    getline(infile, title);

    while (infile)
    {
        getline(infile, starl);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> instock;
        infile.get(ch);
        newVideo.setVideoInfo(title, starl, star2, producer, director, productionCo, instock);

        videoList.insertFirst(newVideo);
    
        getline(infile, title);
    }
}

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a "
         << "particular video." << endl;
    cout << "2: To check out a video." << endl;
    cout << "3: To check in a video." << endl;
    cout << "4: To check whether a particular video is "
         << "in stock." << endl;
    cout << "5: To print only the titles of all the videos."
         << endl;
    cout << "6: To print a list of all the videos." << endl;
    cout << "9: To exit" << endl;
}