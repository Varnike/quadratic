# Quadratic equation solver
Solves quadratic or linear equation.
##### Table of contents:
- [Compilation](#compilation)
- [Run](#run)
- [Parameters](#parameters)
- [Usage](#usage)
- [Example of use](#example)
## Compilation
Download files via [git]("https://git-scm.com/"):
```sh
git clone https://github.com/Varnike/quadratic.git
```
After downloading files run(in same directory):
```sh
cd quadratic/
make
```
## Run
To start programm, go to ~/quadraric directory and type in console:
```sh
./quadratic [parametr]
```
#### Parameters:
- [-h] - help
- [-t] - run unittest
 
## Usage
If you didn't choose any option, program will ask you to enter three coefficients of quadratic equation. Enter these numbers. Program will print number of solutions and roots of equation.

## Example of use
After compiling and start program with no parametes you will see:
```sh
Enter coefficients a, b, c: 
```
Suppose you entered three coefficients: a = 12, b = 89, c = -321.1:
```sh
Enter coefficients a, b, c: 
12 89 -321.1
```
After you pressed enter, programm will print the solution:
```sh
Solutions: -10.073085, 2.656419
```
