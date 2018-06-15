.name "test"
.comment "c'est un test"

debut:
		sti r1, %:survivre, %1
		ld %600, r16

survivre:
			live %1
			ld %42, r3
			ld %40, r4
			sti r3, %1, r16
			add r4, r16, r16
			and r1, %0, r1
			zjmp %:survivre
