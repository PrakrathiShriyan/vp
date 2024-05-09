// t_ff.h
#include "systemc.h"

SC_MODULE(t_ff)
{
    sc_in<bool> clk;
    sc_in<bool> t;
    sc_out<bool> q;
    sc_out<bool> qbar;

    bool q_prev;

    void compute_result()
    {
        if (t.read())
            q_prev = !q_prev;

        q.write(q_prev);
        qbar.write(!q_prev);
    }

    SC_CTOR(t_ff)
    {
        q_prev = false; // Initial state
        SC_METHOD(compute_result);
        sensitive << clk.pos();
    }
};

