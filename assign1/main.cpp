/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "course.h"

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

using namespace std;

/**
 * Represents a course a student can take in ExploreCourses.
 * You must fill in the types of the fields in this struct.
 * Hint: Remember what types C++ streams work with?!
 */


/**
 * (STUDENT TODO) Look at how the main function (at the bottom of this file)
 * calls `parse_csv`, `write_courses_offered`, and `write_courses_not_offered`.
 * Modify the signatures of these functions so that they work as intended, and then delete this
 * comment!
 */

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 * 3) The first line in the CSV defines the column names, so you can ignore it!
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {

  ifstream courses_file(filename);

  if (!courses_file.is_open())
  {
    cout << "No se pudo abrir el archivo" << endl;
  }
  else
  {
    string selected_course;
    vector <string> vector_selected_course;
    Course new_course;

    while (std::getline(courses_file,selected_course))
    {
      vector_selected_course = split(selected_course, ',');
      new_course.number_of_units = vector_selected_course[1];
      new_course.quarter = vector_selected_course[2];
      new_course.title = vector_selected_course[0];

      courses.push_back(new_course);
    }
    
  }

  courses_file.close();
}

/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 * 3) Remember to write the CSV column headers at the beginning of the output!
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
void write_courses_offered(std::vector<Course>& all_courses) {
  
  ofstream courses_file(COURSES_OFFERED_PATH);

  if (!courses_file.is_open())
  {
    cout << "No se pudo abrir el archivo" << endl;
  }
  else
  {
    int size = all_courses.size();
    courses_file << "Title,Number of Units,Quarter" << endl;
    vector <Course> indexes_to_delete;

    for (int i = 0; i < size; i++)
    {
      if (all_courses[i].quarter != "null")
      {
        courses_file << all_courses[i].title << "," << all_courses[i].number_of_units << "," << all_courses[i].quarter << endl;
        indexes_to_delete.push_back(all_courses[i]);
      }
    }

    for (int i = 0; i < indexes_to_delete.size(); i++)
    {
      delete_elem_from_vector(all_courses, indexes_to_delete[i]);
    }
    
  }

  courses_file.close();
}

/**
 * This function writes the courses NOT offered to the file
 * "student_output/courses_not_offered.csv".
 *
 * This function is ALWAYS called after the `write_courses_offered` function.
 * `unlisted_courses` will trivially contain classes that are not offered
 * since you delete offered classes from `all_courses` in the
 * `write_courses_offered` function.
 *
 * HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */
void write_courses_not_offered(std::vector<Course> unlisted_courses) {
  ofstream courses_file(COURSES_NOT_OFFERED_PATH);

  if (!courses_file.is_open())
  {
    cout << "No se pudo abrir el archivo" << endl;
  }
  else
  {
    courses_file << "Title,Number of Units,Quarter" << endl;
    int size = unlisted_courses.size();
    vector <Course> indexes_to_delete;
    

    for (int i = 0; i < size; i++)
    {
      if (unlisted_courses[i].quarter == "null")
      {
        courses_file <<unlisted_courses[i].title << "," <<unlisted_courses[i].number_of_units << "," <<unlisted_courses[i].quarter << endl;
        indexes_to_delete.push_back(unlisted_courses[i]);
      }
    }

    for (int i = 0; i < indexes_to_delete.size(); i++)
    {
      delete_elem_from_vector(unlisted_courses, indexes_to_delete[i]);
    }
    
  }

  courses_file.close();
}

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);
  courses.erase(courses.begin());
  
  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  
  write_courses_not_offered(courses);

  // return run_autograder();
}