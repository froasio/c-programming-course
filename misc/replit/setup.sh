#!/bin/bash

echo "Setting enviroment..."
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch

chmod +x /home/runner/c-programming-course/misc/replit/build.sh
chmod +x /home/runner/c-programming-course/misc/replit/template.sh
mkdir -p /home/runner/.apt
mkdir -p /home/runner/.apt/usr
mkdir -p /home/runner/.apt/usr/bin
ln -sf /home/runner/c-programming-course/misc/replit/build.sh /home/runner/.apt/usr/bin/build
ln -sf /home/runner/c-programming-course/misc/replit/template.sh /home/runner/.apt/usr/bin/template

find . -not -path '*/\.*' -type f -exec sh -c "file -i '{}' | grep -q 'charset=binary'" \; -print | xargs rm -f

echo "Done!"

