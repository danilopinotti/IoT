#!/bin/bash
sudo apt-get install git -y

git config --global user.name "Danilo Pinotti"
git config --global user.email danilopinotti@hotmail.com

mkdir ~/IoT
cd ~/IoT

git clone https://danilopinotti@bitbucket.org/danilopinotti/iot.git ~/IoT