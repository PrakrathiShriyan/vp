#include "systemc.h"
#include "t_ff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
    // Clock
    sc_clock clk("TestClock", 10, SC_NS, 0.5, 1, SC_NS, false);

    // Signals
    sc_signal<bool> t, q_t, qbar_t;

    // T flip-flop
    t_ff t_ff("t_ff");
    t_ff.clk(clk);
    t_ff.t(t);
    t_ff.q(q_t);
    t_ff.qbar(qbar_t);

    // Driver for T flip-flop
    driver drive_t("driver");
    drive_t.t(t);
    drive_t.clk(clk);

    // Monitor for T flip-flop
    monitor mon_t("monitor");
    mon_t.t(t);
    mon_t.clk(clk);
    mon_t.q(q_t);
    mon_t.qbar(qbar_t);

    // Trace file
    sc_trace_file *Tf;
    Tf = sc_create_vcd_trace_file("traces");
    sc_trace(Tf, t, "T");
    sc_trace(Tf, clk, "CLK");
    sc_trace(Tf, q_t, "Q_T");
    sc_trace(Tf, qbar_t, "QBAR_T");

    // Simulation
    sc_start(50, SC_NS);

    // Closing trace file
    sc_close_vcd_trace_file(Tf);

    return 0;
}

