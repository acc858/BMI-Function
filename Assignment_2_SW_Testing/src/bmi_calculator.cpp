#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;


float calculate_bmi(float feet, float inches, float weight) {
    float height = (feet * 12 + inches) * 0.025; // Convert to meters
    height = height * height;
    weight = weight * 0.45; // Convert to kg
    return weight / height;
}

// Determines BMI category
string get_bmi_category(float bmi) {
    if (bmi < 18.5) return "Underweight";
    else if (bmi < 25) return "Normal Weight";
    else if (bmi < 30) return "Overweight";
    else return "Obese";
}


void bmi_calculator() {
    float feet, inches, weight;
    
    cout << "Please input the integer for feet: ";
    cin >> feet;
    cout << "Please input the value for inches. Decimals are acceptable: ";
    cin >> inches;
    cout << "Please input the value for weight in pounds: ";
    cin >> weight;

    float bmi = calculate_bmi(feet, inches, weight);
    string category = get_bmi_category(bmi);

    cout << "The BMI value is: " << bmi << endl;
    cout << "The BMI category is: " << category << endl;
}

// Function to get valid user input (Y/N)
char get_user_choice() {
    char input;
    while (true) {
        cout << "Would you like to calculate a BMI? Input Y or N: ";
        cin >> input;
        if (input == 'Y' || input == 'N') return input;
        cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
    }
}

int main() {
    char input = get_user_choice();

    while (input == 'Y') {
        bmi_calculator();
        input = get_user_choice();
    }

    cout << "Goodbye!" << endl;
    return 0;
}
