# simple shell script to automate the building process

# go to build directory
cd build

# configure the project with cmake
cmake ../src

# Build
make

# Run the exe
../bin/Editor

