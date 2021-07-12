/******************************************************************************
 
 Exercises 3.17

 (Computerization of Health Records) A health care issue that has been in the 
 news lately is the computerization of health records. This possibility is being 
 approached cautiously because of sensitive privacy and security concerns, among 
 others. [We address such concerns in later exercises.] Computerizing health 
 records could make it easier for patients to share their health profiles and 
 histories among their various health care professionals. This could improve the 
 quality of health care, help avoid drug conflicts and erroneous drug 
 prescriptions, reduce costs and in emergencies, could save lives. In this 
 exercise, you’ll design a “starter” HealthProfile class for a person. The class 
 attributes should include the person’s first name, last name, gender, date of 
 birth (consisting of separate attributes for the month, day and year of birth), 
 height (in inches) and weight (in pounds). Your class should have a constructor 
 that receives this data. For each attribute, provide set and get functions. 
 The class also should include functions that calculate and return the user’s 
 age in years, maximum heart rate and target-heart-rate range (see Exercise 3.16), 
 and body mass index (BMI; see Exercise 2.30). Write an application that prompts 
 for the person’s information, instantiates an ob- ject of class HealthProfile 
 for that person and prints the information from that object—including the 
 person’s first name, last name, gender, date of birth, height and weight—then 
 calculates and prints the person’s age in years, BMI, maximum heart rate and 
 target-heart-rate range. It should also display the “BMI values” chart from 
 Exercise 2.30. Use the same technique as Exercise 3.16 to cal- culate the 
 person’s age.

******************************************************************************/

#include <iostream>

#include <string>

#include "HealthProfile.hpp"

int main()
{

    HealthProfile hp1("Akif", "Aydin", "Male", 23, 6, 1984, 176, 71);
    hp1.showHealthProfile();
    return 0;
}