#ifndef CS_COURSE_H_
#define CS_COURSE_H_

#include <iostream>
#include "Streamable.h"
#include "general.h"

namespace cs
{
   class Course : public Streamable
   {
   private:
      char courseCode_[MAX_COURSECODE_LEN + 1];
      char* courseTitle_;
      int credits_;
      int studyLoad_;

   public:
      Course();
      Course(const char*, const char*, int, int);
      Course(const Course&);                          //copy constructor
      Course& operator=(const Course&);               //assignment operator
      ~Course();
      //setters
      void courseCode(const char*);
      void courseTitle(const char*);
      void credits(int);
      void studyLoad(int);
      //getters
      const char* courseCode() const;
      const char*courseTitle_(const char*) const;
      int credits_(int) const;
      int studyLoad_(int) const;
      bool isEmpty() const;

   };
   //non member operator
   bool operator == (int&, const Course&);
   int operator += (int&, const Course&);
   std::ostream& operator<<(std::ostream&, const Course&);
}

#endif