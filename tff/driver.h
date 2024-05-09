// driver_t.h
#include "systemc.h"

SC_MODULE(driver)
{
    sc_out<bool> t;
    sc_in<bool> clk;

    void inputs()
    {
        for (int i = 0; i < 4; i++)
        {
            // Provide different inputs for testing
            t.write(i % 2 == 0); // Alternating T between true and false

            wait();

            sc_time t3 = sc_time_stamp();
            cout << "Value of t3 " << t3.to_string() << endl;
        }
    }

    SC_CTOR(driver)
    {
        SC_THREAD(inputs);
        sensitive << clk.pos();
    }
};

