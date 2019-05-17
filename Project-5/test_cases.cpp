
/*
TESTING makeProper

1.All valid patterns
makeProper(word1A,word2A,separation,5)

2.All invalid patterns
makeProper(word1C,word2C,separationC,4)

3.Non-alphabet character
makeProper(word1A,word2A,separationA,6)

4.Empty string
makeProper(word1B,word2B,separationB,5)

5.Negative separation
makeProper(word1D,word2D,separationD,5)

6.Non-alphabet, empty string and negative separation
makeProper(word1E,word2E,separationE,8)

7.Consecutive invalid patterns
makeProper(word1E,word2E,separationE,8)

8.Negative nPatterns
makeProper(word1C,word2C,separationC,-5)

9.Zero nPatterns
makeProper(word1C,word2C,separationC,0)

10.Uppercase strings
makeProper(word1G,word2G,separationG,3)

11.Patterns repeated twice with different serparation values
makeProper(word1F,word2F,separationF,6)

12.Patterns repeated twice with same serparation values
makeProper(word1H,word2H,separationH,4)

13.Multiple Patterns repeated twice with different serparation values
makeProper(word1F,word2F,separationF,7)

14.Patterns repeated more than twice
makeProper(word1I,word2I,separationI,8)


TESTING rate

1.Document of single space separated words containing only alphabet
rate(doc1,test1w1, test1w2, test1dist, TEST1_NRULES)

2.Multiple spaces between words
rate(doc2,test1w1, test1w2, test1dist, TEST1_NRULES)

3.Document has leading spaces
rate(doc7,test1w1, test1w2, test1dist, TEST1_NRULES)

4.Document has trailing spaces
rate(doc8,test1w1, test1w2, test1dist, TEST1_NRULES)

5.Document has extra spaces before, after string and between words
rate(doc9,test1w1, test1w2, test1dist, TEST1_NRULES)

6.Document has single space separated words containing numbers and special characters
ate(doc10,test1w1, test1w2, test1dist, TEST1_NRULES)

7.Document has multiple space separated words containing numbers and special characters
rate(doc11,test1w1, test1w2, test1dist, TEST1_NRULES)

8.Document contains only invalid characters
rate(doc3,test1w1, test1w2, test1dist, TEST1_NRULES)

9.Document is a blank string
rate(doc6,test1w1, test1w2, test1dist, TEST1_NRULES)

10.Document contains smae pattern multiple times
rate(doc5,test1w1, test1w2, test1dist, TEST1_NRULES)

11.Pattern occurs in document, but in reverse order
rate(doc4,test1w1, test1w2, test1dist, TEST1_NRULES)

*/

int main(){

	//TESTING makeProper
	char word1A[][MAX_WORD_LENGTH+1] = {"mad" , "deranged" , "NEFARIOUS"   ,
								   	    "kid" , "have"     , "half-witted" ,
								   	    "hi"  , "car"};


	char word2A[][MAX_WORD_LENGTH+1] = {"scientist"  , "robot" , "PLOT" ,
								        "AdUlT"      , "mad"   , "half" ,
								    	"hello"      , "bike"};
	int separationA[] = {1 , 3 , 0 ,
						 2 ,12 , 4 ,
						 12, -3};

    char word1B[][MAX_WORD_LENGTH+1] = {"mad"        , ""   , "NEFARIOUS" ,
								   	   "halfwitted"  , ""};
	char word2B[][MAX_WORD_LENGTH+1] = {"scientist"  , ""   , "PLOT"      ,
								       "groan"       , "mad"};
	int separationB[] = {1 , 3 , 0 ,
					     2 ,12};

	char word1C[][MAX_WORD_LENGTH+1] = {"m@d", "have", "123GO", "UCLA" };
	char word2C[][MAX_WORD_LENGTH+1] = {"tin", "some", "groan", "1234" };
	int separationC[] =                {1    , -1    , 4      , 12};

	char word1D[][MAX_WORD_LENGTH+1] = {"mad", "have", "great", "UCLA", "hi"};
	char word2D[][MAX_WORD_LENGTH+1] = {"tin", "some", "groan", "UCBB", "by"};
	int separationD[] =                {1    , -1    , 4      , -12   , 2};

	char word1E[][MAX_WORD_LENGTH+1] = {"mad" , "deranged" , "NEFARIOUS"   ,
								   	    "kid" , "have"     , "half-witted" ,
								   	    "hi"  , "car"};


	char word2E[][MAX_WORD_LENGTH+1] = {"scientist"  , "robot" , "PLOT" ,
								        ""           , "mad"   , "half" ,
								    	"hello"      , "bike"};
	int separationE[] = {1 , 3 , 0 ,
						 2 ,-12 , 4 ,
						 12, -3};

	char word1F[][MAX_WORD_LENGTH+1] = {"mad" , "deranged" , "scientist"   ,
								   	    "kid" , "hello"    , "halfwitted" ,
								   	    "hi"  , "mad"};

	char word2F[][MAX_WORD_LENGTH+1] = {"scientist"  , "robot" , "mad"  ,
								        "AdUlT"      , "hi"    , "half" ,
								    	"hello"      , "scientist" };
	int separationF[] = {1 , 3 , 10 ,
						 2 , 1 , 4  , 
						 12, 13};

	char word1G[][MAX_WORD_LENGTH+1] = {"MAD", "GREAT", "HI"};
	char word2G[][MAX_WORD_LENGTH+1] = {"tin", "some" , "by"};
	int separationG[] =                {1    , 4      , 2};

	char word1H[][MAX_WORD_LENGTH+1] = {"mad", "have", "tin", "UCLA" };
	char word2H[][MAX_WORD_LENGTH+1] = {"tin", "some", "mad", "UCLA" };
	int separationH[] =                {1    , 1     , 1      , 12};

	char word1I[][MAX_WORD_LENGTH+1] = {"mad" , "deranged" , "scientist"   ,
								   	    "kid" , "hello"    , "halfwitted" ,
								   	    "him" , "mad"};

	char word2I[][MAX_WORD_LENGTH+1] = {"scientist"  , "robot" , "mad"  ,
								        "AdUlT"      , "hi"    , "half" ,
								    	"hello"      , "scientist" };
	int separationI[] = {1 , 3 , 10 ,
						 2 , 1 , 4  , 
						 12, 13};

	//TEST 1
	assert(makeProper(word1A,word2A,separationA,5) == 5 &&
			!strcmp(word1A[0],"mad")       && !strcmp(word1A[1],"deranged") && !strcmp(word1A[2],"nefarious") &&
			!strcmp(word1A[3],"kid")       && !strcmp(word1A[4],"have")     &&

			!strcmp(word2A[0],"scientist") && !strcmp(word2A[1],"robot")    && !strcmp(word2A[2],"plot")      &&
			!strcmp(word2A[3],"adult")     && !strcmp(word2A[4],"mad")      &&

			separationA[0] == 1            && separationA[1] == 3           && separationA[2] == 0            &&
			separationA[3] == 2            && separationA[4] == 12);

	//TEST 2
	assert(makeProper(word1C,word2C,separationC,4) == 0);

	//TEST 3
	assert(makeProper(word1A,word2A,separationA,7) == 6 &&
			!strcmp(word1A[0],"mad")       && !strcmp(word1A[1],"deranged") && !strcmp(word1A[2],"nefarious") &&
			!strcmp(word1A[3],"kid")       && !strcmp(word1A[4],"have")     && !strcmp(word1A[5],"hi")        &&

			!strcmp(word2A[0],"scientist") && !strcmp(word2A[1],"robot")    && !strcmp(word2A[2],"plot")      &&
			!strcmp(word2A[3],"adult")     && !strcmp(word2A[4],"mad")      && !strcmp(word2A[5],"hello")     &&

			separationA[0] == 1            && separationA[1] == 3           && separationA[2] == 0            &&
			separationA[3] == 2            && separationA[4] == 12          && separationA[5] == 12);

	//TEST 4
	assert(makeProper(word1B,word2B,separationB,5) == 3 &&
			!strcmp(word1B[0],"mad")       && !strcmp(word1B[1],"nefarious") && !strcmp(word1B[2],"halfwitted") &&	

			!strcmp(word2B[0],"scientist") && !strcmp(word2B[1],"plot")      && !strcmp(word2B[2],"groan")      &&

			separationB[0] == 1            && separationB[1] == 0            && separationB[2] == 2          );	

	//TEST 5
	assert(makeProper(word1D,word2D,separationD,5) == 3 &&
			!strcmp(word1D[0],"mad") && !strcmp(word1D[1],"great") && !strcmp(word1D[2],"hi") &&	

			!strcmp(word2D[0],"tin") && !strcmp(word2D[1],"groan") && !strcmp(word2D[2],"by") &&

			separationB[0] == 1            && separationD[1] == 4  && separationD[2] == 2);

	//TEST 6 and 7
	assert(makeProper(word1E,word2E,separationE,8) == 4 &&
			!strcmp(word1E[0],"mad")       && !strcmp(word1E[1],"deranged") && !strcmp(word1E[2],"nefarious") &&
			!strcmp(word1E[3],"hi")        &&

			!strcmp(word2E[0],"scientist") && !strcmp(word2E[1],"robot")    && !strcmp(word2E[2],"plot")      &&
			!strcmp(word2E[3],"hello")     && 

			separationE[0] == 1            && separationE[1] == 3           && separationE[2] == 0            &&
			separationE[3] == 12);

	//TEST 8
	assert(makeProper(word1C,word2C,separationC,-5) == 0);

	//TEST 9
	assert(makeProper(word1C,word2C,separationC,0) == 0);

	//TEST 10
	assert(makeProper(word1G,word2G,separationG,3) == 3 &&
			!strcmp(word1G[0],"mad") && !strcmp(word1G[1],"great") && !strcmp(word1G[2],"hi") &&	

			!strcmp(word2G[0],"tin") && !strcmp(word2G[1],"some")  && !strcmp(word2G[2],"by") &&

			separationG[0] == 1      && separationG[1] == 4        && separationG[2] == 2);

	//TEST 11
	assert(makeProper(word1F,word2F,separationF,6) == 5 &&
			!strcmp(word1F[0],"deranged")   && !strcmp(word1F[1],"scientist")  && !strcmp(word1F[2],"kid")   &&
			!strcmp(word1F[3],"hello")      && !strcmp(word1F[4],"halfwitted") &&

			!strcmp(word2F[0],"robot")      && !strcmp(word2F[1],"mad")        && !strcmp(word2F[2],"adult") &&
			!strcmp(word2F[3],"hi")         && !strcmp(word2F[4],"half")       &&

			separationF[0] == 3             && separationF[1] == 10            && separationF[2] == 2         &&
			separationF[3] == 1             && separationF[4] == 4);

	//TEST 12
	assert(makeProper(word1H,word2H,separationH,4) == 3 &&
			!strcmp(word1H[0],"mad") && !strcmp(word1H[1],"have") && !strcmp(word1H[2],"ucla") &&	

			!strcmp(word2H[0],"tin") && !strcmp(word2H[1],"some") && !strcmp(word2H[2],"ucla") &&

			separationH[0] == 1      && separationH[1] == 1       && separationH[2] == 12);

	//TEST 13
	assert(makeProper(word1I,word2I,separationI,8) == 6 &&
			!strcmp(word1I[0],"deranged")   && !strcmp(word1I[1],"kid")   && !strcmp(word1I[2],"hello")         &&
			!strcmp(word1I[3],"halfwitted") && !strcmp(word1I[4],"him")   && !strcmp(word1I[5],"mad")           &&

			!strcmp(word2I[0],"robot")      && !strcmp(word2I[1],"adult") && !strcmp(word2I[2],"hi")            &&
			!strcmp(word2I[3],"half")       && !strcmp(word2I[4],"hello") && !strcmp(word2I[5],"scientist")     &&

			separationI[0] == 3             && separationI[1] == 2        && separationI[2] == 1                &&
			separationI[3] == 4             && separationI[4] == 12       && separationI[5] == 13);

	cerr<<"ALL TESTS PASSED FOR makeProper"<<endl;

	const int TEST1_NRULES = 4;
    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
       	"mad",       "deranged", "nefarious", "have"
     };
    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
    	"scientist", "robot",    "plot",      "mad"
     };
  	int test1dist[TEST1_NRULES] = {
 		1,           3,          0,           12
	};
	char doc1[MAX_DOCUMENT_LENGTH] = "The mad UCLA scientist unleashed a deranged evil giant robot";
	char doc2[MAX_DOCUMENT_LENGTH] = "The mad        UCLA scientist     unleashed    a deranged robot";
	char doc3[MAX_DOCUMENT_LENGTH] = "**** 2018 ****";
	char doc4[MAX_DOCUMENT_LENGTH] = "  That plot: NEFARIOUS!";
	char doc5[MAX_DOCUMENT_LENGTH] = "deranged deranged robot deranged robot robot";
	char doc6[MAX_DOCUMENT_LENGTH] = "";
	char doc7[MAX_DOCUMENT_LENGTH] = "     The mad UCLA scientist unleashed a deranged evil giant robot";
	char doc8[MAX_DOCUMENT_LENGTH] = "The mad UCLA scientist unleashed a deranged evil giant robot    ";
	char doc9[MAX_DOCUMENT_LENGTH] = "    The mad        UCLA scientist     unleashed    a deranged robot       ";
	char doc10[MAX_DOCUMENT_LENGTH] = "The mad UCLA scientist unleashed 478 deranged evil people-killing giant robots!!!!!";
	char doc11[MAX_DOCUMENT_LENGTH] = "      The mad UCLA     scientist unleashed 478 deranged evil         people-killing giant         robots! !!   !!       ";
	char doc12[MAX_DOCUMENT_LENGTH] = "robot car tree metal deranged man robot tree";

	//TEST 1
    assert(rate(doc1,test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    //TEST 2
    assert(rate(doc2,test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    //TEST 3
    assert(rate(doc7,test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    //TEST 4
    assert(rate(doc8,test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    //TEST 5
    assert(rate(doc9,test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    //TEST 6
    assert(rate(doc10,test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    //TEST 7
    assert(rate(doc11,test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    //TEST 8
    assert(rate(doc3,test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    //TEST 9
    assert(rate(doc6,test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    //TEST 10
    assert(rate(doc5,test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    //TEST 11
    assert(rate(doc4,test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    //TEST 12
    assert(rate(doc12,test1w1, test1w2, test1dist, TEST1_NRULES) == 1);

	cerr<<"ALL TESTS PASSED FOR rate"<<endl;
	cerr<<"ALL TESTS PASSED"<<endl;
}
