#!/bin/bash

git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch

chmod +x build.sh
mkdir /home/runner/.apt
mkdir /home/runner/.apt/usr
mkdir /home/runner/.apt/usr/bin
ln -s /home/runner/c-programming-course/build.sh /home/runner/.apt/usr/bin/build