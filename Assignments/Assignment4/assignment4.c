#include <stdio.h>
#include <stdbool.h> 


const unsigned short int distanceConversionOption = 1, temperatureConversionOption = 2, quitOption = 3,
        kilometerToMilesOption = 1, milesToKilometerOption = 2, mainMenuOption = 3,
        celsiusToFahrenheitOption = 1, fahrenheitToCelsiusOption = 2, nestedMainMenuOption = 3,
        nestedMenuQuitOption = 4, minimumDistance = 0, maximumDistance = 20000;
const int minimumTemperature = -110, maximumTemperature = 1000;

// based on y = mx + b
double equationOfLineResult(double slope, double x, double yIntercept)
{
    return (slope * x + yIntercept);
}

// based on y = mx + b
double inverseEqutionOfLine(double y, double slope, double yIntercept)
{
    return (y - yIntercept) / slope;
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


void displayDistanceConversion()
{
    int userInput;
    bool displayDistanceConversion = true;
    while (displayDistanceConversion == true)       // While loop to re-display menu if input = invalid
    {
        bool validInputs = false;
        double distanceToConvert = 0, convertedKmToMiles = 0, convertedMilesToKm = 0;      // where Km => kilometers
        printf("\n");
        printf("Distance Converter \n");
        printf("1. Kilometers to Miles \n");
        printf("2. Miles to kilometers \n");
        printf("3. Main Menu \n");
        printf("4. QUit \n");
        printf("Choice: ");

        scanf("%d", &userInput);
        printf("\n");

        if ((userInput == nestedMainMenuOption) || (userInput == nestedMenuQuitOption))
        {
            displayDistanceConversion = false;
        }
        else
        {
            if (userInput == 1)
            {
                validInputs = false;
                while (validInputs == false)        // While loop to re-display menu if input = invalid
                {

                    printf("Enter the distance in Kilometers: ");
                    scanf("%lf",&distanceToConvert);
                    
                    if((distanceToConvert >= minimumDistance) && (distanceToConvert <= maximumDistance))
                    {
                        validInputs = true;

                        convertedKmToMiles = (0.62137119 * distanceToConvert);

                        printf("%-.2f %s %-.2f %s", distanceToConvert, " Kilometers is ", convertedKmToMiles, " Miles \n");
                
                    }
                    else
                    {
                        printf("\n");
                        printf(" Invalid Inputs try again. \n");
                    }

                }

            }
            else if(userInput == 2)
            {
                validInputs = false;
                while (validInputs == false)        // While loop to re-display menu if input = invalid
                {
                    printf("Enter the distance in Miles: ");
                    scanf("%lf",&distanceToConvert);
                    
                    if((distanceToConvert >= minimumDistance) && (distanceToConvert <= maximumDistance))
                    {
                        validInputs = true;

                        convertedMilesToKm = (distanceToConvert / 0.62137119);

                        printf("%-.2f %s %-.2f %s", distanceToConvert, " Miles is ", convertedMilesToKm, " Kilometers \n");
                    }
                    else
                    {
                        printf("\n");
                        printf(" Invalid Inputs try again. \n");
                    }
                }
            }
            else
            {
                printf("Invalid Input try again \n");
            }
        }

    }
            
    
}


int getUserTemperatureInput()
{
    int userInput;

    printf("\n");
    printf("Temperature Converter \n");
    printf("1 Celsius to Fahrenheit \n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Main Menu \n");
    printf("4. QUit \n");
    printf("Choice: ");

    scanf("%d", &userInput);
    printf("\n");

    return userInput;

}


void temperatureConversion()
{
    int userInput;
    bool displayTemperatureConversion = true;
    while (displayTemperatureConversion == true)        // While loop to re-display menu if input = invalid
    {
        bool validInputs = false;
        double temperatureToConvert = 0, convertedCelsiusToFahrenheitValue = 0, convertedFahrenheitToCelsiusValue = 0;

        userInput = getUserTemperatureInput();
        

        if ((userInput == nestedMainMenuOption) || (userInput == nestedMenuQuitOption))
        {
            displayTemperatureConversion = false;
        }
        else
        {
            if (userInput == 1)
            {
                validInputs = false;
                while (validInputs == false)        // While loop to re-display menu if input = invalid
                {
                    printf("Enter temperature in Celsius: ");
                    scanf("%lf",&temperatureToConvert);
                    
                    if((temperatureToConvert >= minimumTemperature) && (temperatureToConvert <= maximumTemperature))
                    {
                        validInputs = true;

                        // convertedCelsiusToFahrenheitValue = (temperatureToConvert * 1.8) + 32;
                        // Since the relationship between temperatures can be expressed as a linear equation
                        // This means that their functions and function inverses can be abstracted by 2 functions
                        convertedCelsiusToFahrenheitValue = equationOfLineResult(1.8, temperatureToConvert, (double)32);

                        printf("%-.2f %s %-.2f %s", temperatureToConvert, " Celsius is ", convertedCelsiusToFahrenheitValue, " Fahrenheit \n");
                
                    }
                    else
                    {
                        printf("\n");
                        printf(" Invalid Inputs try again. \n");
                    }
                }
            }
            else if(userInput == 2)
            {
                validInputs = false;
                while (validInputs == false)        // While loop to re-display menu if input = invalid
                {
                    printf("Enter temperature in Fahrenheit: ");
                    scanf("%lf",&temperatureToConvert);
                    
                    if((temperatureToConvert >= minimumTemperature) && (temperatureToConvert <= maximumTemperature))
                    {
                        validInputs = true;

                        // convertedCelsiusToFahrenheitValue = (temperatureToConvert * 1.8) + 32;
                        // Since the relationship between temperatures can be expressed as a linear equation
                        // This means that their functions and function inverses can be abstracted by 2 functions
                        // convertedFahrenheitToCelsiusValue = (temperatureToConvert - 32) * (double)5 / 9;
                        convertedFahrenheitToCelsiusValue = inverseEqutionOfLine(temperatureToConvert, (double)(1.8), (double)(32));

                        printf("%-.2f %s %-.2f %s", temperatureToConvert, " Fahrenheit is ", convertedFahrenheitToCelsiusValue, " Celsius \n");
                    }
                    else
                    {
                        printf("\n");
                        printf(" Invalid Inputs try again. \n");
                    }
                }
                
            }
            else
            {
                printf("Invalid Input try again \n");
            }
        }

    }
        
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
           displayDistanceConversion();
        }
        else if(mainMenuUserInput == temperatureConversionOption)
        {
           temperatureConversion();
        }

        if((mainMenuUserInput == quitOption) || (userInput == nestedMenuQuitOption))
        {
            quit = true;
        }
    }

    
}