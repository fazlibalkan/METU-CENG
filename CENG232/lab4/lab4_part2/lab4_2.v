`timescale 1ns / 1ps
module IntersectionSimulator(
	input [2:0] mode, //1xx:display, 000:remA, 001:remB, 010:addA, 011:addB
	input [4:0] plateIn,
	input action,
	input clk,
	output reg  greenForA,
	output reg  greenForB,
	output reg 	rushHourWarning,
	output reg [3:0]  hour,
	output reg [5:0]  minute,	
	output reg [5:0]  second,
	output reg	am_pm, //0:am, 1:pm
	output reg [4:0]  numOfCarsA,
	output reg [4:0]  numOfCarsB,
	output reg [6:0]  remainingTime,
	output reg [4:0]  blackListDisplay
	);
	
	//You may write your code anywhere
	
	//memories for the roads as queues
	reg [4:0] memA [0:29];
	reg [4:0] memB [0:29];
	
	reg [4:0] startA;
	reg [4:0] endA;
	reg [4:0] startB;
	reg [4:0] endB;
	
	//min-max stuff
	reg [6:0] minA;
	reg [6:0] maxA;
	reg [6:0] minB;
	reg [6:0] maxB;
	
	reg [6:0] currA;
	reg [6:0] currB;
	
	reg [1:0] green;
	
	//black list
	reg [4:0] blackList [0:29];
	reg [4:0] b;
	reg [4:0] startBL;
	reg [4:0] endBL;

	integer i;
	
	initial begin
		greenForA=1;
		greenForB=0;
		rushHourWarning=0;
		hour=6;
		minute=0;
		second=0;
		am_pm=0;
		numOfCarsA=0;
		numOfCarsB=0;
		remainingTime=50;
		blackListDisplay=0;
		
		green = 0;
		
		//...
		minA = 40;
		maxA = 70;
		minB = 50;
		maxB = 80;
		
		currA = minA;
		currB = minB;
		
		startA = 0;
		endA = 0;
		startB = 0;
		endB = 0;
		
		startBL = 0;
		endBL = 0;
		
		for (i = 0; i < 30; i = i + 1)
		begin
			memA[i] = 5'b00000;
			memB[i] = 5'b00000;
			blackList[i] = 5'b00000;
		end
		
	end
	
	always@(posedge action)
	begin
	
		//remove operations
		startBL = 0;
		
		if (mode == 3'b000)
		begin
			if (numOfCarsA > 0)
			begin
				if (greenForA == 0)
				begin
					b = memA[startA];
					blackList[endBL] = b;
					endBL = (endBL + 1)%30;
				end
				memA[startA] = 5'b00000;
				startA = (startA + 1)%30;
				numOfCarsA = numOfCarsA - 1;
			end
		end
		
		if (mode == 3'b001)
		begin
			if (numOfCarsB > 0)
			begin
				if (greenForB == 0)
				begin
					b = memB[startB];
					blackList[endBL] = b;
					endBL = (endBL + 1)%30;
				end
				memB[startB] = 5'b00000;
				startB = (startB + 1)%30;
				
				numOfCarsB = numOfCarsB - 1;
			end
		end
		
		//add operations
		if (mode == 3'b010)
		begin
			memA[endA] = plateIn;
			endA = (endA + 1)%30;
			numOfCarsA = numOfCarsA + 1;
		end
		
		if (mode == 3'b011)
		begin
			
			memB[endB] = plateIn;
			endB = (endB + 1)%30;
			numOfCarsB = numOfCarsB + 1;
		end
		
	end


	always @(posedge clk)
	begin
		
		//display mode
		if (mode[2] == 1)
		begin
			if (endBL == 0)
			begin
				blackListDisplay = 0;
			end
			else
			begin
				if (startBL >= endBL)
				begin
					startBL = 0;
				end
				blackListDisplay = blackList[startBL];	
				startBL = startBL + 1;
			end
			
		end
		
		
		if (mode[2] == 0)
		begin
			remainingTime = remainingTime - 1;
			
			if (green != 0)
			begin
				if (green == 1)
				begin
					greenForB = 1;
					green = 0;
					
					if (numOfCarsB <= 10)
					begin currB = currB + 5; end
					else if (numOfCarsB >= 20)
					begin currB = currB - 5; end
					
					if (currB < minB)
					begin currB = minB; end
					
					if (currB > maxB)
					begin currB = maxB; end
					
					remainingTime = currA;
				end
				if (green == 2)
				begin
					greenForA = 1;
					green = 0;
					
					if (numOfCarsA <= 10)
					begin currA = currA + 5; end
					else if (numOfCarsA >= 20)
					begin currA = currA - 5; end
					
					if (currA < minA)
					begin currA = minA; end
					
					if (currA > maxA)
					begin currA = maxA; end
	
					remainingTime = currB;
					
				end
			end
			//--------------------------------
			// Some light is turning red
			if (remainingTime == 0)
			begin
				// A turns red
				if (greenForA == 1)
				begin
					greenForA = 0;
					green = 1;
				end
				// B turns red
				if (greenForB == 1)
				begin
					greenForB = 0;
					green = 2;
					
				end
			end
			//-----------------------------------
			//time stuff
			second = (second + 1)%60;
			if (second == 0)
			begin
				minute = (minute + 1)%60;
				if (minute == 0)
				begin
					if (hour == 11)
					begin
						if (am_pm == 1)
						begin
							for (i = 0; i < 30; i = i+1)
							begin
								blackList[i]=0;
							end
							blackListDisplay = 0;
							hour = 12;
							am_pm = 0;
							startBL = 0;
							endBL = 0;
						end else begin
							am_pm = 1;
							hour = 12;
						end
						
					end
					else
					begin
						hour = (hour + 1)%12;
					end
					
				end
			end
			
			//rush hour check, min-max setting
			if (((hour == 7 || hour == 8) && !am_pm) || ((hour == 5 || hour == 6) && am_pm))
			begin
				rushHourWarning = 1;
				minA = 30; maxA = 60;
				minB = 40; maxB = 70;
			end
			else
			begin
				rushHourWarning = 0;
				minA = 40; maxA = 70;
				minB = 50; maxB = 80;
			end
			
		end
	end


endmodule
