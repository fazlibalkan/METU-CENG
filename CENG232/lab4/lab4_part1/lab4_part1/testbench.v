`timescale 1ns / 1ps

// Time= 0 | mode=1 index=xxx number=xxxxxxxx clk=1 | result=00000000 
// Time= 5 | mode=1 index=xxx number=xxxxxxxx clk=0 | result=00000000 
// Time= 6 | mode=0 index=000 number=01011100 clk=0 | result=00000000 
// Time=10 | mode=0 index=000 number=01011100 clk=1 | result=00000000 
// Time=11 | mode=1 index=000 number=01011100 clk=1 | result=01011100 
// Time=15 | mode=1 index=000 number=01011100 clk=0 | result=01011100 
// Time=16 | mode=0 index=001 number=01011100 clk=0 | result=01011100 
// Time=17 | mode=1 index=001 number=01011100 clk=0 | result=00000000 
// Time=18 | mode=0 index=010 number=01011100 clk=0 | result=00000000 
// Time=20 | mode=0 index=010 number=01011100 clk=1 | result=00000000 
// Time=21 | mode=1 index=001 number=01011100 clk=1 | result=00000000 
// Time=25 | mode=1 index=010 number=01011100 clk=0 | result=11110110

module testbench();
    reg mode;
    reg [2:0] index;
    reg [7:0] number;
    reg CLK;
    wire [7:0] result;

    EncodedMemory uut(mode, index, number, CLK, result);

    initial CLK=1;
    always #5 CLK = ~CLK;
    
    initial begin
        $monitor("Time=%2d | mode=%b index=%b number=%b clk=%b | result=%b ", $time, mode, index, number, CLK, result);

        mode=1;
        #6

        mode=0;
        index=3'b000;
        number=8'b01011100;
        #5

        mode=1;
        #5

        mode=0;
        index=3'b001;
        number=8'b01011100;
        #1

        mode=1;
        #1

        mode=0;
        index=3'b010;
        number=8'b01011100;
        #3

        index=3'b001;
        mode=1;
        #4

        index=3'b010;
        mode=1;
		  #1

        $finish;

    end



endmodule
