`timescale 1ns / 1ps

/* EXPECTED OUTPUT

dogru mu bilmiyom ama benimki boyle insallah dogrudur. tabloya bakinca ayni ama ok yildiz falan var tabloda anlamadim tam olarak ne zaman sey oluyor aman neyse

Time=0 | en=0 mode=x clinic=x clk=1 | ann=  x print=  x 
Time=5 | en=1 mode=1 clinic=0 clk=0 | ann=  5 print=  5 
Time=10 | en=1 mode=1 clinic=0 clk=1 | ann=  5 print=  5 
Time=15 | en=1 mode=1 clinic=1 clk=0 | ann= 10 print= 10 
Time=20 | en=1 mode=1 clinic=1 clk=1 | ann= 10 print= 10 
Time=25 | en=1 mode=0 clinic=0 clk=0 | ann=  5 print=  5 
Time=30 | en=1 mode=0 clinic=0 clk=1 | ann=  5 print=  6 
Time=35 | en=1 mode=0 clinic=0 clk=0 | ann=  5 print=  6 
Time=40 | en=1 mode=0 clinic=0 clk=1 | ann=  5 print=  7 
Time=45 | en=1 mode=0 clinic=1 clk=0 | ann= 10 print= 10 
Time=50 | en=1 mode=0 clinic=1 clk=1 | ann= 10 print= 11 
Time=55 | en=1 mode=1 clinic=1 clk=0 | ann= 10 print= 11 
Time=60 | en=1 mode=1 clinic=1 clk=1 | ann= 11 print= 11 
Time=65 | en=1 mode=1 clinic=1 clk=0 | ann= 11 print= 11 
Time=70 | en=1 mode=1 clinic=1 clk=1 | ann= 11 print= 11 
Time=75 | en=1 mode=1 clinic=0 clk=0 | ann=  5 print=  7 
Time=80 | en=1 mode=1 clinic=0 clk=1 | ann=  6 print=  7 
Time=85 | en=1 mode=1 clinic=0 clk=0 | ann=  6 print=  7 
Time=90 | en=1 mode=1 clinic=0 clk=1 | ann=  7 print=  7 
Time=95 | en=0 mode=1 clinic=0 clk=0 | ann=  7 print=  7 
Time=100 | en=0 mode=1 clinic=0 clk=1 | ann=  7 print=  7 

*/


module testbench_numerator(
    );
   reg clinic;
	reg mode;
	reg en;
	reg clk;
	wire [7:0] ann;
	wire [7:0] print;

	// Instantiate the Unit Under Test (UUT)
	Numerator uut(clinic, mode, en, clk, ann, print);
	
	// At 5, 15, 25, .. clk will change 0->1
	// At 10, 20, 30, .. clk will change 1->0
	initial clk = 1;
	always #5 clk = ~clk;
	

	initial begin
		// set monitor to inputs and outputs.
		$monitor("Time=%.2d | en=%b mode=%b clinic=%b clk=%b | ann=%d print=%d ", $time, en, mode, clinic, clk, ann, print);
		
        en = 0;
        #5
        
        en = 1;    
        mode = 1;  
        clinic = 0;
        #10;       

        en = 1;    
        mode = 1;  
        clinic = 1;
        #10;       

        en = 1;    
        mode = 0;  
        clinic = 0;
        #10;

        en = 1;
        mode = 0;
        clinic = 0;
        #10;

        en = 1;
        mode = 0;
        clinic = 1;
        #10;

        en = 1;
        mode = 1;
        clinic = 1;
        #10;

        en = 1;
        mode = 1;
        clinic = 1;
        #10;

        en = 1;
        mode = 1;
        clinic = 0;
        #10;

        en = 1;
        mode = 1;
        clinic = 0;
        #10;
        
        en = 0;
        #10;
        
        
		$finish;
	end //initial

endmodule
