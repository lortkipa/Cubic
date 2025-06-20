echo off
cd engine
make -f linux.mk debug
cd ..

cd testbed
make -f linux.mk debug
make -f linux.mk run
cd ..
