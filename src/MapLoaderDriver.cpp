#include "mapReader.h"


int main()
{
	//Example of the regular map being loaded
	reader("assets/World.map");
	//Example of a custom map being loaded
	reader("assets/Caribbean.map");
	//Example of an invalid map being rejected
	reader("assets/Invalid.map");

}
