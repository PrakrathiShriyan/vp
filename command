g++ -I/usr/local/systemc-2.3.3/include -L/usr/local/systemc-2.3.3/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o hello main.cpp -lsystemc -lm

./hello



to open gtkwave:
 gtkwave traces.vcd

