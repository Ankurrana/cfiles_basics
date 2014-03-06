Var rounds,n:longint;
begin
	read(rounds);
	while rounds>0 do
		begin
			dec(rounds);
			read(n);
			if odd(n) then writeln('BOB') else writeln('ALICE');
			
		end;
end.
