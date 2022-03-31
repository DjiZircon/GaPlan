#!bin/bash

cd build;
cmake ..;
make;
cd ..;
cd GaPlan;
./ga_tsp_test