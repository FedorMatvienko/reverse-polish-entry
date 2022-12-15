BUILD=$PWD/.build
rm -rf $BUILD
mkdir -p $BUILD
cd $BUILD
cmake ..
cmake --build .
./main