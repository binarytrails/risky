#include "mapReader.h"


int main()
{
	//Example of the regular map being loaded
	reader("World.map");
	//Example of a custom map being loaded
	reader("Caribbean.map");
	//Example of an invalid map being rejected
	reader("Invalid.map");

}
