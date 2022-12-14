## Test-Driven-Development Authors (Part 1):
Driver - Aniruddh Balram
Navigator - Aneesh Chodisetty
## Test-Driven-Development Authors (Part 2):
Driver - Mayank Sharma
Navigator - Koundinya Vinnakota

## Standard install via command-line
```
git clone https://github.com/aniruddhbalram97/PID-Controller
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cd <path to repository>
mkdir build
cd build
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Class diagram followed for the PID controller
![PID Control](/UML%20Diagram/TDD.png)