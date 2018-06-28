.name "ABCD"
.comment "EFGH"

begin:
	st		r1, r2
	st		r16, :begin
	sti		r2, %:fork1, %1
	sti		r2, %:fork2, %1
	ld		%10, r3
	and		r1, %0, r1
	fork	:fork2

fork1:
	live	%0
	fork	:fork3
	ld		%190055427, r4
	ld		%0, r5
	and		r1, %0, r1
	zjmp	:end

fork2:
	live	%0
	fork	:fork4
	ld		%67306753, r4
	ld		%2, r5
	and		r1, %0, r1
	zjmp	:end

fork3:
	st		r2, r4
	ld		%6,  r5
	and		r1, %0, r1
	zjmp	:end

fork4:
	zjmp	:begin

end:
	sti		r4, r3, r5
