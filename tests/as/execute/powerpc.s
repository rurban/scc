	B	$L1	# 48 00 00 0C
	BA	$L1	# 48 00 00 0E
	BL	$L1	# 48 00 00 0D
L1:	BLA	$L1	# 48 00 00 07

	BC	$3,$2,$L2	# 40 62 38 00
	BCA	$2,$1,$L2	# 40 41 18 02
	BCL	$1,$3,$L2	# 40 23 38 01
L2:	BCLA	$3,$4,$L2	# 40 64 08 03

	BCLR	$1,$2,$2	# 4C 22 10 20
	BCLRL	$2,$2,$1	# 4C 42 08 21
