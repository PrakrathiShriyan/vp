// monitor_t.h
#include "systemc.h"

SC_MODULE(monitor)
{
    sc_in<bool> t;
    sc_in<bool> clk;
    sc_in<bool> q;
    sc_in<bool> qbar;

    void mon()
    {
        cout << "Inputs: T=" << t << " CLK=" << clk
             << " Output: Q=" << q << " Qb=" << qbar << endl;
    }

    SC_CTOR(monitor)
    {
        SC_METHOD(mon);
        sensitive << clk.pos();
    }
};

