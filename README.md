# OOP LAB 1

A simple CLI tool for transforming arrays/sequences to YAML strings and backwards.

This is first lab in MEPHI's OOP course. Specifications can be seen in specifications.pdf file.

## Requirements

build-essential (cmake, g++)

For generating documentation install: doxygen, latexmk.

## Installation

Clone this repository to your computer.
```bash
git clone ...
```

## Usage

### Build
Run build.sh file to complie and run programm.
```bash
./build.sh 2 # build and run
./build.sh 3 # build and run with valgring
```
```bash
./build.sh 6 # for doxygen assemblage. After completion doxygen files can be found in "docs" directory.
```

### Interface

After running build.sh follow menus' instructions. This tool has two operation mods: to YAML string (1) and from YAML string (2). Third option in menu is for changing function that is being called in menu options (more details in specification file).

## Tests
This lab work can be tested with google tests, which are in a "tests" folder.

To run tests you need to install: libgtest-dev, libgmock-dev.

Use build.sh to compile and run tests:
```bash
./build.sh 1 # build and run tests
```
To check coverage you can use build.sh with 4 (for task library) and 5 (for dialog functions):
```bash
./build.sh 4 # Generate coverage files for task directory
./build.sh 5 # Generate coverage files for dialog directory
```
After running build.sh you can find coverage files in "COVERAGES" directory.


## License

[MIT](https://choosealicense.com/licenses/mit/)