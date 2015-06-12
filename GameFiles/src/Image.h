#ifndef IMAGE_H_
#define IMAGE_H_

#include<cstdlib>
#include<iostream>
#include<string>

class Image{
	public:
		Image();
		Image(std::string);
		Image(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);

		std::string getImageName();
		std::string getLine1();
		std::string getLine2();
		std::string getLine3();
		std::string getLine4();
		std::string getLine5();
		std::string getLine6();
		std::string getLine7();
		std::string getLine8();
		std::string getLongString();

		void setImageName(std::string);
		void setLine1(std::string);
		void setLine2(std::string);
		void setLine3(std::string);
		void setLine4(std::string);
		void setLine5(std::string);
		void setLine6(std::string);
		void setLine7(std::string);
		void setLine8(std::string);
		void setLongString();

	private:
		std::string imageName;
		std::string line1;
		std::string line2;
		std::string line3;
		std::string line4;
		std::string line5;
		std::string line6;
		std::string line7;
		std::string line8;
		std::string longString;
};

#endif /* IMAGE_H_ */