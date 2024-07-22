# Don't commit directly to the main branch!

## Cuscontest Repository

This repository contains the problems formulated for the different editions of `CUSCONTEST`.

### Writing A Problem

To write a problem just follow the same format specified in the folder `template`. The problem will be written using LaTex, There are some new commands that will be necessary to use in the structure of the document. If in doubt, consult the examples from previous editions. Inside this folder there is an example of a problem called `CombinacionDeLaCerradura`

Steps to write a problem:

1. **Create a new local branch from main branch**
2. Copy the problem folder inside template folder and rename it with the name of your problem.
3. Complete the documents:
    - Description (`description.tex`)
    - Editorial (`editorial.tex`)
    - Solution (`solution.cpp`)
4. If you need to include images, create an `images` folder within your problem.
5. Create the `in` folder, and inside put the inputs of examples of your problem and the other cases that will be used to judge.
6. Create the `out` folder and inside put all the test case results including the example ones.
7. **Once you have your problem open a pull request from youyr branch**. This should pass a two-person review.

#### Input format

The following formats of how the input will be read are recommended:

1. Read a number that represents the total number of test cases and then the input format of each test case.
2. Read the input format of each test case until there are no more cases.

This allows us to organize inputs and outputs in fewer files. Which also makes it easier to upload it to the online judge.

### Testing Using Overleaf

One way to test that your problem is written correctly is through Overleaf:

1. Open the [cuscontest-repository project](https://www.overleaf.com/9544566223xxngyxghkmby#e048af) on the overleaf
2. Add your problem folder and follow the format explained above
3. Add the folder name of your problem in the list in the `main.tex` file `line 77`
```
\def\folderlist{CombinacionDeLaCerradura}  % ADD HERE YOUR FOLDER PROBLEM USING COMMA SEPARATOR
```
4. Recompile the project and validate that everything is working!

