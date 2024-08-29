It is science class of middle standard of MissMihye.

Today they are studying acid and alkalireactions. There are N bottles of acid/alkaline/neutral acid.

On each glass bottle its weight is markedin gram unit, the reactivity is indicated in -3 to +3, + means acidic solution,- means alkaline solution and 0 means neutral And absolute value of these show strengthof reactivity.

Here 1 g of +2 strength acid can react with1g of -2 alkaline and it will generate 2 calories of energy and resultingsolution would be neutral. So when we mix acid and alkaline it would generateenergy as much as solution is neutralized. Like 10g of +3 acid have acidstrength 10x3 = +30 and it can neutralize alkaline of 15g and -2 (strength -30)to generate energy 30 calories and weight of resultant material is 10+ 15 g =25g.

 

Miss Mihye is asked to select R chemicalssuch that it generate maximum energy. She should select exact R bottles, notless than R bottles.

 

Let’s take an example :

Glass Bottle	1	2	3	4	5
Weight	30	10	70	50	50
Reactivity	1	-1	0	-3	-1

 

Here we need to select 3 bottles.

For {1, 2, 5} .. Weight is 90 and energy is30( 30x1 = +30, it can neutralize only 30 strength of alkaline even we havealkaline -10 -50 = -60. )

 

For {1,3,4} weight is 150, energy is again30.

In case we have same energy for somecombination we select with less weight.

[Input]

First line have number of test cases: T

Next line have N (5<= N <= 20):number of glass bottles and R(2<=R<=20) number of bottles Miss Mihye shouldselect.

Next we have weight Wi Wi(1<= Wi <= 100),Pi(-3 <= Pi <= 3) reactivity for N bottles.

[Output]

Output maximum calories which can begenerated along with weight..

 

[Inputexample

5 // Testcase 5

5 3

30 1 10 -1 70 0 50 -3 50 -1

5 3

30 -3 30 3 40 1 30 -3 10 -2

5 2

30 -1 90 2 70 -3 40 0 60 2

5 3

60 0 50 -1 20 2 80 3 40 2

5 5

80 -2 20 0 80 1 60 3 50 -2

[Outputexample]

30 90

90 70

180 160

50 110

260 290

