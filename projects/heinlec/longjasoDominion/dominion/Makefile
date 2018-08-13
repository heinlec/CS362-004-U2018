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

randomtests.out: dominion.o interface.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o randomcardtest1 -g randomtestcard1.c dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o randomcardtest2 -g randomtestcard2.c dominion.o rngs.o interface.o $(CFLAGS)
	
	./randomtestadventurer >> randomtestresults.out
	./randomcardtest1 >> randomtestresults.out
	./randomcardtest2 >> randomtestresults.out
	gcov -f -b dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

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
