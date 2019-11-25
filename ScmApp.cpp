#include "ScmApp.h"
#include "array"

namespace cs
{
   ScmApp::ScmApp()
   {
      // make an empty array of the max size
      Course* courseList_[] = new Course[MAX_NO_RECS]; 
      // set all the pointers in the array to safe null values
      for(int i = 0; i < MAX_NO_RECS; i++){
         courseList_[i] = nullptr;
      }

      // set the default value of number of courses to 0
      noOfCourses = 0;
   }


   ScmApp::ScmApp(const ScmApp& source)                           //copy constructor
   {
      // copy the number of courses from the object being copied
      noOfCourses = *source.noOfCourses;

      // add all the courses from the list of the object being copied to the new object
      Course* courseList_ = new Course[MAX_NO_RECS];
      for(int i = 0; i < MAX_NO_RECS; i++){
         courseList_[i] = *source.courseList_[i];
      }
   }

   ScmApp& ScmApp::operator=(const ScmApp& source)        //assignment operator
   {
      //basically the exact same as the copy constructor, just with an overloaded operator
      noOfCourses = source.noOfCourses;
      Course* courseList_ = new Course[MAX_NO_RECS];
      for(int i = 0; i < MAX_NO_RECS; i++){
         courseList_[i] = *source.courseList_[i];
      }
   }

   ScmApp::~ScmApp()
   {
      delete[] courseList_;
   }

   void ScmApp::pause() const
   {
      cout << "Press Enter to continue..." << endl;
   }

/* Menu function. Has been modified to:
   - Take user selection
   - Validates user selection is valid option
   - Clears cin to ensure no further issues 
   */
   int ScmApp::menu()
   {  
      //Select: user's selection.
      int select;
      //Options: Menu options. Can be added to for addition options later. 
      int options [5] = {0,1,2,3,4};

      //Existing code, menu format
      cout << "Seneca Course Management Tool" << endl; 
      cout << "1 - List courses." << endl;
      cout << "2 - Display the details of a course." << endl;
      cout << "3 - Add a course." << endl;
      cout << "4 - Change the study load of a course." << endl;
      cout << "0 - Exit program" << endl;
      cout << ">"

      //cin is set to select, then cleared. 
      cin >> select;
      cin.ignore();

      //validates that select is within the menu options. Returns if so, returns failure number if not.
      for(int i = 0; i < noOfCourses; i++) {
         if (select == i) {
            return select;
         }
      }
      return -1;
   }

   void ScmApp::listCourses()const
   {
      cout << " Row | Code | Course Title  | Credit | Load| System | Lang |" << endl;  
      cout << "-----|------|---------------|--------|-----|--------|------|" << endl;
      for(int i = 0; i < courseList_; i++){
         courseList_.Display();
      }
   }

   int ScmApp::searchACourse(const char* courseCode)const
   {
      if (courseList_ == nullptr){ //check for null array
         return -1;
      }
      for(int i = 0; i < numberOfCourses; i++){
         if(courseList_[i] == courseCode)){ //defines
            return i; //returns the first index that it comes across
         }
      }
      return -1; //nothing found, returns -1 as specified
   }

/*  ChangeStudyLoad function
   Has been given functionality:
   - Validates the inputted course code exists
   - Allows users to input a new study load and have the selected function be change
   - Kicks users out of the function of the course code does not exist in the function
   */
   void ScmApp::changeStudyLoad(const char* courseCode)
   {
      //For and If worrk together to validate courseCode, to ensure it exists
      for(int i = 0; i < noOfCourses; i++;) {
         if(searchACourse(courseCode) != -1) {
            //Functions allows user to input a new study load if it is found.
            int changing;
            cout << "Please enter the amount of the study load: ";
            cin << changing;

            *courseList_[i].studyLoad(changing);
         }
         //Function ends if it is not found.
         else {
            cout << "Not Found!" << endl;
         }
      }
   }

   void ScmApp::addACourse()
   {

   }
   int ScmApp::run()
   {
      // variable to hold user input
      int input;

      do{
         input = menu(); // get the user input

         // perform the action associated with the user input
         switch(input){
            case 0:
               cout << "Goodbye!!";
               break;
            case 1:
               listCourses();
               break;
            case 2:
               searchACourse();
               break;
            case 3:
               addACourse();
               break;
            case 4:
               changeStudyLoad();
               break;
            default:
               cout << "===Invalid Selection, try again.===";
         }
         pause();
      }while(input!=0)

      return 0;
   }

}