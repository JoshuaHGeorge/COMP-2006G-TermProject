#include "Course.h"
#include "general.h"

namespace cs
{
   Course::Course()
   {
      courseCode_[0] = '\0';
      courseTitle_ = nullptr;
      credits_ = 0;
      studyLoad_ = 0;
   }


   Course::Course(const char* crsCd, const char* crsTit, int cred, int stdLd)
   {
      courseCode(crsCd);
      courseTitle(crsTit);
      credits(cred);
      studyLoad(stdLd);
   }

   Course::Course(const Course& source)                                 //copy constructor
   {
      courseCode(source.courseCode_);
      courseTitle(source.courseTitle_);
      credits(source.credits_);
      studyLoad(source.studyLoad_);
   }

   Course& Course::operator=(const Course& source)                      //assignment operator
   {
      if (this != &source)
      {
         courseCode(source.courseCode_);
         courseTitle(source.courseTitle_);
         credits(source.credits_);
         studyLoad(source.studyLoad_);
      }
      return *this;

   }

   Course::~Course()
   {
      delete[]courseTitle_;
      courseTitle_ = nullptr;
   }

   // Setters Functions

   void Course::courseCode(const char* courseCode)
   {
      strncpy(courseCode_, courseCode, MAX_COURSECODE_LEN);
      courseCode_[MAX_COURSECODE_LEN] = '\0';
   }

   void Course::courseTitle(const char* courseTitle)
   {
      if (courseTitle != nullptr)                            // allocate dyn memory
      {
         courseTitle_ = new char[strlen(courseTitle) + 1];
         strcpy(courseTitle_, courseTitle);                  //copy resource data
      }
      else
         courseTitle_ = nullptr;
   }
   
   void Course::credits(int credits)
   {
      credits_ = credits;
   }

   void Course::studyLoad(int studyLoad)
   {
      studyLoad_ = studyLoad;
   }

   // Getter Functions

   const char* Course::courseCode() const
   {
      return courseCode_;
   }
   const char* Course::courseTitle_(const char*) const
   {
      return courseTitle_;
   }
   int Course::credits_(int) const
   {
      return credits_;
   }
   int Course::studyLoad_(int) const
   {
      return studyLoad_;
   }
   bool Course::isEmpty() const
   {
      bool safeEmptyState;

      if (courseCode_[0] == '\0'
         && courseTitle_[0] == '\0'
         && credits_() == 0
         && studyLoad_() == 0)
      {
         safeEmptyState = true;
      }
      else
      {
         safeEmptyState = false;
      }
      return safeEmptyState;
   }

   std::ostream& operator<<(std::ostream& os, const Course&source)
   {
      source.write(os, true);
      return os;
   }

}


