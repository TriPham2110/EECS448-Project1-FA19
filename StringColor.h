#ifndef _stringcolor_h
#define _stringcolor_h

#include <string>

//https://stackoverflow.com/questions/9158150/colored-output-in-c

class StringColor {
	public:
		/*
		 * @pre none
		 *	     @param none
		 *	     @post constructor
		 *       @return none
		 */
		StringColor(){};

		static const std::string RESET;
		static const std::string BLACK;
		static const std::string RED;
		static const std::string GREEN;
		static const std::string YELLOW;
		static const std::string BLUE;
		static const std::string MAGENTA;
		static const std::string CYAN;
		static const std::string WHITE;
		static const std::string BOLDBLACK;
		static const std::string BOLDRED;
		static const std::string BOLDGREEN;
		static const std::string BOLDYELLOW;
		static const std::string BOLDBLUE;
		static const std::string BOLDMAGENTA;
		static const std::string BOLDCYAN;
		static const std::string BOLDWHITE;
		static std::string WATER;
		static std::string SHIP;
		static std::string BORDER;
		static std::string TEXT;
		static std::string HIT;
		static std::string MISS;
		static std::string SUNK;
		static std::string BACKGROUND;

		/**
		 *@pre none
		 *	    @param theme name
		 *	    @post changes the theme colors
		 *     @return none
		 */
		static void changeTheme(std::string themeName);
		/**
		 * @pre none
		 *	     @param none
		 *	     @post resets console to original color
		 *      @return none
		 */
		static void reset();

	private:
		/**
		 * @pre none
		 *	     @param a and b coordinates
		 *	     @post generates random integers between a and b
		 *      @return returns an integer
		 */
		static int RandInt(int a, int b);

		std::string theme = "default";
};
#endif
