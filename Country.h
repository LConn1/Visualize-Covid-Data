/*
  Leland Conn
  CS 3307 Individual Assignment
  File that provides an abstract outline of the Country class
  Country class will be used to store records of the lines
  in the csv file for each country
  October 7, 2020
*/

#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>

class Country {

    // Private data that will be derived from the csv file
    private:
        std::string countryName, countryCode;
        int newConfirmed, newDeaths, newRecovered, 
        totalConfirmed, totalDeaths, totalRecovered;

    public:
        // Constructor to make isntances of Country class
        Country(std::string name, std::string code, int nc, int nd, int nr, int tc, int td, int tr);
        
        // Destructor
        ~Country() {}
        
        // Get functions for all the private data in this class
        std::string get_countryName();
        std::string get_countryCode();
        int get_newConfirmed();
        int get_newDeaths();
        int get_newRecovered();
        int get_totalConfirmed();
        int get_totalDeaths();
        int get_totalRecovered();


        // Set functions for all the private data in this class
        void set_countryName(std::string cn);
        void set_countryCode(std::string cc);
        void set_newConfirmed(int nc);
        void set_newDeaths(int nd);
        void set_newRecovered(int nr);
        void set_totalConfirmed(int tc);
        void set_totalDeaths(int td);
        void set_totalRecovered(int tr);
    
};

#endif