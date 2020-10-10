/*
  Leland Conn
  CS 3307 Individual Assignment
  Main file to use user input to create a graph to visualize covid data
  October 7, 2020
*/

#include <iostream>
#include "Country.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

// compare function for the case of ascending order and new confirmed cases
bool compare_A_newConfirmed (Country i,Country j) { return (i.get_newConfirmed()<j.get_newConfirmed()); }

// compare function for the case of ascending order and new deaths
bool compare_A_newDeaths (Country i,Country j) { return (i.get_newDeaths()<j.get_newDeaths()); }

// compare function for ascending order and new recovered cases
bool compare_A_newRecovered (Country i,Country j) { return (i.get_newRecovered()<j.get_newRecovered()); }

// compare function for ascending order and total confirmed cases
bool compare_A_totalConfirmed (Country i,Country j) { return (i.get_totalConfirmed()<j.get_totalConfirmed()); }

// compare function for ascending order and total deaths
bool compare_A_totalDeaths (Country i,Country j) { return (i.get_totalDeaths()<j.get_totalDeaths()); }

// compare function for ascending order and total recovered cases
bool compare_A_totalRecovered (Country i,Country j) { return (i.get_totalRecovered()<j.get_totalRecovered()); }

// compare function for descending order and new confirmed cases
bool compare_D_newConfirmed (Country i,Country j) { return (i.get_newConfirmed()>j.get_newConfirmed()); }

// compare function for the case of descending order and new deaths
bool compare_D_newDeaths (Country i,Country j) { return (i.get_newDeaths()>j.get_newDeaths()); }

// compare function for descending order and new recovered cases
bool compare_D_newRecovered (Country i,Country j) { return (i.get_newRecovered()>j.get_newRecovered()); }

// compare function for descending order and total confirmed cases
bool compare_D_totalConfirmed (Country i,Country j) { return (i.get_totalConfirmed()>j.get_totalConfirmed()); }

// compare function for descending order and total deaths
bool compare_D_totalDeaths (Country i,Country j) { return (i.get_totalDeaths()>j.get_totalDeaths()); }

// compare function for descending order and total recovered cases
bool compare_D_totalRecovered (Country i,Country j) { return (i.get_totalRecovered()>j.get_totalRecovered()); }

bool myfunction (int i,int j) { return (i<j); }

int main() {
    
    // File pointer 
    fstream file; 

    // Ask user to input file name with csv data
    string fName;
    cout << "\nEnter file name: " << endl;
    cin >> fName;
  
    // Open an existing file 
    file.open(fName);

    // Check if the file succesfully
    if (!file.is_open()) {
        cout << "Invalid file name." << endl;
        return 0;
    }

    string line, temp; 

    // read an entire row and 
    // store it in a string variable 'line' 
    getline(file, line); 

    vector<Country> countries;

    // while reading a line from file returns successful
    // continue the loop and store the line in variable line
    while (getline(file, line)) { 

        // create a vector to hold all the elements of line
        // (elements are seperated by commas in csv file)
        vector<string> result;
        stringstream s_stream(line); //create string stream from line

        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            
            // If the substring starts with '"' then check if it ends with " because
            // if it doesn't then you are missing part of the substring and should
            // use getline to get the remainder (which should end at a comma)
            if (substr.at(0) == '"' && substr.at(substr.length() - 1) != '"') {
                string substr2;
                getline(s_stream, substr2, ',');
                substr = substr + substr2;
            }
            // add the substring to  vector holding all elements of the line
            result.push_back(substr);
        }
        // check if the vector is sufficient size so no out of bound errors are thrown
        if (result.size() > 2) {
            
            // Create the variables that will store data for
            // the Country objects, representing each country
            string countryName = result.at(0);
            string countryCode = (result.at(1)).substr(1,2);
            int newConfirmed = stoi(result.at(3));
            int newDeaths = stoi(result.at(4));
            int newRecovered = stoi(result.at(5));
            int totalConfirmed = stoi(result.at(8));
            int totalDeaths = stoi(result.at(9));
            int totalRecovered = stoi(result.at(10));
            
            // Initialize a country object with the above data variables
            Country country(countryName, countryCode, newConfirmed, newDeaths, newRecovered, totalConfirmed, totalDeaths, totalRecovered);
            
            // add country to vector
            countries.push_back(country);
        }
    } 

    // Close file
    file.close();

   // Create a dictionary to store keys being the various kinds of user input for data type
   // and the associated values being the full name so the print statement at end can be dynamic
   std::map <string, string> dataCategories;

   dataCategories["TC"] = "Total Confirmed Cases";
   dataCategories["TD"] = "Total Deaths";
   dataCategories["TR"] = "Total Recovered Cases";
   dataCategories["NC"] = "New Confirmed Cases";
   dataCategories["ND"] = "New Deaths";
   dataCategories["NR"] = "New Recovered Cases";

    // Ask the user for the kind of data he/she would like to see
    // Then store the response in variable dataType
    string dataType, order;
    cout << "\nWhat data would you like to see? (Enter initials) " << endl;
    cout << "\nOptions:\n TC - Total Confirmed\n TD - Total Deaths\n TR - Total Recovered\n NC - New Confirmed\n ND - New Deaths\n NR - New Recovered\n" << endl;
    cin >> dataType;

    if (dataCategories[dataType] == "") {
        cout << "Invalid data type." << endl;
        return 0;
    }

    // Ask the user for the sorting method desired
    // Then store the response in variable order
    cout << "\nHow should the data be sorted? (Enter single letter) " << endl;
    cout << "\nOptions: \n A - Ascending\n D - Descending\n" << endl;
    cin >> order;

    if (order != "A" && order != "D") {
        cout << "Invalid sort order." << endl;
        return 0;
    }

    cout << endl;

    // Create an array arr that will store the data from top or bottom 10 countries
    int arr[10];

    // Based on the data type and sort order a certain sort by function function
    // Will be used to organize the vector countries storing all the instances of countries
    // then a for loop will iterate to fill the array with the correct data in the right order
    if (dataType == "NC") {
         if (order == "A") {
             std::sort (countries.begin(), countries.end(), compare_A_newConfirmed);
         }
         else {
             std::sort (countries.begin(), countries.end(), compare_D_newConfirmed);
         }
         for (int j = 0; j < 10; j++) {
             arr[j] = countries.at(j).get_newConfirmed();
         }
    }
    else if (dataType == "ND") {
         if (order == "A") {
             std::sort (countries.begin(), countries.end(), compare_A_newDeaths);
         }
         else {
             std::sort (countries.begin(), countries.end(), compare_D_newDeaths);
         }
         for (int j = 0; j < 10; j++) {
             arr[j] = countries.at(j).get_newDeaths();
         }
    }
    else if (dataType == "NR") {
         if (order == "A") {
             std::sort (countries.begin(), countries.end(), compare_A_newRecovered);
         }
         else {
             std::sort (countries.begin(), countries.end(), compare_D_newRecovered);
         }
         for (int j = 0; j < 10; j++) {
             arr[j] = countries.at(j).get_newRecovered();
         }
    }
    else if (dataType == "TC") {
         if (order == "A") {
             std::sort (countries.begin(), countries.end(), compare_A_totalConfirmed);
         }
         else {
             std::sort (countries.begin(), countries.end(), compare_D_totalConfirmed);
         }
         for (int j = 0; j < 10; j++) {
             arr[j] = countries.at(j).get_totalConfirmed();
         }
    }
    else if (dataType == "TD") {
         if (order == "A") {
             std::sort (countries.begin(), countries.end(), compare_A_totalDeaths);
         }
         else {
             std::sort (countries.begin(), countries.end(), compare_D_totalDeaths);
         }
         for (int j = 0; j < 10; j++) {
             arr[j] = countries.at(j).get_totalDeaths();
         }
    }
    else if (dataType == "TR") {
         if (order == "A") {
             std::sort (countries.begin(), countries.end(), compare_A_totalRecovered);
         }
         else {
             std::sort (countries.begin(), countries.end(), compare_D_totalRecovered);
         }
         for (int j = 0; j < 10; j++) {
             arr[j] = countries.at(j).get_totalRecovered();
         }
    }

    //This will be used for a later print statement
    //to contextualize the size of '#'
    float proxy;

   // Iterate through the array and print the desired graph
   // to visualize the data
   for (int i = 0; i < 10; i++) {
       
       // Depending on the sort order the first or last record will
       // have a default length for its '#' characters to create
       // a base for comparison
       if ((order == "D" && i == 0) || (order == "A" && i == 9)) {
           
           string bar = "######################################################################";
           
           if (arr[i] == 0) {
               bar = "";
           }

           cout << countries.at(i).get_countryCode() << " |" << bar << endl;
           cout << "   |" << endl;

           //Calculate what number a single '#' represents
           proxy = arr[i] / 70.0;

           continue;
       }

       float num = 0;

       // Now store the assigned number of '#' for the record
       // Check if the base line comparison is not zero to ensure
       // we do not divide by zero
       if (order == "D" && arr[0] != 0) {
           num = arr[i] * 70 / arr[0];
       }
       else if (order == "A" && arr[9] != 0) {
           num = arr[i] * 70 / arr[9];
       }

       cout << countries.at(i).get_countryCode() << " |";
       
       // Print '#' for the record based on the proxy
       // adjusted number for the chosen data type
       for (int x = 0; x < num; x++) {
           cout << "#";
       }

       cout << "\n";
       cout << "   |" << endl;
   }

   cout << "--------------------------------------------------------------------------" << endl;

   // Round proxy to two decimal places
   proxy = roundf(proxy * 100) / 100;

   cout << dataCategories[dataType] << "; Each # is approx. " << proxy << " cases\n" << endl;

   return 0;
} 