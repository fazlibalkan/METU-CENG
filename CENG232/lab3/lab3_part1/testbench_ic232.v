`timescale 1ns / 1ps
module testbench_ic232;

	// Inputs
	reg A0;
	reg A1;
	reg A2;
	reg clk;

	// Outputs
	wire Q0;
	wire Q1;
	wire Z;

	// Instantiate the Unit Under Test (UUT)
	ic232 uut (
		.A0(A0), 
		.A1(A1),
		.A2(A2),
		.clk(clk),
		.Q0(Q0),
		.Q1(Q1),
		.Z(Z)
	);

	// At 5, 15, 25, .. clk will change 0->1
	// At 10, 20, 30, .. clk will change 1->0
   initial clk = 0;
	always #5 clk = ~clk; 

	initial begin
		// set monitor to inputs and outputs.
		$monitor("Time=%.2d | A0=%b A1=%b A2=%b | Q0=%b Q1=%b Z=%b", $time, A0, A1, A2, Q0, Q1, Z);
      
		#1; //(1ns)Check Initial Q0=0, Q1=0, Z=1, values (made q0=0, q1=0 initially)
		if (!((Q0 == 1'b0)&&(Q1 == 1'b0)&&(Z==1'b1))) $display("Initial value of Q0 or Q1 or Z is wrong");
		else $display("Successful");
		
		#1; //(2ns) Set A0=0, A1=0, A2=0 (1.)
		A0 = 1'b0; A1 = 1'b0; A2 = 1'b0;
		
		#5; //(7ns) Wait for clock edge
		if (!((Q0 == 1'b1)&&(Q1 == 1'b0)&&(Z==1'b0))) $display("Values after Q0prev=0 Q1prev=0 Z=1 is wrong");
		else $display("Successful");
		
		#10; //(17ns) Wait for clock edge 
		if (!((Q0 == 1'b1)&&(Q1 == 1'b0)&&(Z==1'b0))) $display("Values after Q0prev=1 Q1prev=0 Z=0 is wrong");
		else $display("Successful");
		
		#1; //(18ns) Set A0=0, A1=0, A2=1 (2.)
		A0 = 1'b0; A1 = 1'b0; A2 = 1'b1;
		
		#9; //(27ns) Wait for clock edge 
		if (!((Q0 == 1'b0)&&(Q1 == 1'b1)&&(Z==1'b0))) $display("Values after Q0prev=1 Q1prev=0 Z=0 is wrong");
		else $display("Successful");
		
		#10; //(37ns) Wait for clock edge
		if (!((Q0 == 1'b1)&&(Q1 == 1'b0)&&(Z==1'b0))) $display("Values after Q0prev=0 Q1prev=1 Z=0 is wrong");
		else $display("Successful");
		
		#10; //(47ns) Wait for clock edge
		if (!((Q0 == 1'b0)&&(Q1 == 1'b1)&&(Z==1'b0))) $display("Values after Q0prev=1 Q1prev=0 Z=0 is wrong");
		else $display("Successful");
		
		#1; //(48ns) Set A0=0, A1=1, A2=0 (3.)
		A0 = 1'b0; A1 = 1'b1; A2 = 1'b0;
		
		#9; //(57ns) Wait for clock edge
		if (!((Q0 == 1'b0)&&(Q1 == 1'b1)&&(Z==1'b0))) $display("Values after Q0prev=0 Q1prev=1 Z=0 is wrong");
		else $display("Successful");
		
		#10; //(67ns) Wait for clock edge
		if (!((Q0 == 1'b0)&&(Q1 == 1'b1)&&(Z==1'b0))) $display("Values after Q0prev=0 Q1prev=1 Z=0 is wrong");
		else $display("Successful");
		
		#1; //(68ns) Set A0=0, A1=1, A2=1 (4.)
		A0 = 1'b0; A1 = 1'b1; A2 = 1'b1;
		
		#9; //(77ns) Wait for clock edge 
		if (!((Q0 == 1'b0)&&(Q1 == 1'b0)&&(Z==1'b1))) $display("Values after Q0prev=0 Q1prev=1 Z=0 is wrong");
		else $display("Successful");
		
		#10; //(87ns) Wait for clock edge
		if (!((Q0 == 1'b0)&&(Q1 == 1'b1)&&(Z==1'b0))) $display("Values after Q0prev=0 Q1prev=0 Z=1 is wrong");
		else $display("Successful");
		
		#1; //(98ns) Set A0=1, A1=0, A2=0 (5.)
		A0 = 1'b1; A1 = 1'b0; A2 = 1'b0;
		
		#9; //(107ns) Wait for clock edge 
		if (!((Q0 == 1'b1)&&(Q1 == 1'b1)&&(Z==1'b1))) $display("Values after Q0prev=0 Q1prev=1 Z=0 is wrong");
		else $display("Successful");
		
		#10; //(117ns) Wait for clock edge
		if (!((Q0 == 1'b0)&&(Q1 == 1'b1)&&(Z==1'b0))) $display("Values after Q0prev=1 Q1prev=1 Z=1 is wrong");
		else $display("Successful");
		
		#10; //(127ns) Wait for clock edge
		if (!((Q0 == 1'b1)&&(Q1 == 1'b1)&&(Z==1'b1))) $display("Values after Q0prev=0 Q1prev=1 Z=0 is wrong");
		else $display("Successful");
		
		#1; //(128ns) Set A0=1, A1=0, A2=1 (6.)
		A0 = 1'b1; A1 = 1'b0; A2 = 1'b1;
		
		#9; //(137ns) Wait for clock edge 
		if (!((Q0 == 1'b0)&&(Q1 == 1'b0)&&(Z==1'b1))) $display("Values after Q0prev=1 Q1prev=1 Z=1 is wrong");
		else $display("Successful");
		
		#10; //(147ns) Wait for clock edge
		if (!((Q0 == 1'b1)&&(Q1 == 1'b0)&&(Z==1'b0))) $display("Values after Q0prev=0 Q1prev=0 Z=1 is wrong");
		else $display("Successful");
		
		#1; //(148ns) Set A0=1, A1=1, A2=0 (7.)
		A0 = 1'b1; A1 = 1'b1; A2 = 1'b0;
		
		#9; //(157ns) Wait for clock edge 
		if (!((Q0 == 1'b0)&&(Q1 == 1'b0)&&(Z==1'b1))) $display("Values after Q0prev=1 Q1prev=0 Z=0 is wrong");
		else $display("Successful");
		
		#10; //(167ns) Wait for clock edge
		if (!((Q0 == 1'b0)&&(Q1 == 1'b0)&&(Z==1'b1))) $display("Values after Q0prev=0 Q1prev=0 Z=1 is wrong");
		else $display("Successful");
		
		#1; //(168ns) Set A0=1, A1=1, A2=1 (8.)
		A0 = 1'b1; A1 = 1'b1; A2 = 1'b1;
		
		#9; //(177ns) Wait for clock edge 
		if (!((Q0 == 1'b0)&&(Q1 == 1'b1)&&(Z==1'b0))) $display("Values after Q0prev=0 Q1prev=0 Z=1 is wrong");
		else $display("Successful");
		
		#10; //(187ns) Wait for clock edge
		if (!((Q0 == 1'b0)&&(Q1 == 1'b0)&&(Z==1'b1))) $display("Values after Q0prev=0 Q1prev=0 Z=1 is wrong");
		else $display("Successful");
		
		#5;
		$finish;

	end
      
endmodule
