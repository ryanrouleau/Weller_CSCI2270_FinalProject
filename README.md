# Weller_CSCI2270_FinalProject
Description:

  I have written a console input/output game called "The Road" (name after Cormac McCarthy's apoctalyptic novel) which is an extension of Assignments 10/11. 

  The purpose of the game is to try to reach a randomized "end" city during the zombie apocalypse from a randomized starting city. You "win" as long as you manage to make it, but it's a bonus if you make it by traversing less than a certain amount of distance. The catch is this: each time you try to travel to a new city, there is a 50% chance that something may go wrong which blocks that road. Additionally, the provided "available path" is not always the fastest. The game requires you to use the menu strategically to optimize your options for navigating between cities.

  The application takes an input file "cities.txt" which is similar to the "bestCities.txt" file used in Assignment 11, but with some modifcations, and builds a graph of cities from it. Some of the cities' edges are initialized to -1, meaning there is no safe path between them initially. The game gives you a long list of options in the form of a menu, to help you navigate the cities. The primary data structure used in the game is a graph, which is modified by randomly generated events (i.e. some "roads" being blocked) and also the use of queues and pointers to keep track of the path traveled. 
  
  
How to Play:

  The program will generate a random starting city and ending city for you try to navigate between. It also provides you with a menu to help. The menu allows you to print the current city you're in and the ending city you are trying to get to. It will also print out which cities you've been to and the distance you've traveled. These are mainly for your records. It will also print out an available path for you to the final city (this is not necessarily the shortest, distance-wise though, and will change depending on your current city). You may see which adjacent, not-blocked cities are available to travel to as well, to any city. This may help you pick a shorter path. Finally, the menu allows you to trvel to the next city, which may generate a problem which causes the path to be blocked. If this happens, then you will need to try a new path. 


How to Run from Terminal:

  I highly recommend to run this through a linux environment or a downloaded terminal that simulates a linux environment, like GitBash.
  
  Linux: Download the files cities.txt, Setup.h, Setup.cpp, and TheRoad.cpp into a folder. Open the terminal, and change directory "cd directoryName" until within the folder where the files are saved. Use "ls" to see which filenames are in the current directory. Once in the proper folder, type "g++ Setup.h Setup.cpp TheRoad.cpp -o TheRoad" to create an executable version of the game. Then, to play, type "./TheRoad" and it will open in the terminal.


Dependencies: 
  No dependencies.


System Requirements:

  As stated above, considering this is a console application, it is easiest executed through a Linux environment. For Windows or mac users, I suggest downloading Git/Git Bash and then following the instructions above to compile and run the program.


Group Members:
  N/A
  
  
Contributors:
  N/A
  
  
Open Issues:
  No current open issues or bugs.
