#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Function to calculate BMI
float calculate_bmi(float feet, float inches, float weight) {
    float height = (feet * 12 + inches) * 0.025; // Convert to meters
    height = height * height;
    weight = weight * 0.45; // Convert to kg
    return weight / height;
}

// Function to get the BMI category
string get_bmi_category(float bmi) {
    if (bmi < 18.5) return "Underweight";
    else if (bmi < 25) return "Normal Weight";
    else if (bmi < 30) return "Overweight";
    else return "Obese";
}

TEST_CASE("Test BMI Calculation and Categories") {

    // Test for calculate_bmi function
    CHECK(calculate_bmi(5, 3, 125) == doctest::Approx(22.7).epsilon(0.1)); 
    
    // Test for get_bmi_category function
    CHECK(get_bmi_category(18.6) == "Normal Weight");
    CHECK(get_bmi_category(18.4) == "Underweight");
    CHECK(get_bmi_category(29) == "Overweight");
    CHECK(get_bmi_category(30.1) == "Obese");
}

