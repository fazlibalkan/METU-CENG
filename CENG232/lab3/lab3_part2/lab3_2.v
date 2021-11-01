`timescale 1ns / 1ps
module QueueCounter(
	input [7:0] llmt,
	input [7:0] ulmt,
	input en,
	input mode, // 1:delete, 0:insert
	input clk,
	output reg [7:0] head,
	output reg [7:0] tail,
	output reg empty,
	output reg full);
	
	//you may write your code here

	initial
	begin
		head = llmt;
		tail = llmt;
		empty = 1'd1;
		full = 1'd0;
	end

	//you may write your code here
	
	always@(posedge clk)
	begin
		if (en == 1)
		begin
			//mode 0
			if (mode == 0)
			begin
				empty = 0;
				if (full != 1)
				begin 
					if ((tail > head) && (tail - head == ulmt - llmt))
						full = 1;
					else if ((head > tail) && (head - tail == 1))
						full = 1;
					if (tail == ulmt)
						tail = llmt;
					else
						tail = tail + 1;
				end
			end
			//mode 1
			else if (mode == 1)
			begin
				full = 0;
				if (empty != 1)
				begin 
					if (head == ulmt)
						head = llmt;
					else
						head = head + 1;
					if (head == tail)
						empty = 1;
				end
			end
		end
	end
	
	

endmodule


module Numerator(
	input clinic, 
	input mode, 
	input en, 
	input clk,
	output [7:0] ann,
	output [7:0] print);

	//write your code here
	
	wire [7:0] head0, head1, tail0, tail1;
	
	assign ann = (clinic ? head1 : head0);
	assign print = (clinic ? tail1 : tail0);
	
	QueueCounter room0(8'd5, 8'd9, en&(~clinic), mode, clk, head0, tail0);
	QueueCounter room1(8'd10, 8'd14, en&clinic, mode, clk, head1, tail1);
	
	always@(en or mode or clinic)
	begin
	end

endmodule
