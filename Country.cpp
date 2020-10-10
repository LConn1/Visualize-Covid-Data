/*
  Leland Conn
  File to provide the implementation of Country class
  Country class will be used to store records of the lines
  in the csv file for each country
  October 7, 2020
*/

#include <iostream>
#include "Country.h"
using namespace std;


/*
  Function name: Country
  Description: This is a constructor to create an instance of the Country class
  Parameter descriptions: 
      name = the name of the country
      code = the code of the country
      nc = the new confirmed cases for the country
      nd = the new deaths for the country
      nr = the new recovered cases for the country
      tc = the total cases for the country
      td = the total deaths for the country
      tr = the total recovered cases for the country
  Return description: n/a
*/
Country::Country(string name, string code, int nc, int nd, int nr, int tc, int td, int tr) {
    Country::countryName = name;
    Country::countryCode = code;
    Country::newConfirmed = nc;
    Country::newRecovered = nr;
    Country::newDeaths = nd;
    Country::totalConfirmed = tc;
    Country::totalDeaths = td;
    Country::totalRecovered = tr;
}

/*
  Function name: get_countryName
  Description: This functions returns a string of the country name
  Parameter descriptions: n/a
  Return description: return the name of the country
*/
string Country::get_countryName(){return(countryName);}

/*
  Function name: get_countryCode
  Description: This functions returns a string of the country code
  Parameter descriptions: n/a
  Return description: return the code of the country
*/
string Country::get_countryCode(){return(countryCode);}

/*
  Function name: get_newConfirmed
  Description: This functions returns an int of the number of new confirmed cases for the country
  Parameter descriptions: n/a
  Return description: return the the number of new confirmed cases for the country
*/
int Country::get_newConfirmed(){return(newConfirmed);}

/*
  Function name: get_newDeaths
  Description: This functions returns an int of the number of new deaths for the country
  Parameter descriptions: n/a
  Return description: return the the number of new deaths for the country
*/
int Country::get_newDeaths(){return(newDeaths);}

/*
  Function name: get_newRecovered
  Description: This functions returns an int of the number of new recovered cases for the country
  Parameter descriptions: n/a
  Return description: return the the number of new recovered cases for the country
*/
int Country::get_newRecovered(){return(newRecovered);}

/*
  Function name: get_totalConfirmed
  Description: This functions returns an int of the number of total confirmed cases for the country
  Parameter descriptions: n/a
  Return description: return the the number of total confirmed cases for the country
*/
int Country::get_totalConfirmed(){return(totalConfirmed);}

/*
  Function name: get_totalDeaths
  Description: This functions returns an int of the number of total deaths for the country
  Parameter descriptions: n/a
  Return description: return the the number of total deaths for the country
*/
int Country::get_totalDeaths(){return(totalDeaths);}

/*
  Function name: get_totalRecovered
  Description: This functions returns an int of the number of total recovered cases for the country
  Parameter descriptions: n/a
  Return description: return the the number of total recovered cases for the country
*/
int Country::get_totalRecovered(){return(totalRecovered);}


/*
  Function name: set_countryName
  Description: This functions sets the country name
  Parameter descriptions: cn = The new country name (a string)
  Return description: n/a
*/
void Country::set_countryName(string cn){countryName = cn;}

/*
  Function name: set_countryCode
  Description: This functions sets the country code
  Parameter descriptions: cc = The new country code (a string)
  Return description: n/a
*/
void Country::set_countryCode(string cc){countryCode = cc;}

/*
  Function name: set_newConfirmed
  Description: This functions sets the new confirmed cases
  Parameter descriptions: nc = The number of new confirmed cases (an int)
  Return description: n/a
*/
void Country::set_newConfirmed(int nc){newConfirmed = nc;}

/*
  Function name: set_newDeaths
  Description: This functions sets the new deaths number
  Parameter descriptions: nd = The number of new deaths (an int)
  Return description: n/a
*/
void Country::set_newDeaths(int nd){newDeaths = nd;}

/*
  Function name: set_newRecovered
  Description: This functions sets the new recovered cases
  Parameter descriptions: nr = The number of new recovered cases (an int)
  Return description: n/a
*/
void Country::set_newRecovered(int nr){newRecovered = nr;}

/*
  Function name: set_totalConfirmed
  Description: This functions sets the total confirmed cases
  Parameter descriptions: tc = The number of total confirmed cases (an int)
  Return description: n/a
*/
void Country::set_totalConfirmed(int tc){totalConfirmed = tc;}

/*
  Function name: set_totalDeaths
  Description: This functions sets the total deaths
  Parameter descriptions: td = The number of total deaths (an int)
  Return description: n/a
*/
void Country::set_totalDeaths(int td){totalDeaths = td;}

/*
  Function name: set_totalRecovered
  Description: This functions sets the total recovered cases
  Parameter descriptions: tr = The number of total recovered cases (an int)
  Return description: n/a
*/
void Country::set_totalRecovered(int tr){totalRecovered = tr;}
