#include <stdio.h>
#include <stdbool.h> 

int main()
{
    const int distanceConversionOption = 1, temperatureConversionOption = 2, quitOption = 3,
        kilometerToMilesOption = 1, milesToKilometerOption = 2, mainMenuOption = 3,
        celsiusToFahrenheitOption = 1, fahrenheitToCelsiusOption = 2, nestedMainMenuOption = 3,
        nestedMenuQuitOption = 4;
    int  mainMenuUserInput = 0, userInput = 0;


    bool quit = false;
    while(quit == false)
    {
        printf("\n");
        printf("Convert Temperatures and Measurements \n");
        printf("1. Distance Conversion \n");
        printf("2. Temperature Conversion \n");
        printf("3. Quit \n");
        printf("Choice: ");

        scanf("%d", &mainMenuUserInput);
        printf("\n");


        if(mainMenuUserInput == distanceConversionOption)
        {
            bool displayDistanceConversion = true;
            while (displayDistanceConversion == true)
            {
                double distanceToConvert = 0, convertedKmToMiles = 0, convertedMilesToKm = 0;      // where Km => kilometers
                printf("\n");
                printf("Distance Converter \n");
                printf("1 Kilometers to Miles \n");
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
                        printf("Enter the distance in Kilometers: ");
                        scanf("%lf",&distanceToConvert);
                        
                        convertedKmToMiles = (0.62137119 * distanceToConvert);

                        printf("%-.2f %s %-.2f %s", distanceToConvert, " Kilometers is ", convertedKmToMiles, " Miles \n");

                    }
                    else if(userInput == 2)
                    {
                        printf("Enter the distance in Miles: ");
                        scanf("%lf",&distanceToConvert);

                        convertedMilesToKm = (distanceToConvert / 0.62137119);

                        printf("%-.2f %s %-.2f %s", distanceToConvert, " Miles is ", convertedMilesToKm, " Kilometers \n");
                    }
                    else
                    {
                        printf("Invalid Input try again \n");
                    }
                }

            }
            
        }
        else if(mainMenuUserInput == temperatureConversionOption)
        {
            bool displayTemperatureConversion = true;
            while (displayTemperatureConversion == true)
            {
                bool validInputs = false;
                double temperatureToConvert = 0, convertedCelsiusToFahrenheitValue = 0, convertedFahrenheitToCelsiusValue = 0;


                printf("\n");
                printf("Temperature Converter \n");
                printf("1 Celsius to Fahrenheit \n");
                printf("2. Fahrenheit to Celsius\n");
                printf("3. Main Menu \n");
                printf("4. QUit \n");
                printf("Choice: ");

                scanf("%d", &userInput);
                printf("\n");


                if ((userInput == nestedMainMenuOption) || (userInput == nestedMenuQuitOption))
                {
                    displayTemperatureConversion = false;
                }
                else
                {
                    if (userInput == 1)
                    {
                        printf("Enter temperature in Celsius: ");
                        scanf("%lf",&temperatureToConvert);

                        convertedCelsiusToFahrenheitValue = (temperatureToConvert * 1.8) + 32;

                        printf("%-.2f %s %-.2f %s", temperatureToConvert, " Celsius is ", convertedCelsiusToFahrenheitValue, " Fahrenheit \n");

                    }
                    else if(userInput == 2)
                    {
                        printf("Enter temperature in Fahrenheit: ");
                        scanf("%lf",&temperatureToConvert);

                        convertedFahrenheitToCelsiusValue = (temperatureToConvert - 32) * (double)5 / 9;
                        printf("%-.2f %s %-.2f %s", temperatureToConvert, " Fahrenheit is ", convertedFahrenheitToCelsiusValue, " Celsius \n");
                    }
                    else
                    {
                        printf("Invalid Input try again \n");
                    }
                }


            }
            
        }


        if((mainMenuUserInput == quitOption) || (userInput == nestedMenuQuitOption))
        {
            quit = true;
        }
        
    }

    
}