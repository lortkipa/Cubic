echo off
cd engine
bear -- make -f linux.mk debug
cd ..

cd testbed
bear -- make -f linux.mk debug
cd ..
