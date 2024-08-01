# Don't commit directly to the main branch!

## Cuscontest Repository

This repository contains the problems formulated for the different editions of `CUSCONTEST`.

To write a problem, just follow the same format specified in the folder `template`. The problem will be written using LaTeX. There are some new commands that will be necessary to use in the structure of the document. When in doubt, consult the examples from previous editions. Inside this folder, there is an example of a problem called `CombinacionDeLaCerradura`

## How To Write A Problem?

Steps to write a problem:

1. **Create a new local branch from the main branch**
2. Copy the problem folder inside the `template` folder and rename it with the name of your problem.
3. Complete the documents:
    - Description (`description.tex`)
    - Editorial (`editorial.tex`)
    - Solution (`solution.cpp`)
4. If you need to include images, create an `images` folder within your problem folder.
5. Create the `in` folder, and inside, put the inputs of examples of your problem and the other cases that will be used to judge.
6. Create the `out` folder and inside, put all the test case results, including the example ones.
7. **Once you have your problem, open a pull request from your branch**. This should pass a two-person review.

### Input format

The following formats for reading the input are recommended:

1. Read a number that represents the total number of test cases, and then the input format of each test case.
2. Read the input format of each test case until there are no more cases.

This allows us to organize inputs and outputs in fewer files. Which also makes it easier to upload them to the online judge.

## How To Test My Problem?

One way to test that your problem is written correctly is through Overleaf:

1. Open the [cuscontest-repository project](https://www.overleaf.com/9544566223xxngyxghkmby#e048af) on Overleaf.
2. Add your problem folder inside the `template folder` in the project and follow the format explained above. You can use the folder or files upload feature on Overleaf (sometimes it happens that this does not upload the `out` folder; in this case, create the folder manually usign Overleaf's feature and upload your test output files).
3. Add the folder name of your problem to the list in the `main.tex` file `line 77`
```
\def\folderlist{CombinacionDeLaCerradura}  % ADD HERE YOUR FOLDER PROBLEM USING COMMA SEPARATOR
```
4. Recompile the project and validate that everything is working!

