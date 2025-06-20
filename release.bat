@echo off
cd engine
make -f windows.mk debug
cd ..

cd testbed
make -f windows.mk release
make -f windows.mk run
cd ..
