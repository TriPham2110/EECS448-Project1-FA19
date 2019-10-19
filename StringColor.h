#ifndef _stringcolor_h
#define _stringcolor_h

#include <string>

//https://stackoverflow.com/questions/9158150/colored-output-in-c

class StringColor {
    public:
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
    private:

};
#endif