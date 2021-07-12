/*
 * =====================================================================================
 *
 *       Filename:  GradeBook.hpp
 *
 *    Description:  Fig. 3.15: GradeBook class definitions presents the public
 *                  interface of the class.
 *                  Member-function definitions appear in GradeBook.cpp.
 *
 *        Version:  1.0
 *        Created:  08/07/2020 19:59:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Akif AYDIN - akifaydin52@gmail.com
 *   
 *
 * =====================================================================================
 */

#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <string>

class GradeBook
{
public:
   explicit GradeBook(const std::string &);

   // SETTERS
   void setCourseName(const std::string &);

   // GETTERS
   std::string getCourseName();

   void displayMessage();

private:
   std::string courseName;
};

#endif // GRADEBOOK_HPP