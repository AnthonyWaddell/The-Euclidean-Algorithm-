# The-Euclidean-Algorithm-
This program empirically analyzes the worst-case performance of the Euclidean algorithm for finding the greatest common divisor of two nonnegative integers


Purpose 

This programming assignment empirically analyzes] the worst-case performance of the Euclidean algorithm for finding the greatest common divisor of two nonnegative integers. You will code this program, plot its running times, and validate if your output is upper-bound to a given function. 

  

The Euclidean Algorithm 

The Euclidean algorithm computes the greatest common divisor (gcd) of two positive integers A and B, based on the observation gcd( A, B ) is equivalent to gcd( B, A modulus B ). In other words, the greatest common divisor of positive integers A and B is equal to the greatest common divisor of the integers B and the result of A modulus B. In other words, given two positive integers, their gcd is computed by repetitions of the following three statements: R = A % B; A = B; B = R; until B becomes 0.  

Example for gcd(270, 192):  

78 = 270 % 192; R = 78, A = 270, B = 192; Next step: gcd (B, R) = gcd (192, 78) 

36 = 192 % 78;  R = 36, A = 192, B = 78; Next step: gcd (B, R) = gcd (78, 36) 

6 = 78 % 36; R = 6, A = 78, B = 36; Next step: gcd (B, R) = gcd (36, 6) 

0 = 36 % 6; R = 0, A = 36, B = 6; This has shown that gcd (36, 6) = 6. 

Going back up the chain: 6 = gcd (36, 6) = gcd (78, 36) = gcd (192, 78) = gcd (270, 192); 

Therefore, gcd(270, 192) = 6; 

Another way to express this example: to find the gcd of 270 and 192,  

gcd(270,192) = gcd(192,78) = gcd(78,36) = gcd(36,6) = gcd(6,0) = 6 

That is, gcd(270, 192) = 6. 

https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm (Links to an external site.) 

The worse-case performance is log3/22n/3 modulus operations required for computing the gcd of two integers in the range 1 to n, where n >= 8. 
