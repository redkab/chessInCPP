git clone https://github.com/redkab/chessInCPP.git
cd chessInCPP

sudo apt update
sudo apt install build-essential cmake libsfml-dev

mkdir build
cd build

cmake ..
cmake --build .

./chess
