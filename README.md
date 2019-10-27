----------
Introduction
----------
This program is used to enter a list of students and their preference for other students. It takes a csv input of the students and their preferences and will output a csv with their respective groups.

--------
Running
--------
To run this program, enter a file in the corresponding format:
- CSV one line for each students
- First column, student first name
- Second column, student middle name
- Third column, student family name
- Fourth column, student unique id numbered
- Fifth to tenth column, the 6 student ids of their preferences in any order

For examples of this see the setup folder of the root. It also contains a very simple python code to create a new list of people.

----------
TODO List:
----------
- Fix program crashing on certain  strange numbered groups (e.g. 7)
- Fix wrong output for group of 1