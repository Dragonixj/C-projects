# C-projects

This repo contains some programmes I will be writing along my Self learning Process
of the C programming language.
A little desription will be provided for each program so you could
try to do it on your own as practice or reference.

## Cloning

- To clone this repo for reference or ideas for your own pragrammes;

```
git clone https://github.com/Dragonixj/C-projects
cd C-projects/
```

- To run any of the programmes
  - Navigate into the sub directory
  - and compile the code
  - And then run the file

```
cd Beginner_Level/ || cd Intermediate_level

gcc file.c -o file

./file
```

---

## Projects

<details>
<summary>Beginner_Level</summary>

- **calculator.c**

  - This is a simple calculator programme
    that performs simple calculations
  - It performs 6 basic operations
    - Addition
    - subtraction
    - Multiplication
    - Division
    - Power
    - Modulo
  - It starts by asking the user what operation they want to perform
    and the integers they want to perform the operation on and prints the output

- **circumference-area.c**

  - This is a programme that receives arguments (radius) and gives an output based on if the user wants to calculate the Circumference or radius of a circle

- **numrange.c**

  - This programme outputs the range of a given integer between 1 and 500
  - It then prompts the user if they want to continue with the program

- **Psqr.c**

  - This is a programme that determines if an inputed value is perfect square
    -A perfect square is a number that can be expressed as the product of an integer by itself or as the second exponent of an integer.

- **Palindrome.c**
  - This is a programme that checks if a string entered by the user is a palindrome.
  - A Palindrome is simply a word, that reads the same backward or forward. - Level, mom, rotator, racecar.
    </details>
  <details>
  <summary>Intermediate_level</summary>
- multable.c

  - A simple Multiplication table printer
  - It asks a user for the # they want a table of
  - It then asks for a range
  - It creates a file table.txt with the crafted table stored
  - And prints out the content of the .txt file

- ATM - A simple ATM - Inspo from itsourcecode.com - Still a work in progress, but runnable
:warning::warning:
</details>

---

## Contributing

### Fork this repository.

- Fork this repo by clicking on the fork button on the top of this page.
  This will create a copy of this repository in your account.

### Clone this repository

- Now clone the forked repository to your machine.
  Go to your GitHub account, open the forked repository, click on the code button and then click to copy to clipboard.

Open a terminal and run the command

```
git clone "url you just copied"
```

Don't include the quotation marks.
For example

```
git clone https://github.com/your-name/C-projects.git
```

where **your-name** is you.

### Create a new branch

Change to the repo directory on your computer (if you aren't already there):
`cd C-projects
   `
now create a new branch using the `git switch` command

```
git switch -c your-branch-name
```

Example:
`git switch -c apple
   `
Now make necessary changes

- Create new programmes
- Edit some code

Now commit those changes and push

```
git add .
git commit -m "program made"
git push -u origin your-branch-name
```

replace `your-branch-name` with the branch you created from the example `apple`.

<details>
<summary>If you face issues pushing</summary>
check <a href = "https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account">Github Docs</a> on generating and configuring an ssh Key for your account.

</details>
