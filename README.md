# CS 210 Project Three – Corner Grocer

## Project Summary

The Corner Grocer project was created to help a grocery store analyze the items purchased by customers throughout the day. The store provides a text file containing the names of purchased produce items in chronological order. The purpose of the program is to count how frequently each item appears so that the store can use the information when deciding how to organize the produce department.

The C++ program provides a menu that allows the user to search for the frequency of a specific item, display the frequency of every item, display the information as a histogram, or exit the program. The program also creates a backup frequency file containing each item and its purchase count.

## What I Did Well

One area I did particularly well was organizing the program into separate functions instead of placing all of the code inside main(). This made the program easier to follow and allowed each function to perform a specific task.

I also used a map to associate each grocery item with its frequency. This was an effective way to store the information because each item could be used as a key and its purchase frequency could be stored as the corresponding value.

The menu gives the user several ways to view the same data, including searching for an individual item, viewing the complete numeric frequency list, and viewing a histogram. I also worked to keep the output easy for the user to understand.

## Areas I Could Improve

One improvement I could make would be to add stronger input validation. For example, the program could handle unexpected menu entries or differences in capitalization when a user searches for an item. Converting user input into a consistent format before searching could make the program more user-friendly.

I could also improve the program by adding more detailed error handling for file operations. If the input file cannot be opened, the program should clearly explain the problem and exit safely instead of attempting to continue.

As I gain more experience, I could also separate the program into additional class files, such as a header file and implementation file. This would make a larger version of the program easier to maintain and expand.

Challenges and How I Overcame Them

One of the more challenging parts of this project was working with files and making sure the program correctly read the grocery data before processing it. I also had to understand how to count repeated values and store those counts efficiently.

Another challenge was connecting all of the program requirements into one application. The program needed to read a file, count items, search for individual items, display all frequencies, create a histogram, write a backup file, and repeatedly display a menu until the user chose to exit.

I worked through these challenges by breaking the program into smaller sections and testing each part individually. Course examples, zyBooks activities, compiler error messages, and debugging were important resources throughout the project. I have learned that compiler errors are useful tools because they often identify exactly where I need to begin looking for a problem.

## Transferable Skills

Several skills from this project will transfer to future programming courses and software development projects. These include:

Reading data from and writing data to files
Using maps and other data structures to organize information
Using loops and conditional statements
Creating functions with specific responsibilities
Validating user input
Debugging compiler and runtime problems
Designing programs around user and business requirements
Writing readable and organized C++ code

The process of taking a list of requirements and converting them into a working program will be especially useful in future projects because most software development begins with understanding a problem and determining how the program should solve it.

## Maintainability, Readability, and Adaptability

I made the program maintainable and readable by separating major responsibilities into functions and using descriptive names for variables and functions. Comments can also help another programmer understand the purpose of important sections of the program.

Using a map to store the grocery items also makes the program adaptable because the program does not need to know in advance which produce items will appear in the input file. New grocery items can be processed automatically as they are encountered.

The menu-based design also makes the program easier to expand. Additional menu options or reports could be added later without completely redesigning the existing program.

## Reflection

This project helped me better understand how the individual C++ concepts covered throughout the course can work together in a complete application. Earlier activities often focused on one concept at a time, but the Corner Grocer project required me to combine file handling, functions, loops, conditionals, data structures, and user interaction.

Completing the project also gave me more experience working through errors and debugging rather than expecting a program to work correctly on the first attempt. This is a skill I know I will continue to use throughout the Computer Science program and in future software development work.
