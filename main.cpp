/*

Description : A program that sorts all of the countries in alphabetical order. Prompting the user to pick a question to see if the program has it in its binary search.

*/




#include <iostream>

#include <string>

#include <fstream>

#include <iomanip>




const int MAX_ARR_SIZE = 500;  // dimension of our array







// Function prototypes

bool populateArrays(std::string [], std::string [], int &);

void displayArrays(const std::string [], const std::string [], const int);

void swapElements(std::string &, std::string &);

void bubbleSort(std::string [], const int);

int binarySearch(const std::string [], const int, std::string);




int main() 

{

  // these arrays will hold data

  // captured from the file

  std::string countryCode[MAX_ARR_SIZE] = {""};

  std::string countryName[MAX_ARR_SIZE] = {""};

  int counter = -1;

  int result;

  std::string cCode;




if (!populateArrays(countryCode, countryName, counter))

{

  std::cout << "Error! Trouble locating the file.\nExiting..." << std::endl;

}

else

{

  displayArrays(countryCode, countryName, counter);

  std::cout << "-----------------------------------" << std::endl;

  bubbleSort(countryCode, counter);




  std::cout << "Enter the country code: ";

  getline (std::cin, cCode);

  result = binarySearch(countryCode, counter, cCode);

  if (result == -1)

    std::cout << cCode << " is not in the data set" << std::endl;

  else

    std::cout << cCode << " exists " << countryCode[result] << std::endl;

  

}

  

  return 0;

}




int binarySearch(const std::string arr[], const int arrSize, std::string target)

{

  int first = 0;          // position of the first array element

  int last = arrSize-1;   // index of the last array element

  int middle;             // calculated midpoint of every search

  int targetPos = -1;     // index of the target value

  bool found = false;     // flag that indicates success of the search




  // loop until we find it, or exhaust all of the tries

  while (!found && (first <= last))

  {

    middle = (first + last)/2;

    if (arr[middle] == target)

    {

      found = true;

      targetPos = middle;

    }

    else if(arr[middle] > target)

    {

      last = middle - 1;

    } 

    else

    {

      first = middle + 1;

    }

  }




  return targetPos;   // if found return the index of the string that matched the target otherwise - 1

}




void swapElements(std::string &a, std::string &b)

{

  std::string temp;




  temp = a;

  a = b;

  b = temp;

}




void bubbleSort(std::string arr[], const int arrSize)

{

  for (int maxElement = arrSize-1; maxElement > 0; maxElement--)

  {

    // perform swaps

    for (int i = 0; i < maxElement; i++)

    {

      // figure if it needs to swap

      if (arr[i] > arr[i+1])

        swapElements(arr[i], arr[i+1]);

    }

  }

}




void displayArrays(const std::string code[], const std::string country[], const int arrSize)

{

  // header

  std::cout << std::left

            << std::setw(5) << "Code"

            << std::setw(5) << "Country Name"

            << std::endl;

  // display the data from arrays

  for (int i = 0; i < arrSize; i++)

  {

    std::cout << std::left

              << std::setw(5) << code[i]

              << std::setw(5) << country[i]

              << std::endl;

  }

  

}




bool populateArrays(std::string code[], std::string country[], int &numRecords)

{

  std::ifstream iFile;

  bool fileExists = true;

  int index = 0;




  // opening the input file

  iFile.open("Countries.txt");

  if(!iFile)

    fileExists = false;

  else

  {

    // process the input file

    while(!iFile.eof())

    {

      getline(iFile, code[index], '|');

      getline(iFile, country[index], '\n');

      index++;

    }

    numRecords = index;

  }

  // close the file

  iFile.close();

  return fileExists;

}
