# Main Design Idea 

The main design lens is seeing it as an upgrade to the assignment3 program, hence teh source code as been copied into the assignment4.c file.

# General Observations
1.) Creation of other functions to handle things like input validation <br>
2.) Use of a assert to test independent functions <br>

## Functionalities Overview
- Conversion from any unit to another including the case of unit a to unit a
- String validion to get input for both unit to convert from and unit to convert to

# Flow Control Ideas
- The Main funion will be responsible for the general flow control.

## Global Variables
- Relationships between different units such as kmToMilesValue are stored as global variables.

## Main Function
- Gets and validaes user input for temperature and distance conversion.
- Gets the unit to convert to and unit to convert from
- Validates these inputs using necessary functions.
- Decides based on user input to call distance or temerature conversion menus.
- Contains main while loop to re - display until exist.

## Other Functions
### - temperatureConversion()
### - distanceConversion()
### - validateValue()
### - validateUnitInput()

# Things to watch out for
- Ensure the valid input range is still the same

# Changes to assignment3.c
- Make constant variables global to increase ease of access from other function </br>