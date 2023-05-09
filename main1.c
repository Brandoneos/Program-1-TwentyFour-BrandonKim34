/*-------------------------------------------
Program 1: Basic Calculator
Course: CS 211, Spring 2023, UIC
System: Replit
Author: Brandon Kim
------------------------------------------- */
#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>
 //Declarations of 2 functions used
double getValue(double int1, double int2, char symbol);
double getValue2(double f1, char s1, double f2, char s2, double f3, char s3, double f4);

int main(int argc, char * argv[]) {
  int easyMode = 1; // 1 = on, 0 = off
  int debugMode = 0; // 1 = on, 0 = off

  int i; // counting variable for number of operators entered

  //(1) Starts with identifying the arguments in order to see if the user wants easy mode and debug mode on.

  if (argc != 3 && argc != 5 && argc != 1) {
    printf("Incorrect arguments were given, please try again.\n\n");
    return 1;
  }

  char modeString[2] = "-e"; // strings to compare arguments with
  char debugString[2] = "-d";

  int Mcounter = 0; //associated with knowing if the user wants easyMode on/off
  int dcounter = 0; // associated with knowing if the user wants debugMode on/off
  int modeLocation = 0; //determines whether the easyMode is before the debugMode argument
  //if modeLocation is 2, easyMode is before, else debug Mode is before the easyMode argument
  //checks if argc is 3
  if (argc == 3) {
    Mcounter++;
    dcounter++;
    for (int p = 0; p < 2; p++) {
      if (modeString[p] == argv[1][p]) {
        Mcounter++;
      }
      if (debugString[p] == argv[1][p]) {
        dcounter++;
      }
    }

  }
  //checks if argc is 5
  if (argc == 5) {
    //for loop checks first arguments other than file name
    for (int p = 0; p < 2; p++) {
      if (modeString[p] == argv[1][p]) {
        Mcounter++;
        modeLocation++;
      }
      if (debugString[p] == argv[1][p]) {
        dcounter++;
      }
    }
    //for loop checks second arguments
    for (int p = 0; p < 2; p++) {
      if (modeString[p] == argv[3][p]) {
        Mcounter++;

      }
      if (debugString[p] == argv[3][p]) {
        dcounter++;

      }
    }
    //if argc is not 1,3,5 it means the user entered the wrong number of arguments.
    if (!(dcounter == 3 && Mcounter == 3)) {
      if (argc != 1) {
        printf("Incorrect arguments were given, please try again.\n\n");
        return 1;
      }
    }

  }
  //if statement checking if both easyMode and debugMode were mentioned in arguments of commandline
  if (dcounter == 3 && Mcounter == 3) {
    if (modeLocation == 2) {
      easyMode = atoi(argv[2]);

      debugMode = atoi(argv[4]);
    } else {
      easyMode = atoi(argv[4]);
      debugMode = atoi(argv[2]);
    }
    //else if statement checking if debugMode was mentioned in arguments
  } else if (dcounter == 3) {
    debugMode = atoi(argv[2]);
    //else if statement checking if easyMode was mentioned in arguments
  } else if (Mcounter == 3) {
    easyMode = atoi(argv[2]);
  } else {
    if (argc != 1) { //if there were the wrong arguments given
      printf("Incorrect arguments were given, please try again.\n\n");
      return 1;
    }
    //else, there was only the executable file run
  }

  printf("Welcome to the game of TwentyFour.\n");
  printf("Use each of the four numbers shown below exactly once, \n");
  printf("combining them somehow with the basic mathematical operators (+,-,*,/) \n");
  printf("to yield the value twenty-four.\n\n");

  //int value associated with continuing the program again.
  int continue1 = 0;
  int continue2 = 0;
  int firstTimeThrough = 0;
  //While loop to loop the process if the user wants to continue
  while (continue2 == 0) {
    if (firstTimeThrough == 0) {
      srand(1);
    }

    while (continue1 == 0) {
      int randomInte = rand();
      int randomInt = 4 * (randomInte % 10);
      // Initialize random number generator.
      // (2) Here is where we generate random numbers.
      int j, k, l, m;
      //if easyMode was on, then pick between the 10 solutions given

      if (easyMode == 1) {
        //easymode numbers
        int easyNumbers[] = {
          3,
          9,
          4,
          1,
          8,
          5,
          8,
          1,
          6,
          1,
          5,
          1,
          2,
          8,
          7,
          8,
          5,
          2,
          9,
          2,
          2,
          6,
          8,
          4,
          5,
          5,
          4,
          3,
          6,
          6,
          2,
          6,
          8,
          4,
          2,
          6,
          6,
          2,
          8,
          1
        };

        j = easyNumbers[randomInt];
        k = easyNumbers[randomInt + 1];
        l = easyNumbers[randomInt + 2];
        m = easyNumbers[randomInt + 3];
      }
      //if either debugMode is on, or easyMode is off, we have to go through the 7 nested loops. 

      char input2[4] = "+-*/";
      int a, b, c, d, e, f, g;
      int count = 1; //count to output the number of solutions(3188)
      //Loop to loop through digits 1-9 four times, and the symbols(+-*/) 3 times for
      // the calculation to 24
      //pick random number between 1-3188
      int rand1 = (randomInte % 3188) + 1;;

      for (a = 1; a < 10; a++) {
        for (b = 1; b < 10; b++) {
          for (c = 1; c < 10; c++) {
            for (d = 1; d < 10; d++) {
              for (e = 0; e < 4; e++) {
                for (f = 0; f < 4; f++) {
                  for (g = 0; g < 4; g++) {
                    if (fabs(getValue2(a, input2[e], b, input2[f], c, input2[g], d) - 24) < 0.001) {
                      if (debugMode == 1 && firstTimeThrough == 0) { //if debugMode is on, then print all the solutions.
                        printf("%d. %d%c%d%c%d%c%d\n", count, a, input2[e], b, input2[f], c, input2[g], d);
                      }
                      if (easyMode == 0) {
                        //if hardmode is on, based on the random int count, a random solution from the 3188 solutions is chosen and given to the j,k,l,m integers which are the numbers to use.
                        //hardmode numbers
                        //use random int to decide on the four numbers.
                        if (count == rand1) {
                          j = a;
                          k = b;
                          l = c;
                          m = d;
                        }
                      }

                      count++;
                    }
                  }
                }
              }
            }
          }
        }
      }

      printf("The numbers to use are: %d, %d, %d, %d.", j, k, l, m);
      printf("\nEnter the three operators to be used, in order (+,-,*, or /): ");
      //checks if the entered characters are valid and if there are 3 of them.
      int valid1 = 0;
      char input1[40];
      scanf("%s", input1);
      i = 0;
      //i here is used to check if the number of operators is 3.
      while (input1[i] != '\0') {
        // printf("%c\n",input1[i]);
        if (input1[i] != '+' && input1[i] != '-' && input1[i] != '*' && input1[i] != '/') {
          valid1 = 1;
          //if any of the arguments were not the correct operators, then it cause an error
        }
        i++;
      }
      if (i != 3) {
        printf("Error! The number of operators is incorrect. Please try again.\n");
        firstTimeThrough = 1;
        break;

      }
      //if statement to check the value of valid1 in order to determine if the operators entered were valid operators
      if (valid1 == 1) {
        printf("Error! Invalid operator entered. Please try again.\n");
        firstTimeThrough = 1;
        break;
      }

      // (3) Doing the Calculation now
      int answer1 = (int)(getValue((double)(j), (double)(k), input1[0]));
      printf("%d %c %d = %d.\n", j, input1[0], k, (int)(answer1));
      //same with the second calculation
      int answer2 = (int)(getValue((int)(answer1), (double)(l), input1[1]));
      printf("%d %c %d = %d.\n", (int)(answer1), input1[1], l, (int)(answer2));
      //same with the last calculation
      int answer3 = (int)(getValue((int)(answer2), (double)(m), input1[2]));
      printf("%d %c %d = %d.\n", (int)(answer2), input1[2], m, (int)(answer3));
      //(4) Checking if the result equals 24

      if (fabs((double)(answer3) - 24) < 0.001) {
        printf("Well done! You are a math genius.\n\n");
      } else {
        printf("Sorry. Your solution did not evaluate to 24.\n\n");
      }

      //(5) prompt the continue command in order to redo the process. 
      printf("Would you like to play again? Enter N for no and any other character for yes. ");
      char yesNo[1] = {
        'P'
      };
      scanf("%s", yesNo);
      printf("\n");
      if (yesNo[0] == 'N') { //prompt specified capital N as the only character in order to stop the program
        printf("Thanks for playing!");
        continue1 = 1;
        continue2 = 1;
      }
      firstTimeThrough = 1;
    }
  }
  printf("\n");
  return 0;

}
// function to calculate between 2 numbers and one operator given a character. 
double getValue(double int1, double int2, char symbol) {
  if (symbol == '+') {

    return int1 + int2;
  } else if (symbol == '-') {

    return int1 - int2;
  } else if (symbol == '*') {

    return int1 * int2;
  } else if (symbol == '/') {

    return int1 / int2;
  } else {
    printf("Error was found\n");
    return 7000.0; // value that is not possible to get
  }
}
//function to run all of the numbers with all of the operators for the solutions, returns the result of the operations done to the numbers by using the getValue function 3 times.
double getValue2(double f1, char s1, double f2, char s2, double f3, char s3, double f4) {
  double ans1 = getValue(f1, f2, s1);
  //error only after the first call to getValue();

  double ans2 = getValue(ans1, f3, s2);

  double ans3 = getValue(ans2, f4, s3);

  return ans3;
}