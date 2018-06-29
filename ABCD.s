.name "ABCD"
.comment "EFGH"

begin:
	st		r1, r2
	st		r16, :begin
	sti		r2, %:start_fork, %1
	sti		r2, %:fork1, %1
	sti		r2, %:fork2, %1
	ld		%10, r3
	ld		%500, r10
	and		r1, %0, r1

start_fork:
	live	%0
	and		r1, %0, r1
	fork	%:fork2

fork1:
	live	%0
	fork	%:fork3
	ld		%190055427, r4
	ld		%0, r5
	zjmp	%:end

fork2:
	live	%0
	fork	%:fork4
	ld		%67306753, r4
	ld		%2, r5
	and		r1, %0, r1
	zjmp	%:end

fork3:
	st		r2, r4
	ld		%6,  r5
	and		r1, %0, r1
	zjmp	%:end

fork4:
	zjmp	%:start_fork

end:
	sti		r4, r10, r5

jump:
	zjmp	%495
