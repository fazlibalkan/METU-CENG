`timescale 1ns / 1ps

//
// NOTE: This is a sample testbench, provided to you as a guidance.
//

module testbench(
    );
	
	reg	[2:0] mode; //1XX:display; 000: remA; 001:remB; 010:addA; 011:addB
	reg	[4:0] plateIn;
	reg   action;
	reg   clk;
	wire  greenForA;
	wire  greenForB;
	wire  rushHourWarning;
	wire  [3:0]  hour;
	wire  [5:0]  minute;	
	wire  [5:0]  second;
	wire  am_pm;
	wire  [4:0]  numOfCarsA;
	wire  [4:0]  numOfCarsB;
	wire  [6:0]  remainingTime;
	wire  [4:0]  blackListDisplay;

	integer iter;

	// Instantiate the Unit Under Test (UUT)
   IntersectionSimulator uut(
		mode,
		plateIn,
		action,
		clk,
		greenForA,
		greenForB,
		rushHourWarning,
		hour,
		minute,
		second,
		am_pm,
		numOfCarsA,
		numOfCarsB,
		remainingTime,
		blackListDisplay
	);

    initial clk = 0;
	always #5 clk = ~clk;
	

	initial begin
		mode = 0;
		action = 0;
		for (iter = 0; iter < 15; iter = iter + 1)
			begin
				#20;
				action = ~action;
				plateIn = iter + 1;
				if (iter % 2 == 0)
					mode = 011;
				else
					mode = 001;
			end
		action = 0;
		if (numOfCarsB == 7)
			$display("Case 0: Successfull!");
		else
			$display("Case 0: Failure!");
		while (greenForA == 1'b1)
			begin
				#10;
				action = ~action;
				mode = 001;
			end
		mode = 3'b1xx;
		for (iter = 0; iter < 5; iter = iter + 1)
			begin
				#10;
				if (iter % 2 == 0)
					begin
						if ((iter * 2) + 1 == blackListDisplay)
							$display("Case %2d: Successfull!", iter / 2 + 1);
						else
							$display("Case %2d: Failure!", iter / 2 + 1);
					end
			end
		action = 0;
		mode = 3'b000;
		//Waiting for 1 second.
		#10;
		mode = 010;
		for (iter = 1; iter < 7; iter = iter + 1)
			begin
				#10;
				plateIn = iter * 2;
				action = ~action;		
			end
		action = 0;
		mode = 3'b000;
		while (greenForB == 1'b1)
			#10;		
		
	
		#10;
		//Waited for 1 second.	
		
		if (greenForA == 1 && numOfCarsA == 3 && remainingTime == 55)
			$display("Case 4: Successfull!");
		else
			$display("Case 4: Failure!");
		while (greenForA == 1'b1)
			begin
				mode = 0;
				action = ~action;
				#10;
			end	
		action = 0;
		if (greenForA == 0 && numOfCarsA == 0)
			$display("Case 5: Successfull!");
		else
			$display("Case 5: Failure!");
		
		#36000;
		//Waited for 1 hour.
		if (remainingTime == 65 && rushHourWarning && greenForA)
			$display("Case 6: Successfull!");
		else
			$display("Case 6: Failure!");
			
		while (greenForA == 1'b1)
			#10;
		//Waiting for 5 minutes.
		#3000;
		if (remainingTime == 25 && greenForB && rushHourWarning)
			$display("Case 7: Successfull!");
		else
			$display("Case 7: Failure!");
		
		#66870;
		if (greenForA && rushHourWarning)
			$display("Case 8: Successfull!");
		else
			$display("Case 8: Failure!");
		#10;
		if (greenForA && !rushHourWarning)
			$display("Case 9: Successfull!");
		else
			$display("Case 9: Failure!");		
		mode = 010;
		#20;
		for (iter = 1; iter < 8; iter = iter + 1)
			begin
				#10;
				plateIn = iter * 2;
				action = ~action;
			end
		mode = 0;
		#20;
		for (iter = 1; iter < 8; iter = iter + 1)
			begin
				#10;
				action = ~action;
			end
		action = 0;
		mode = 3'b1xx;
		for (iter = 0; iter < 5; iter = iter + 1)
			#10;
		mode = 0;
		if (numOfCarsA == 0 && blackListDisplay == 9)
			$display("Case 10: Successfull!");
		else
			$display("Case 10: Failure!");
		#539810;
		$display("Time= %2d:%2d:%2d, PM: %2d, Remaining Time: %2d, Green for A: %2d, Green for B: %2d, Number of Cars on RoadA: %2d, Number of Cars on RoadB: %2d, BlackList Display: %2d ", hour, minute, second, am_pm, remainingTime, greenForA, greenForB, numOfCarsA, numOfCarsB, blackListDisplay);
		#10;
		$display("Time= %2d:%2d:%2d, PM: %2d, Remaining Time: %2d, Green for A: %2d, Green for B: %2d, Number of Cars on RoadA: %2d, Number of Cars on RoadB: %2d, BlackList Display: %2d ", hour, minute, second, am_pm, remainingTime, greenForA, greenForB, numOfCarsA, numOfCarsB, blackListDisplay);
		$finish;
		
	end
      
endmodule
