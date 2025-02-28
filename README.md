# Two-Dice-Game
This program simulates the rolling of two dice and tracks the frequency of the sums that appear.
The simulation is designed to roll the two dice 36,000 times, and each roll generates a sum ranging from 2 to 12. The goal of the program is to calculate the occurrence of each possible sum, display the results in a tabular format, and determine whether the player wins or loses based on the frequency of rolling a (6, 6).

Program Features:

Simulating Dice Rolls:
The program will simulate the rolling of two dice using the rand() function in C++.
For each die, the rand() function will generate a random integer value between 1 and 6, representing the outcome of a dice roll.
Tracking Sums:
After each roll, the sum of the two dice will be calculated, which can vary between 2 and 12.
A 2D array will be used to keep track of how often each sum occurs during the 36,000 rolls.
Output:
The program will print the tally of the sums in a tabular format. The table will display each possible sum (from 2 to 12) along with the frequency of how many times that sum appeared.
Player Win Condition:
The player wins if the occurrence of the sum (6,6) (which sums to 12) is greater than 1,000 times.
If the sum of (6,6) appears more than 1,000 times, the player wins. Otherwise, the player loses.
Rolling Simulation (36,000 times):
The dice will be rolled 36,000 times to ensure a sufficiently large sample size for accurate frequency tracking.
SplashKit Integration (Extended Task):
Once the logic is implemented, the game will be integrated into a SplashKit graphical window.
The program will display the result of each dice roll and the final outcome (win/lose) in a user-friendly graphical format.
Program Structure:

Dice Roll Simulation: Uses rand() to generate random numbers between 1 and 6, then computes the sum of both dice.
Frequency Calculation: A 2D array will be used where each index corresponds to a particular sum (e.g., index 0 for sum = 2, index 11 for sum = 12).
Display Results: After 36,000 rolls, the program will display a tabular view showing how many times each sum (from 2 to 12) was rolled.
Win/Loss Condition: The program will check if the sum (6, 6) occurred more than 1,000 times and print whether the player wins or loses.
SplashKit Integration: The result table and the win/lose outcome will be displayed in a graphical window using SplashKit, allowing for an enhanced user interface experience.
