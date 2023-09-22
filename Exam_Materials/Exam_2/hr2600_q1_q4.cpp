/*


Question 1:

Theorem:

        When n >= 0 3^n = (3^n+1 - 1) / 2, where n is some non-negative integer.


Proof:

        By induction.


Base Case:

        P(n) = 0

        3^0 = (3^0+1 - 1) / 2

        1 = (3-1) / 2

        1 = 2 / 2

        1 = 1

        P(n) is true.

Induction Step:

        Inductive Hypothesis: 
        
        P(k): 3^k = (3^k+1 - 1) / 2

        P(k+1): 3^k+1 = (3^(k+1)+1 - 1) / 2

        3^1 * (3^k) = (3*(3^k+1) - 1) / 2


        Introduce the induction hypothesis

        3^1 * (3^k+1 - 1) / 2 = 3 * (3^k+1 - 1) / 2

        P(k+1) is true




--------------------------------------------------------------------------------------------


Question 2:

a.

Solution: C(2, 1) + C(7, 4) * 5!

Explanation: 
             Both Hal and Ida cannot be in the photo choose one of either Hal or Ida: C(2,1)

            After I choose either Hal or Ida I can choose 4 of the remaining 7 people 
            (where Hal or Ida was choose and I cannot choose the other that wasn't choose): C(7,4)

            Finally I need all the permutations of this occuring: 5!

--------------------------------------------------------------------------------------------

b.

Solution: C(8, 5)

Explanation: There are 8 valid values {1,2,5,6,7,8,9,10} and 5 must be choose to create a set.

--------------------------------------------------------------------------------------------

Question 3:

a.

Solution: 9/29

Explanation: There was 1 freshman already selected so we are left with 9 freshman and 29 possible selections,
             therofore the probability that the next select student is a freshmen is 9/29.


--------------------------------------------------------------------------------------------

b.

Solution: (C(8, 3) + C(8, 2) + C(8 ,1)) / 256

Explanation: There are 3 scenarios in which there are more 0's than 1's.
             When there are greater than 5 0's:
                    Therofore C(8, 3) + C(8, 2) + C(8 ,1)
             There are also 2^8 possible combination for a bit string of length 8
                    Therofore 256


--------------------------------------------------------------------------------------------

Question 4:

function1():

Solution: Theta(n^2*log(n))

Explanation:

            In the initial nested for-loop, in the first for-loop
            the for-loop is being incremented in large steps therefore: log(n)

            The nest loop is n therefore: n

            As a result: n*log(n)

            Since we need to account for the worst situation where n % 5,
            the second nested for-loop would be n^2

            As a result: n^2

            Final result: Theta(n^2*log(n))






--------------------------------------------------------------------------------------------

function2():

Solution: Theta(n*log(n))

Explanation:

            In the for-loop, in the first for-loop the for-loop is being
            incremented in large steps therefore: log(n)

            The while loop is dictated by the value of n therefore: n

            Final result: Theta(n*log(n))



--------------------------------------------------------------------------------------------
*/
