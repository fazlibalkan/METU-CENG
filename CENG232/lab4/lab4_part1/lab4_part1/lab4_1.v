`timescale 1ns / 1ps

module ROM (
input [2:0] addr, 
output reg [7:0] dataOut);

	// write your code below
	initial
	begin
		dataOut = 8'b00000000;
	end
	
	always@(addr)
		begin
			if (addr == 0) begin dataOut = 8'b00000000;end
			if (addr == 1) begin dataOut = 8'b01010101;end
			if (addr == 2) begin dataOut = 8'b10101010;end
			if (addr == 3) begin dataOut = 8'b00110011;end
			if (addr == 4) begin dataOut = 8'b11001100;end
			if (addr == 5) begin dataOut = 8'b00001111;end
			if (addr == 6) begin dataOut = 8'b11110000;end
			if (addr == 7) begin dataOut = 8'b11111111;end
		end
	
	
endmodule


module XOR_RAM (
input mode, 
input [2:0] addr, 
input [7:0] dataIn, 
input [7:0] mask, 
input CLK, 
output reg [7:0] dataOut);
	
	reg [7:0] ram [7:0];
	integer i;
	
	initial
	begin
		dataOut = 0;
		for (i = 0; i < 8; i = i + 1)
		begin
			ram[i] =  0;
		end
	end
	
	// write mode
	always@(posedge CLK)
	begin
		if (mode == 0)
		begin
			ram[addr] = (dataIn ^ mask);
		end
	end	
	
	// read mode
	always@(mode, addr) 
	begin
		if (mode == 1)
		begin
			dataOut = ram[addr];
		end
	end
	
endmodule


module EncodedMemory (
input mode, 
input [2:0] index, 
input [7:0] number, 
input CLK, 
output [7:0] result);
	
	// DO NOT EDIT THIS MODULE
	
	wire [7:0] mask;
	
	ROM R(index, mask);
	XOR_RAM XR(mode, index, number, mask, CLK, result);

endmodule
