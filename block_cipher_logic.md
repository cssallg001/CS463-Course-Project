ECB: 
	y_1:
		• y_1 = e_[8-bit key] [First two hex values of 16-bit input]
		• LT = [1st character of 16-bit input] 
		• RT = [2nd character of 16-bit input] 
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• Combine LC and RC to get 1st half of ECB
	y_2:
		• y_2 = e_[8-bit key] [Last two hex values of 16-bit input]
		• LT = [3rd character of 16-bit input] 
		• RT = [4th character of 16-bit input] 
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• Combine LC and RC to get 2nd half of ECB

	
CBC:
	y_1:
		• y_1 = e_[8-bit key] [{First two hex values of 16-bit input} xor {IV}]
		• LT = [1st character of 16-bit input] xor [1st character of IV] 
		• RT = [2nd character of 16-bit input] xor [2nd character of IV] 
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• y_1 = LC||RC
	y_2:
		• y_2 = e_[8-bit key] [{Last two hex values of 16-bit input} xor {y_1}]
		• LT = [3rd character of 16-bit input] xor [1st character of y_1] 
		• RT = [4th character of 16-bit input] xor [2nd character of y_1] 
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• y_ = LC||RC


OFB:
	s_1:
		• s_1 = e_[8-bit key] [IV]
		• LT = [1st character of IV]
		• RT = [2nd character of IV] 
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RC xor LT
		• Combine LC and RC
		• s_1 = LC||RC xor [1st two hex values of 16-bit input]
	s_2:
		• s_2 = e_[8-bit key] [LCs1||RCs1]
		• LT = LCs1
		• RT = RCs1
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• s_2 = LC||RC xor [2nd two hex values of 16-bit input]
		
		
CFB:
	s_1:
		• s_1 = e_[8-bit key] [IV]
		• LT = [1st character of IV]
		• RT = [2nd character of IV] 
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RC xor LT
		• Combine LC and RC
		• s_1 = LC||RC xor [1st two hex values of 16-bit input]
	s_2:
		• s_2 = e_[8-bit key] [s_1]
		• LT = [1st character of s_1]
		• RT = [1st character of s_2]
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• s_2 = LC||RC xor [2nd two hex values of 16-bit input]


CTR:
	y_1:
		• y_1 = e_[8-bit key] [{2nd character of hex key} {incrementing counter}]
		• LT = [2nd character of hex key]
		• RT = [incrementing counter]
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• y_1 = LC||RC xor [1st two hex values of 16-bit input]
	y_2:
		• y_2 = e_[8-bit key] [{2nd character of hex key} {incrementing counter}]
		• LT = [2nd character of hex key]
		• RT = [incrementing counter]
		• LK = [1st character of 8-bit key] 
		• RK = [2nd character of 8-bit key] 
		• LC = LK xor RT
		• RC = RK xor LT
		• y_2 = LC||RC xor [2nd two hex values of 16-bit input]