#!/bin/bash

echo "Setting enviroment..."

export LOCAL_ROOT_PATH=/home/runner

git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch

chmod +x ${LOCAL_ROOT_PATH}/c-programming-course/misc/replit/build.sh
chmod +x ${LOCAL_ROOT_PATH}/c-programming-course/misc/replit/template.sh
mkdir -p ${LOCAL_ROOT_PATH}/.apt
mkdir -p ${LOCAL_ROOT_PATH}/.apt/usr
mkdir -p ${LOCAL_ROOT_PATH}/.apt/usr/bin
ln -sf ${LOCAL_ROOT_PATH}/c-programming-course/misc/replit/build.sh ${LOCAL_ROOT_PATH}/.apt/usr/bin/build
ln -sf ${LOCAL_ROOT_PATH}/c-programming-course/misc/replit/template.sh ${LOCAL_ROOT_PATH}/.apt/usr/bin/template

find . -not -path '*/\.*' -type f -exec sh -c "file -i '{}' | grep -q 'charset=binary'" \; -print | xargs rm -f

echo "Done!"

