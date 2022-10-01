## Test-Driven-Development Authors (Part 1):
Driver - Aniruddh Balram
Navigator - Aneesh Chodisetty

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
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

