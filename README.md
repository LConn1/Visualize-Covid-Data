# Visualize-Covid-Data
This C++ program visualizes Covid-19 data for over 180 countries in a bar graph format, using user input for the desired sort order and category of data shown (e.g. new case count, total cases, new death count, or total deaths).

A custom class Country is created to contain a country's record of data from this dataset. The class has members to contain the country's name, two-letter country code, and six statistical counts (new confirmed cases, new deaths,
new recovered cases, total confirmed cases, total deaths, and total recovered cases). The name and country code are stored using strings and the statistical counts are stored as numbers. A constructure is made to initialize objects
of this class and a a destructor is provided as as well. Additionally, a vector is used to store these records. Filestream is used to read the csv and populate the vector created. Lastly sorting based on created functions is used to
organize the vector dependant on the user input (ascending or descending order, and choosing which data type). Once the vector is organized in the desired manner the vector is iterated on to print a bar chart like the image provided
(i.e. image.png).
