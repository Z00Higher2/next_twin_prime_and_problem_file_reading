// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1C

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
   string filename = "problems.csv";
   ifstream file(filename);
   if (file.fail()) // if filename is not found
   { 
      cerr << "Error: " << filename << " not found" << endl;
      exit(1); // EXIT_FAILURE
   }

   string problem, solution;
   double answer, correct_answer, correct, num_of_questions;
   num_of_questions = 0;
   correct = 0;

   while(getline(file, problem, ',') && getline(file, solution)) // if the file is open and there are questions
   { 
      correct_answer = stod(solution); // get the answer from the solution string
      cout << "What is " << problem << "? ";
      cin >> answer;
      num_of_questions++; // increment the number of questions

      if (answer == correct_answer) // if the answer is correct
      { 
         cout << "True" << endl; // print true
         correct++; // increment the correct
      } 
      else 
      {
         cout << "False" << endl; // print false
      }
   
   }
   double grades = 100 * (correct/num_of_questions);
   
   if (grades >= 90)
   { // if the grade was 90 or higher

      char letter = 'A'; // sets the character to A
      cout << "percentage correct: " << grades << "%" << endl; // prints the grade
      cout << "letter grade: " << letter << endl; // prints out letter grade: A

   } 
   else if (grades >= 80 && grades < 90)
   { // if the grade was 80 or higher and less than 90

      char letter = 'B'; // sets the character to B
      cout << "percentage correct: " << grades << "%" << endl; // prints the grade
      cout << "letter grade: "<< letter << endl; // prints out letter grade: B

   } 
   else if (grades >= 70 && grades < 80)
   { // if the grade was 70 or higher and less than 80
      
      char letter = 'C'; // sets the character to C
      cout << "percentage correct: " << grades << "%" << endl; // prints the grade
      cout << "letter grade: "<< letter << endl; // prints out letter grade: C

   }
   else if (grades >= 60 && grades < 70)
   { // if the grade was 60 or higher and less than 70
      
      char letter = 'D'; // sets the character to D
      cout << "percentage correct: " << grades << "%" << endl; // prints the grade
      cout << "letter grade: "<< letter << endl; // prints out letter grade: D

   }
   else 
   { // Otherwise

      char letter = 'F'; // sets the character to F
      cout << "percentage correct: " << grades << "%" << endl; // prints the grade
      cout << "letter grade: "<< letter << endl; // prints out letter grade: F

   }

   file.close();
   return 0;  
}