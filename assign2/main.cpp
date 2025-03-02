/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <ctime>

std::string kYourName = "Felipe Quilumbango"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
 
  std::set<std::string> get_applicants;
  std::ifstream names_file(filename);

  if (!names_file.is_open())
  {
    std::cout << "Archive can't be open!" << std::endl;
  }
  else
  {
    std::string name_extracted;
    

    while (std::getline(names_file,name_extracted))
    {
      get_applicants.insert(name_extracted);
    }
    
  }

  names_file.close();

  return get_applicants;
}

std::pair<char,char> initialLetters(std::string name_used,std::string delimiter)
{
  
  const std::string firstName = name_used.substr(0, name_used.find(delimiter));
  const std::string lastName = name_used.substr(name_used.find(delimiter) + 1, name_used.length());
  std::pair<char, char> initialPair = {firstName[0], lastName[0]};

  return initialPair;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {

  std::pair<char, char> principalName = initialLetters(name, " ");
  
  std::queue<const std::string *> namesPointer;

  for (const std::string& nameSelected : students)
  {
    std::pair<char, char> setName = initialLetters(nameSelected, " ");

    if (principalName.first == setName.first && principalName.second == setName.second)
    {
      namesPointer.push(&nameSelected);
    }

  }
  return namesPointer;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) 
{
  
  if (!matches.empty())
  {
    std::srand(std::time(0));
    int queueSize = matches.size();
    int random_pos = std::rand() % queueSize;

    for (int i = 0; i < random_pos; ++i)
    {
      matches.push(matches.front());
      matches.pop();
    }

    return *matches.front();
  }
  else
  {
    return "NO MATCHES FOUND.";
  }
  
  
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"