//Deskchanger for i3wm, created by Collin "Flagger44" McKinley <contact@flagger44.net>
//Contact me if you have any issues with the code
//Requires feh and a day and night picture to be placed in the pictures folder
//More info on the github page https://github.com/flagger44/i3deskchange
#include <iostream>
#include <ctime>
using namespace std;
int main ()
{
	while(true){
		time_t timedata;
		struct tm * timeinfo;
		char buffer[80];
		char hour[80];
		time (&timedata);
		timeinfo = localtime(&rawtime);
		strftime(hour,sizeof(hour),"%M", timeinfo);
		strftime(buffer,sizeof(buffer),"%H",timeinfo);
		string str(buffer);
		string min(hour);
		int time = atoi(str.c_str());
		int minint = atoi(min.c_str());
			if(minint == 00){
				if(time > 20){//8PM to 11PM
					system("feh --bg-scale ~/Pictures/night.jpg");
				}
				else if(time < 6){//midnight to 6AM
					system("feh --bg-scale ~/Pictures/night.jpg");
				}
				else{//if all else fails default to day bg
					system("feh --bg-scale ~/Pictures/day.jpeg");
			}
		}
	}
  return 0;
}
