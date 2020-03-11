#!/usr/bin/env bash

sudo apt-get update --yes
sudo apt-get install --yes cmake
sudo apt-get install --yes libgtest-dev
sudo apt-get install --yes valgrind
sudo apt-get install --yes cppcheck
sudo apt-get install --yes curl
export CODECOV_TOKEN="5c299964-5a65-411d-bbfe-e7ac089395aa" # :)
sudo cmake /usr/src/gtest/CMakeLists.txt
(cd /usr/src/gtest && sudo make && sudo cp *.a /usr/lib)
