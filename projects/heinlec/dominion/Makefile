CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
	gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unitTest1: unittest1.c dominion.o rngs.o
	gcc -o unitTest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unitTest2: unittest2.c dominion.o rngs.o
	gcc -o unitTest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unitTest3: unittest3.c dominion.o rngs.o
	gcc -o unitTest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unitTest4: unittest4.c dominion.o rngs.o
	gcc -o unitTest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

cardTest1: cardtest1.c dominion.o rngs.o
	gcc -o cardTest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardTest2: cardtest2.c dominion.o rngs.o
	gcc -o cardTest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

cardTest3: cardtest3.c dominion.o rngs.o
	gcc -o cardTest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardTest4: cardtest4.c dominion.o rngs.o
	gcc -o cardTest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

unittestresults.out: dominion.o interface.o
	gcc -o test8 -g cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test7 -g cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test6 -g cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test5 -g cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test4 -g unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test3 -g unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test2 -g unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o test1 -g unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
	./test8 >> unittestresults.out
	./test7 >> unittestresults.out
	./test6 >> unittestresults.out
	./test5 >> unittestresults.out
	./test4 >> unittestresults.out
	./test3 >> unittestresults.out
	./test2 >> unittestresults.out
	./test1 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out 

#unittestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c dominion.c rngs.c

	#echo "Result for running Dominion test suite:" > unittestresults.out
	
	#echo "unittest1.c:" >> unittestresults.out
	#gcc -o unitTest1 -g  unittest1.c dominion.c rngs.c $(CFLAGS)
	#./unitTest1 >> unittestresults.out
	#gcov unittest1.c >> unittestresults.out
	#cat unittest1.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	#echo "unittest2.c:" >> unittestresults.out
	#gcc -o unitTest2 -g  unittest2.c dominion.c rngs.c $(CFLAGS)
	#./unitTest2 >> unittestresults.out
	#gcov unittest2.c >> unittestresults.out
	#cat unittest2.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	#echo "unittest3.c:" >> unittestresults.out
	#gcc -o unitTest3 -g  unittest3.c dominion.c rngs.c $(CFLAGS)
	#./unitTest3 >> unittestresults.out
	#gcov unittest3.c >> unittestresults.out
	#cat unittest3.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	#echo "unittest4.c:" >> unittestresults.out
	#gcc -o unitTest4 -g  unittest4.c dominion.c rngs.c $(CFLAGS)
	#./unitTest4 >> unittestresults.out
	#gcov unittest4.c >> unittestresults.out
	#cat unittest4.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	#echo "cardtest1.c:" >> unittestresults.out
	#gcc -o cardTest1 -g  cardtest1.c dominion.c rngs.c $(CFLAGS)
	#./cardTest1 >> unittestresults.out
	#gcov cardtest1.c >> unittestresults.out
	#cat cardtest1.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	#echo "cardtest2.c:" >> unittestresults.out
	#gcc -o cardTest2 -g  cardtest2.c dominion.c rngs.c $(CFLAGS)
	#./cardTest2 >> unittestresults.out
	#gcov cardtest2.c >> unittestresults.out
	#cat cardtest2.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	#echo "cardtest3.c:" >> unittestresults.out
	#gcc -o cardTest3 -g  cardtest3.c dominion.c rngs.c $(CFLAGS)
	#./cardTest3 >> unittestresults.out
	#gcov cardtest3.c >> unittestresults.out
	#cat cardtest3.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	#echo "cardtest4.c:" >> unittestresults.out
	#gcc -o cardTest4 -g  cardtest4.c dominion.c rngs.c $(CFLAGS)
	#./cardTest4 >> unittestresults.out
	#gcov cardtest4.c >> unittestresults.out
	#cat cardtest4.c.gcov >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out


runtests: testUpdateCoins 
	./testUpdateCoins &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unitTests: unitTest1
	./unitTest1 &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out unitTest* cardTest* testDrawCard testDrawCard.exe
