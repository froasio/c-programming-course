#!/bin/bash

echo "Setting enviroment..."

if [ -f ./misc/replit/.envs ]; then
    export $(cat ./misc/replit/.envs  | grep -v '#' | awk '/=/ {print $1}')
		echo ${REPLIT_PATH}
fi

git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch

chmod +x ${REPLIT_PATH}/c-programming-course/misc/replit/build.sh
chmod +x ${REPLIT_PATH}/c-programming-course/misc/replit/template.sh
mkdir -p ${REPLIT_PATH}/.apt
mkdir -p ${REPLIT_PATH}/.apt/usr
mkdir -p ${REPLIT_PATH}/.apt/usr/bin
ln -sf ${REPLIT_PATH}/c-programming-course/misc/replit/build.sh ${REPLIT_PATH}/.apt/usr/bin/build
ln -sf ${REPLIT_PATH}/c-programming-course/misc/replit/template.sh ${REPLIT_PATH}/.apt/usr/bin/template

find . -not -path '*/\.*' -type f -exec sh -c "file -i '{}' | grep -q 'charset=binary'" \; -print | xargs rm -f

echo "Done!"

