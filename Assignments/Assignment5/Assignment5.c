#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct fileData{
    char * name;
    float assignmentGrade;
    float midtermGrade;
    float finalGrade;
    char letterGrade;
    bool isPlusGrade;
    float semesterPercentageGrade;

};


struct fileReport{
    int numStudents;
    int numAs;
    int numBplus;
    int numBs;
    int numCplus;
    int numCs;
    int numDs;
    int numFs;
    float averageAssignmentGrade;
    float averageMidtermGrade;
    float averageFinalGrade;
};


struct gradeAverages{
    float averageAssignmentGrade;
    float averageMidtermGrade;
    float averageFinalGrade;
};


void endline();

void printInt(const char * text, int value);

void fprintInt(FILE * fptr,const char * text, int value);

void printFloat(const char * text, float value);

void fprintFloat(FILE * fptr,const char * text, float value);

void printDataValues(const struct fileData data);

void fprintDataValues(FILE * fptr, const struct fileData data);

void printReportCli(const struct fileReport report);

bool gradeIsplus(const struct fileData data);

struct fileData processLine(const char * line);

void processLetterGrade(struct fileData * data);

void setReportValuesToZero(struct fileReport * report);

struct gradeAverages returnAverages(const struct fileData * data, int numLines);

struct fileReport getFileReport(const struct fileData * data, int numLines);

void deepCopyData(struct fileData * dataToModify, const struct fileData dataToCopy);

float getPercentageValue(float percentageContribution, float value);

void computeSemesterPercentageGrade(struct fileData * data);

void printReportToFile(FILE * fptr, const struct fileReport report);

void outputReportToFile(const char * fileName, const struct fileReport report, const struct fileData * allData, int numLines);


int main()
{
    FILE * fptr;
    int numLinesInFile = 0;
    char line[800];
    double assignmentGrade;
    double midtermGrade;
    double finalGrade;
    
    struct fileReport report;
    
    // opening the file in read mode
    fptr = fopen("students.csv", "r");
 
    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    else
    {
        while(!feof(fptr))
        {
            fscanf(fptr,"%s",line);
            numLinesInFile++;
        }

        rewind(fptr);           // Reset File pointer to beginning of file
        // struct fileData allData[numLinesInFile];
        struct fileData allData[5];
        int count = 0;
        while(!feof(fptr))
        {
            struct fileData data;
            
            fscanf(fptr,"%s",line);
            
            data = processLine(line);   // Populate struct with data from line

            deepCopyData(&(allData[count]), data);
            // printDataValues(allData[count]);
            // assert(allData[count].midtermGrade == data.midtermGrade);

            count = count + 1;

        }

        for(int count = 0; count < numLinesInFile; count++)
        {
            computeSemesterPercentageGrade(&(allData[count]));
            processLetterGrade(&(allData[count]));
            // printDataValues(allData[count]);
        }
        
        report = getFileReport(allData, numLinesInFile);
        printReportCli(report);
        outputReportToFile("final.txt", report, allData, numLinesInFile);


        fclose(fptr);
    }

    return 0;
}


void endline()
{
    printf("\n");
}


void printInt(const char * text, int value)
{
    printf("%s%d", text, value);
    printf("\n");
}


void fprintInt(FILE * fptr,const char * text, int value)
{
    fprintf(fptr, "%s%d", text, value);
    fprintf(fptr, "\n");
}


void printFloat(const char * text, float value)
{
    printf("%s%0.2f", text, value);
    printf("\n");
}


void fprintFloat(FILE * fptr,const char * text, float value)
{
    fprintf(fptr, "%s%0.2f", text, value);
    fprintf(fptr, "\n");
}


void printDataValues(const struct fileData data)
{
    printf("%s%s", "Name: ", data.name);
    printf("\n");
    printf("%s%f", "Assignment Grade: ", data.assignmentGrade);
    printf("\n");
    printf("%s%f", "Midterm Grade: ", data.midtermGrade);
    printf("\n");
    printf("%s%f", "Final Grade: ", data.finalGrade);
    printf("\n");
    printf("%s%c", "Letter Grade: ", data.letterGrade);
    printf("\n");
    printf("%s%f", "Semester Percentage Grade: ", data.semesterPercentageGrade);
    printf("\n");

    if(data.isPlusGrade == true)
    {
        printf("+");
    }
    printf("\n");
    printf("\n");

}


void fprintDataValues(FILE * fptr, const struct fileData data)
{
    fprintf(fptr, "%s", data.name);
    fprintf(fptr, " ");
    fprintf(fptr, "%0.2f", data.semesterPercentageGrade);
    fprintf(fptr, " ");
    fprintf(fptr, "%c", data.letterGrade);

    if(data.isPlusGrade == true)
    {
        fprintf(fptr, "+");
    }

    fprintf(fptr, "\n");

}


void printReportCli(const struct fileReport report)
{
    printf("\n");
    printInt("Total students: ", report.numStudents);
    endline();
    printInt("Number of A's: ", report.numAs);
    printInt("Number of B+'s: ", report.numBplus);
    printInt("Number of B's: ", report.numBs);
    printInt("Number of C+'s: ", report.numCplus);
    printInt("Number of C's: ", report.numCs);
    printInt("Number of D's: ", report.numDs);
    printInt("Number of F's: ", report.numFs);
    printf("\n");
    /* printFloat("Average Assignments Grade: ",report.averageAssignmentGrade);
    printFloat("Average Midterm Exam Grade: ",report.averageMidtermGrade);
    printFloat("Average final Exam Grade: ",report.averageFinalGrade) */;
}


bool gradeIsplus(const struct fileData data)
{
    bool isPlus = false;
    if(data.isPlusGrade == true)
    {
        isPlus = true;
    }

    return isPlus;
}

// Populate struct with data from line
struct fileData processLine(const char * line)
{
    int position = 0;
    char delimeter = ',';
    struct fileData data;

    // Creat Character arrays larger than the required size.
    char stringOne[200];
    char stringTwo[200];
    char stringThree[200];
    char stringFour[200];

    for(int count = 0; count < strlen(line) + 1; count++)
    {
        char tempChar[200];       // Creates an array of characters to hold a single character and appends a null terminator
        char currentValue[2];   // Creates an array of characters to hold hold a character from this line. 
        currentValue[0] = line[count];
        currentValue[1] = '\0';

        
        if(line[count] != delimeter && (line[count] != (count - 1)))    // If this line not delimeter add it to array to add to strings
        {
            strcat(tempChar, currentValue);
        }
        else if((line[count] == delimeter) || (count == (strlen(line) - 1))) // Bug here not reading string four
        { 
            if(position == 0)
            {
                strcat(stringOne, tempChar);
                // printf("%s%s", "stringOne: ", stringOne);
            }
            else if (position == 1)
            {
                strcat(stringTwo, tempChar);
                // printf("%s%s", "stringTwo: ", stringTwo);
            }
            else if(position == 2)
            {
                strcat(stringThree, tempChar);
                // printf("%s%s", "stringThree: ", stringThree);
            }
            else
            {
                printf("Invalid data format, check if there is an empty line at end of file.");
                exit(0);
            }
            
            strcpy(tempChar, "");       //Clear temperary values

            position++;
        }

        if(count == (strlen(line) - 1))
        {
            position++;
            strcat(stringFour, tempChar);
            // printf("%s%s", "stringFour: ", stringFour);
        }

    }

    strcpy(data.name, stringOne);
    data.assignmentGrade = atof(stringTwo);
    data.midtermGrade = atof(stringThree);
    data.finalGrade = atof(stringFour);
    
    return data;
}


void processLetterGrade(struct fileData * data)
{
    // printf("Hello There");
    // printf("%s%f")
    float semesterGrade = data -> semesterPercentageGrade;
    
    if((((semesterGrade)) >= (float)90) && (((semesterGrade)) <= (float)100))
    {
        data -> letterGrade = 'A';
        
    }
    else if((((semesterGrade)) >= (float)85) && (((semesterGrade)) < (float)90))
    {
        data -> letterGrade = 'B';
        data -> isPlusGrade = true;
    }
    else if(((semesterGrade) >= (float)80) && ((semesterGrade) < (float)85))
    {
        data -> letterGrade = 'B';
    }
    else if(((semesterGrade) >= (float)75) && ((semesterGrade) < (float)80))
    {
        data -> letterGrade = 'C';
        data -> isPlusGrade = true;
    }
    else if(((semesterGrade) >= (float)70) && ((semesterGrade) < (float)75))
    {
        data -> letterGrade = 'C';
    }
    else if(((semesterGrade) >= (float)60) && ((semesterGrade) < (float)70))
    {
        data -> letterGrade = 'D';
    }
    else if(((semesterGrade) >= (float)0) && ((semesterGrade) < (float)60))
    {
        data -> letterGrade = 'F';
    }
    else
    {
        printf("\n");
        printf("Invalid Input");
        printf("\n");
    }

    // printDataValues(*data);
}


void setReportValuesToZero(struct fileReport * report)
{
    report -> numStudents = 0;
    report -> numAs = 0;
    report -> numBplus = 0;
    report -> numBs = 0;
    report -> numCplus = 0;
    report -> numCs = 0;
    report -> numDs = 0;
    report -> numFs = 0;
    report -> averageAssignmentGrade = 0;
    report -> averageMidtermGrade = 0;
    report -> averageFinalGrade = 0;

}


struct gradeAverages returnAverages(const struct fileData * data, int numLines)
{
    struct gradeAverages averages;
    
    float sumFinalGrades = 0;
    float sumMidtermGrades = 0;
    float sumAssignmentGrades = 0;

    averages.averageFinalGrade = 0;
    averages.averageMidtermGrade = 0;
    averages.averageAssignmentGrade = 0;

    // printInt("Sum Final grades: ", sumFinalGrades);


    for(int count = 0; count < numLines; count++)
    {
        sumFinalGrades = sumFinalGrades + data[count].finalGrade;
        sumMidtermGrades = sumMidtermGrades + data[count].midtermGrade;
        sumAssignmentGrades = sumAssignmentGrades + data[count].assignmentGrade;

        // printInt("Sum Final grades: ", sumFinalGrades);
    }

    averages.averageFinalGrade = ((float)(sumFinalGrades / numLines));
    averages.averageMidtermGrade = ((float)(sumMidtermGrades / numLines));
    averages.averageAssignmentGrade = ((float)(sumAssignmentGrades / numLines));

    // endline();
    // printInt("NumLines: ", numLines);
    // endline();
    // printFloat("Average final Grade: ", averages.averageFinalGrade);
    // endline();
    // printFloat("Average assignmet Grade: ", averages.averageAssignmentGrade);

    return averages;
}


struct fileReport getFileReport(const struct fileData * data, int numLines)
{
    struct fileReport report;
    struct gradeAverages averages;

    setReportValuesToZero(&report);
    
    report.numStudents = numLines;

    for(int count = 0; count < numLines; count++)
    {
        char tempLetterGrade;
        tempLetterGrade = ((data[count]).letterGrade);
        // printf("%s%c", "Pointer i guess: ", tempLetterGrade);
        // printf("\n");

        if(tempLetterGrade == 'A')
        {
            report.numAs++;
        }
        else if((tempLetterGrade == 'B') && (gradeIsplus(data[count]) == true))
        {
            report.numBplus++;
        }
        else if((tempLetterGrade == 'B') && (gradeIsplus(data[count]) == false))
        {
            report.numBs++;
        }
        else if((tempLetterGrade == 'C') && (gradeIsplus(data[count]) == true))
        {
            report.numCplus++;
        }
        else if((tempLetterGrade == 'C') && (gradeIsplus(data[count]) == false))
        {
            report.numCs++;
        }
        else if((tempLetterGrade == 'D'))
        {
            report.numDs++;
        }
        else if((tempLetterGrade == 'F'))
        {
            report.numFs++;
        }

        // printReportCli(report);
    }

    averages = returnAverages(data, numLines);

    report.averageAssignmentGrade = averages.averageAssignmentGrade;
    report.averageMidtermGrade = averages.averageMidtermGrade;
    report.averageFinalGrade = averages.averageFinalGrade;

    return report;
}


void deepCopyData(struct fileData * dataToModify, const struct fileData dataToCopy)
{
    (dataToModify) -> name = strdup(dataToCopy.name);
    (dataToModify) -> assignmentGrade = dataToCopy.assignmentGrade;
    (dataToModify) -> midtermGrade = dataToCopy.midtermGrade;
    (dataToModify) -> finalGrade = dataToCopy.finalGrade;
    (dataToModify) -> letterGrade = dataToCopy.letterGrade;
    (dataToModify) -> isPlusGrade = dataToCopy.isPlusGrade;
}


float getPercentageValue(float percentageContribution, float value)
{
    float number = (value * (percentageContribution / 100));
    return number;
}


void computeSemesterPercentageGrade(struct fileData * data)
{
    float midterm = (data -> midtermGrade);
    float assignment = (data -> assignmentGrade);
    float final = (data -> finalGrade);

    float midtermContribution = getPercentageValue(40, assignment);
    float finalContribution = getPercentageValue(30, midterm);
    float assignmentContribution = getPercentageValue(30, final);

    data -> semesterPercentageGrade = midtermContribution + finalContribution + assignmentContribution;

}


void printReportToFile(FILE * fptr, const struct fileReport report)
{
    fprintf(fptr, "\n");
    fprintInt(fptr, "Total students: ", report.numStudents);
    fprintf(fptr, "\n");
    fprintFloat(fptr, "Average Assignments Grade: ",report.averageAssignmentGrade);
    fprintFloat(fptr, "Average Midterm Exam Grade: ",report.averageMidtermGrade);
    fprintFloat(fptr, "Average final Exam Grade: ",report.averageFinalGrade);
    fprintf(fptr, "\n");
    fprintInt(fptr, "Number of A's: ", report.numAs);
    fprintInt(fptr, "Number of B+'s: ", report.numBplus);
    fprintInt(fptr, "Number of B's: ", report.numBs);
    fprintInt(fptr, "Number of C+'s: ", report.numCplus);
    fprintInt(fptr, "Number of C's: ", report.numCs);
    fprintInt(fptr, "Number of D's: ", report.numDs);
    fprintInt(fptr, "Number of F's: ", report.numFs);
}


void outputReportToFile(const char * fileName, const struct fileReport report, const struct fileData * allData, int numLines)
{
    FILE * fptr;
    if(fptr == NULL)
    {
        printf("The file is not opened. The program will now exit.");
    }
    else
    {
        fptr = fopen(fileName, "w");

        // Print all data values in file
        for(int count = 0; count < numLines; count++)
        {
            fprintDataValues(fptr, (allData[count]));
        }

        printReportToFile(fptr, report);

        fclose(fptr);
    }

}


