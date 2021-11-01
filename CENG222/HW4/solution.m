N = 21140; %N >= 21139.3425
C = 250; %5*50

p = 0.62; %given

Totalw=zeros(N,1);

for k = 1 : N;
    
    w = 0; %variable for weight
    
	i = sum(rand(C,1) < p);
	Y = i;
    
	s = 0;
    t = 8;
    m = 0.22;
    
	for f = 1 : Y; 
        
		CX = 0;
        CY = m; 
		F = 0; % initial F at CX = 0
        
		while (CY > F); 
            
			U = rand; 
            V = rand;
			
            CX = s+(t-s)*U; 
            CY = m*V;
			
			if (CX <= 2)
				F = 0.07*CX;
			elseif (CX <= 5)
				F = -0.02 * (CX-4)^2 + 0.22;
			elseif (CX <=7)
				F = 0.08 * (5-CX) + 0.2;
			else
				F = -0.04 * CX + 0.32;
            end
            
		end;
		w = w + CX;	
	end;
	Totalw(k) = w;
end;

p_est = mean(Totalw>640);
expectedw = mean(Totalw);
stdw = std(Totalw);

%printing the results of the Monte Carlo study
fprintf('Estimated probability = %f\n',p_est);
fprintf('Expected w = %f\n',expectedw);
fprintf('Standard deviation = %f\n',stdw);