void convertDistance(const char * from, const char * to, double value)
{
    
    double convertedValue;
    printf("\n");

    printf("%s %s","This is From: ", from);
    printf("%s %s","\n This is to: ", to);

    printf("\n");
    // Since the relationship between temperatures can be expressed as a linear equation
    // This means that their functions and function inverses can be abstracted by 2 functions
    if((strcmp(from,KILOMETER) == 0 ) && (strcmp(to, MILES)))
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
        printOutConversionString(value, from, inverseEqutionOfLine(value, 0, 1000), to);
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
 strcmp   {,        printOutConversionString( == 0value, )from, value, to);
    }
        
}