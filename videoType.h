#ifndef videoType_H
#define videoType_H

#include <iostream>
#include <string>


using namespace std;

class videoType
{

	friend ostream& operator<< (ostream&, const videoType&);

private:
	string videoTitle;			//variable to store the name of the movie
	string movieStar1;			//variable to store the name of the star
	string movieStar2;			//variable to store the name of the star
	string movieProducer;		//variable to store the name of the
								//producer
	string movieDirector;		//variable to store the name of the
								//director
	string movieProductionCo;	//variable to store the name
								//of the production company
	int copiesInStock;			//variable to store the number of int copiesInstock;
								//copies in stock

public:

	void setVideoInfo(string title, string star1, string star2, string producer, string director, string productionCo, int setInStock);
	int getNoOfCopiesInStock() const;
	void checkOut();
	void checkIn();
	void printTitle() const;
	void printInfo() const;
	bool checkTitle(string title);
	void updateInStock(int num);
	void setCopiesInStock(int num);
	string getTitle() const;
	videoType(string title = "", string star1 = "", string star2 = "", string producer = "", string director = "", string productionCo = "", int setInStock = 0);

	bool operator==(const videoType&) const;
	bool operator!=(const videoType&) const;

};
#endif // !videoType
