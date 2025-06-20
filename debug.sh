echo off
cd engine
make -f linux.mk release
cd ..

cd testbed
make -f linux.mk release
make -f linux.mk run
cd ..
