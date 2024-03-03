#include <stdio.h>
#include <stdbool.h>
#include <string.h>


const unsigned short int distanceConversionOption = 1, temperatureConversionOption = 2, quitOption = 3,
        kilometerToMilesOption = 1, milesToKilometerOption = 2, mainMenuOption = 3,
        celsiusToFahrenheitOption = 1, fahrenheitToCelsiusOption = 2, nestedMainMenuOption = 3,
        nestedMenuQuitOption = 4, minimumDistance = 0, maximumDistance = 20000;
const int minimumTemperature = -110, maximumTemperature = 1000;
const double FAHRENHEIT_INTERCEPT_VALUE = 32;
const double FAHRENHEIT_SLOPE_VALUE = 1.8;
const double KELVIN_INTERCEPT_VALUE = 273.15;

// Convert options
const int CONVERT_TO_CELSIUS = 1, CONVERT_TO_FAHRENHEIT = 2, CONVERT_TO_KELVIN = 3;
const char CELSIUS = 'C', FAHRENHEIT = 'F', KELVIN = 'K';
const char * KILOMETER = "km";
const char * MILES = "mi";
const char * FEET = "ft";
const char * METERS = "m";

// based on y = mx + b
double equationOfLineResult(double slope, double x, double yIntercept)
{
    return (slope * x) + (yIntercept);
}

// based on y = mx + b
double inverseEqutionOfLine(double y, double slope, double yIntercept)
{
    return (y - yIntercept) / slope;
}


double getDistanceToConvert()
{
    fflush(stdin);
    bool validInputs = false;
    double distanceToConvert = 0;

    validInputs = false;
    while (validInputs == false)        // While loop to re-display menu if input = invalid
    {
        printf("Enter the distance from 0.0 to 20000.1: ");
        scanf("%lf",&distanceToConvert);
        
        if((distanceToConvert >= minimumDistance) && (distanceToConvert <= maximumDistance))
        {
            validInputs = true;
        }
        else
        {
            printf("\n");
            printf(" Invalid Inputs try again. \n");
        }
    }

    return distanceToConvert;

}


void getDistanceUnit(const char * toOrFrom, char * unit)
{
    bool validInputs = false;
    // static char unit[2];

    validInputs = false;
    while (validInputs == false)        // While loop to re-display menu if input = invalid
    {
        printf("Enter unit to  convert ");
        printf("%s", toOrFrom);
        printf(" (km, mi, ft, m): ");
        fflush(stdin);
        scanf("%s",unit);
        
        if((strcmp(unit, KILOMETER) == 0) || (strcmp(unit, MILES) == 0) || (strcmp(unit, FEET) == 0) || (strcmp(unit, METERS) == 0))
        {
            validInputs = true;
        }
        else
        {
            printf("\n");
            printf(" Invalid Inputs try again. \n");
        }
    }

    // return unit;
}


double getTemperatureToConvert()
{
    fflush(stdin);
    bool validInputs = false;
    double temperatureToConvert = 0;

    validInputs = false;
    while (validInputs == false)        // While loop to re-display menu if input = invalid
    {
        printf("Enter the Temperature from -110.0 to 1000.0: ");
        scanf("%lf",&temperatureToConvert);
        
        if((temperatureToConvert >= minimumTemperature) && (temperatureToConvert <= maximumTemperature))
        {
            validInputs = true;
        }
        else
        {
            printf("\n");
            printf(" Invalid Inputs try again. \n");
        }
    }

    return temperatureToConvert;

}


char getTempeeratureUnit(const char * toOrFrom)
{
    bool validInputs = false;
    char unit;

    validInputs = false;
    while (validInputs == false)        // While loop to re-display menu if input = invalid
    {
        printf("Enter unit to  convert ");
        printf("%s", toOrFrom);
        printf(" (C, F, K): ");
        fflush(stdin);
        scanf("%c",&unit);
        
        if((unit == 'C') || (unit == 'F') || (unit == 'K'))
        {
            validInputs = true;
        }
        else
        {
            printf("\n");
            printf(" Invalid Inputs try again. \n");
        }
    }

    return unit;

}


void printOutConversionString(double from, const char * fromUnit, double to, const char * toUnit)
{
    printf("%-.4f %s %s %s %-.4f %s %s", from, "", fromUnit, " converts", to, " ", toUnit);
}


void printOutConversionChar(double from, char fromUnit, double to, char toUnit)
{
    printf("%-.4f %s %c %s %-.4f %s %c", from, "", fromUnit, " converts", to, "", toUnit);
}


void convertDistance(const char * from, const char * to, double value)
{

    printf("\n");
    // Since the relationship between temperatures can be expressed as a linear equation
    // This means that their functions and function inverses can be abstracted by 2 functions
    if((strcmp(from,KILOMETER) == 0 ) && (strcmp(to, MILES) == 0))
    {
        printOutConversionString(value, from, equationOfLineResult(0.62137119, value, 0), to);
    }
    else if((strcmp(from, KILOMETER) == 0) && (strcmp(to, FEET) == 0))
    {
        printOutConversionString(value, from, equationOfLineResult(3280.8398950131, value, 0), to);
    }
    else if((strcmp(from, KILOMETER) == 0) && (strcmp(to, METERS) == 0))
    {
        printOutConversionString(value, from, equationOfLineResult(1000, value, 0), to);
    }
    else if((strcmp(from, MILES) == 0) && (strcmp(to, KILOMETER) == 0))
    {
        printOutConversionString(value, from, inverseEqutionOfLine(value, 0.62137119, 0), to);
    }
    else if((strcmp(from, MILES) == 0) && (strcmp(to, FEET) == 0))
    {
        printOutConversionString(value, from, equationOfLineResult(5280, value, 0), to);
    }
    else if((strcmp(from, MILES) == 0) && (strcmp(to, METERS) == 0))
    {
        printOutConversionString(value, from, equationOfLineResult(1609.344, value, 0), to);
    }
    else if((strcmp(from, FEET) == 0) && (strcmp(to, KILOMETER) == 0))
    {
        printOutConversionString(value, from, inverseEqutionOfLine(value, 3280.8398950131, 0), to);
    }
    else if((strcmp(from, FEET) == 0) && (strcmp(to, MILES) == 0))
    {
        printOutConversionString(value, from, inverseEqutionOfLine(value, 5280, 0), to);
    }
    else if((strcmp(from, FEET) == 0) && (strcmp(to, METERS) == 0))
    {
        printOutConversionString(value, from, equationOfLineResult(0.3048, value, 0), to);
    }
    else if((strcmp(from, METERS) == 0) && (strcmp(to, KILOMETER) == 0))
    {
        printOutConversionString(value, from, inverseEqutionOfLine(value, 1000, 0), to);
    }
    else if((strcmp(from, METERS) == 0) && (strcmp(to, MILES) == 0))
    {
        printOutConversionString(value, from, inverseEqutionOfLine(value, 1609.344, 0), to);
    }
    else if((strcmp(from, METERS) == 0) && (strcmp(to, FEET) == 0))
    {
        printOutConversionString(value, from, inverseEqutionOfLine(value ,0.3048, 0), to);
    }
    else if((strcmp(from, to) == 0))
    {
        printOutConversionString(value, from, value, to);
    }
            
}


void convertTemperature(char from, char to, double value)
{
    double convertedValue;
    printf("\n");

    printf("%s %c","This is From: ", from);
    printf("%s %c","\n This is to: ", to);

    printf("\n");
    // Since the relationship between temperatures can be expressed as a linear equation
    // This means that their functions and function inverses can be abstracted by 2 functions
    if((from == CELSIUS) && (to == FAHRENHEIT))
    {
        convertedValue = equationOfLineResult(FAHRENHEIT_SLOPE_VALUE, value, FAHRENHEIT_INTERCEPT_VALUE);
        printOutConversionChar(value, from, convertedValue, to);
    }
    else if((from == CELSIUS) && (to == KELVIN))
    {
        convertedValue = equationOfLineResult(1, value, KELVIN_INTERCEPT_VALUE);
        printOutConversionChar(value, from, convertedValue, to);
    }
    else if((from == FAHRENHEIT) && (to == CELSIUS))
    {
        convertedValue = inverseEqutionOfLine(value, (FAHRENHEIT_SLOPE_VALUE), FAHRENHEIT_INTERCEPT_VALUE);
        printOutConversionChar(value, from, convertedValue, to);
    }
    else if((from == FAHRENHEIT) && (to == KELVIN))
    {
        convertedValue = inverseEqutionOfLine((value - KELVIN_INTERCEPT_VALUE), (FAHRENHEIT_SLOPE_VALUE), FAHRENHEIT_INTERCEPT_VALUE);
        printOutConversionChar(value, from, convertedValue, to);
    }
    else if((from == KELVIN) && (to == CELSIUS))
    {
        convertedValue = inverseEqutionOfLine(value, (1), (KELVIN_INTERCEPT_VALUE));
        printOutConversionChar(value, from, convertedValue, to);
    }
    else if((from == KELVIN) && (to == FAHRENHEIT))
    {
        convertedValue = equationOfLineResult(FAHRENHEIT_SLOPE_VALUE, (value - KELVIN_INTERCEPT_VALUE), FAHRENHEIT_INTERCEPT_VALUE);
        printOutConversionChar(value, from, convertedValue, to);
    }
    else if((from == to))
    {
        printOutConversionChar(value, from, value, to);
    }
        
}


int getUserInput()
{
    int mainMenuUserInput = 0;

    printf("\n");
    printf("Convert Temperatures and Measurements \n");
    printf("1. Distance Conversion \n");
    printf("2. Temperature Conversion \n");
    printf("3. Quit \n");
    printf("Choice: ");

    scanf("%d", &mainMenuUserInput);
    printf("\n");

    return mainMenuUserInput;
}


int main()
{
    int userInput = 0;
    int  mainMenuUserInput = 0;

    bool quit = false;
    while(quit == false)
    {
        mainMenuUserInput = getUserInput();

        if(mainMenuUserInput == distanceConversionOption)
        {
            double distanceInput;
            char convertFrom[3];
            char convertTo[3];
            
            distanceInput = getDistanceToConvert();
            
            getDistanceUnit("from", convertFrom);
            getDistanceUnit("to", convertTo);

            // printf("\n");

            // printf("%s %s","This is From: ", convertFrom);
            // printf("%s %s","\n This is to: ", convertTo);
           
           convertDistance(convertFrom, convertTo, distanceInput);
        }
        else if(mainMenuUserInput == temperatureConversionOption)
        {
            double tempInput;
            char convertFrom, convertTo;
            
            tempInput = getTemperatureToConvert();
            
            convertFrom = getTempeeratureUnit("from");

            convertTo = getTempeeratureUnit("to");

            convertTemperature(convertFrom, convertTo, tempInput);
        }

        if((mainMenuUserInput == quitOption) || (userInput == nestedMenuQuitOption))
        {
            quit = true;
        }
    }

    
}
