#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OCTAVE_OFFSET 0

int notes[] = { 0,
262,277,294,311,330,349,370,392,415,440,466,494,
523,554,587,622,659,698,740,784,831,880,932,988,
1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976,
2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951
};

//char *song = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
//char *song = "Indiana:d=4,o=5,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6";
//char *song = "TakeOnMe:d=4,o=4,b=160:8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5,8f#5,8e5,8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5";
//char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p,8d,8d#,8e,c6,8e,c6,8e,2c.6,8p,8a,8g,8f#,8a,8c6,e6,8d6,8c6,8a,2d6";
//char *song = "Muppets:d=4,o=5,b=250:c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,8a,8p,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,8e,8p,8e,g,2p,c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,a,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,d,8d,c";
//char *song = "Xfiles:d=4,o=5,b=125:e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,g6,f#6,e6,d6,e6,2b.,1p,g6,f#6,e6,d6,f#6,2b.,1p,e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,e6,2b.";
//char *song = "Looney:d=4,o=5,b=140:32p,c6,8f6,8e6,8d6,8c6,a.,8c6,8f6,8e6,8d6,8d#6,e.6,8e6,8e6,8c6,8d6,8c6,8e6,8c6,8d6,8a,8c6,8g,8a#,8a,8f";
//char *song = "20thCenFox:d=16,o=5,b=140:b,8p,b,b,2b,p,c6,32p,b,32p,c6,32p,b,32p,c6,32p,b,8p,b,b,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,g#,32p,a,32p,b,8p,b,b,2b,4p,8e,8g#,8b,1c#6,8f#,8a,8c#6,1e6,8a,8c#6,8e6,1e6,8b,8g#,8a,2b";
//char *song = "Bond:d=4,o=5,b=80:32p,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d#6,16d#6,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d6,16c#6,16c#7,c.7,16g#6,16f#6,g#.6";
//char *song = "MASH:d=8,o=5,b=140:4a,4g,f#,g,p,f#,p,g,p,f#,p,2e.,p,f#,e,4f#,e,f#,p,e,p,4d.,p,f#,4e,d,e,p,d,p,e,p,d,p,2c#.,p,d,c#,4d,c#,d,p,e,p,4f#,p,a,p,4b,a,b,p,a,p,b,p,2a.,4p,a,b,a,4b,a,b,p,2a.,a,4f#,a,b,p,d6,p,4e.6,d6,b,p,a,p,2b";
//char *song = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
//char *song = "GoodBad:d=4,o=5,b=56:32p,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,d#,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,c#6,32a#,32d#6,32a#,32d#6,8a#.,16f#.,32f.,32d#.,c#,32a#,32d#6,32a#,32d#6,8a#.,16g#.,d#";
//char *song = "TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,d#,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,g#";
//char *song = "A-Team:d=8,o=5,b=125:4d#6,a#,2d#6,16p,g#,4a#,4d#.,p,16g,16a#,d#6,a#,f6,2d#6,16p,c#.6,16c6,16a#,g#.,2a#";
//char *song = "Flinstones:d=4,o=5,b=40:32p,16f6,16a#,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,d6,16f6,16a#.,16a#6,32g6,16f6,16a#.,32f6,32f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,a#,16a6,16d.6,16a#6,32a6,32a6,32g6,32f#6,32a6,8g6,16g6,16c.6,32a6,32a6,32g6,32g6,32f6,32e6,32g6,8f6,16f6,16a#.,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#6,16c7,8a#.6";
//char *song = "Jeopardy:d=4,o=6,b=125:c,f,c,f5,c,f,2c,c,f,c,f,a.,8g,8f,8e,8d,8c#,c,f,c,f5,c,f,2c,f.,8d,c,a#5,a5,g5,f5,p,d#,g#,d#,g#5,d#,g#,2d#,d#,g#,d#,g#,c.7,8a#,8g#,8g,8f,8e,d#,g#,d#,g#5,d#,g#,2d#,g#.,8f,d#,c#,c,p,a#5,p,g#.5,d#,g#";
//char *song = "Gadget:d=16,o=5,b=50:32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,32d#,32f,32f#,32g#,a#,d#6,4d6,32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,8d#";
//char *song = "Smurfs:d=32,o=5,b=200:4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8f#,p,8a#,p,4g#,4p,g#,p,a#,p,b,p,c6,p,4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8b,p,8f,p,4f#";
//char *song = "MahnaMahna:d=16,o=6,b=125:c#,c.,b5,8a#.5,8f.,4g#,a#,g.,4d#,8p,c#,c.,b5,8a#.5,8f.,g#.,8a#.,4g,8p,c#,c.,b5,8a#.5,8f.,4g#,f,g.,8d#.,f,g.,8d#.,f,8g,8d#.,f,8g,d#,8c,a#5,8d#.,8d#.,4d#,8d#.";
//char *song = "LeisureSuit:d=16,o=6,b=56:f.5,f#.5,g.5,g#5,32a#5,f5,g#.5,a#.5,32f5,g#5,32a#5,g#5,8c#.,a#5,32c#,a5,a#.5,c#.,32a5,a#5,32c#,d#,8e,c#.,f.,f.,f.,f.,f,32e,d#,8d,a#.5,e,32f,e,32f,c#,d#.,c#";
//char *song = "winterwrapup:d=4,o=5,b=89:2p,p,8p,8c#,8c#,8d#,8f,8c#,8d#,d#,8c#,8g#,16g#,8g#,8a#.,g#,8p,8c#,8f,8f,8f,8g#,16g#,8f,8d#.,8c#,8f,16f,8f,8f#.,c#,8p,16a#4,16c,8c#,8c#,8c#,8f,16d#,8c#,8c#.,16c#,16d#,8f,16f,8f,8f#.,d#,8p,8f#,8g#,16g#,8g#.,8g#,8g#,8f,8d#,8c#,8d#,8c#,16d#,8f,d#,8p,16p,8c#,8g#,8g#,8g#,8g#,8g#,a#,g#,16c#,8d#,8f.,8f#,8f,8c#,16f,16f#,8g#,8g#,8g#,8g#,g#,8f,g#,8c#,8d#,8f,16f#,8f,c#,8p,16p,16c#,8d#,8f.,8d#,16c#,8d#,8f.,8c#,8p,16f,16f,16f,16f,8f#,16f,c#,8p,16p,16c#,8d#,8f.,16d#,8c#,8d#,8f.,16f,c#,16p,8c#,16g#,8g#,8g#,8a#.,2g#,2p,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,8g#,16g#,16g#,8f,8g#,16f,8f.,8c#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8p,16g#,16g#,8g#,8f,8g#,8f,c#,8g#,8g#,8g#,8f,8g#,a#,g#,8c#,16d#,16d#,8f,8f#,8f,8c#,8f,8g#,8g#,8g#,8g#,g#,8f,g#,16c#,8d#,8f.,8f#,8f,c#,8p,8c#,8d#,8f,d#,8c#,8c#,8g#.,8g#.,8a#,2g#,8p,16c#,16c#,8d#,8f,8d#,8c#,8c#,8c#,8g#.,8g#.,8a#.,1g#,p,8p,16p,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,8g#,16g#,16g#,8f,8g#,16f,8f.,8c#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8p,16g#,16g#,8g#,8f,8g#,8f,c#,8g#,8g#,8g#,8f,8g#,a#,g#,16c#,8d#,8f.,8f#,8f,8c#,8f,8g#,8g#,8g#,8g#,g#,8f,g#,16c#,8d#,8f.,8f#,8f,c#,8p,16c#,8d#,8f.,8d#,16c#,8d#,8f.,8c#,8p,8f#,8f#,8f#,16f#,g#,8p,16p,16c#,8d#,8f.,8d#,16c#,8d#,8f.,f.,16c#,16f,8g#,16g#,8g#,8a#.,2g#,2p,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,8g#,16g#,16g#,8f,8g#,16f,8f.,8c#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8p,16g#,16g#,8g#,8f,8g#,8f,c#,8p,8f,8d#,8c#,8d#,16c#,8d#,8f.,c#,8f,8f,8f#,16f,8d#.,8c#,8p,8f,8f,8f,8g#.,8d#,8f.,c#,8f,16f,8d#,8c#.,c#,8c,8f,8f,8c#,16f#,16f#,8f,c#,16g#,16g#,8g#,8g#,8a#,2g#,8c,8f,8f,8c#,16f#,8f,8c#.,8g#,8a#,8g#,8g#,16f,2g#,16p,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,8g#,16g#,16g#,8f,8g#,16f,8f.,8c#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8p,16g#,16g#,8g#,8f,8g#,8f,c#,8p,8c#,8d#,8f,8d#,16c#,8d#,8f.,8c#.,16f#,8f#,16f#,8f#,8g#.,g#,8p,16c#,8d#,8f.,8f#,16f,8d#,8f.,8c#,8f#,8f#,16f,8f#,8f,c#,8p,16p,16c#,8d#,8f.,8d#,16c#,8d#,8f.,8f,8c#,8f#,16f,8f#.,8f,8g#,g#,8c#6,16c#6,16c#6,16a#,8c#.6,8a#,8d#6,c#.6,8c#6,16a#,8c#6,8d#.6,c#6,p,8c#6,16a#,8c#6,d#6,16p,8c#6,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,8g#,16g#,16g#,8f,8g#,16f,8f.,8c#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,8g#,8c#,8c#,8f,8c#,8f#,8f#,8a#,g#,16g#,16g#,8g#,8f,8g#,a#,g#,16g#,16g#,8g#,8f,8f#,f,d#,16g#,16g#,8g#,8f,8g#,c6,1c#.6";
//char *song = "rickastley:d=4,o=5,b=120:8f,a#3,g,8c4,8c,8c4,8g,a3,a,8d4,16c6,16a#,8a,8f,a#3,g,8c4,8c,8c4,8a2,a3,d3,16c,16c,16d,16f,16d4,16f,8f,a#3,g,8c4,8c,8c4,8g,a3,a,8d4,16c6,16a#,8a,8f,a#3,g,8c4,8c,8c4,8e,8f,8f,8a3,d4,16f,8f,16f,8a#2,8f3,8d,8e,8f,8f,8g,8e.,16d,c,8c4,c4,b3,8a#2,8d,8d,8e,8f,8d,8a#3,8c,16c6,8p,16p,8c6,8g,8c7,8g6,8c8,8g7,8a#2,8d,8d,8e,8f,8d,8f,8g,8c4,8e,8d,8c,c4,b3,8a#2,8d,8d,8e,8f,8d,c,8g,8g,8g,8a,g,b3,8f,8a#3,8a#2,8a#3,8a#2,8g,8a,8f,8g,8g,8g,8a,8g,8c4,8c,8c4,8a#2,8a#3,8a#2,8a#3,8d,8e,8f,8d,16c4,16p,8g,8a,g.,16c,16d,16f,16d,16a.,16p,32p,8a,16p,g.,16c,16d,16f,16d,16g.,16p,32p,8g,16p,8f.,16e,8d,16c,16d,16f,16d,f,8g,8e.,16d,8c,8c4,8c,8g,8p,2f,16c,16d,16f,16d,16a.,16p,32p,8a,16p,g.,16c,16d,16f,16d,c6,8e,8f.,16e,8d,16c,16d,16f,16d,f,8g,8e.,16d,8c,8c4,8c,8g,8p,2f";
//char *song = "megaman3intro:d=4,o=5,b=150:2c#6,8p,8f#,8a,8b,32c6,2c#6,8p,16p,32p,e6,2d#6,8p,8c#6,8b,1d6,8b,32c6,16c#.6,8a,f#,8e,f#,a,f#,a,b,32b,16c.6,8b,8a,8f#,a.,8p,32b6,16c.7,8b6,8a6,8f#6,a6,8a6,8b.6,8p,16p,8f#,8g#,8a,8b,8c#6,8e6,f#6,c#6,e6,f#6,32a6,b.6,a6,16f#.6,e6,32f6,f#6,16f.6,c#.6,8p,8e6,8f#6,8p,32c7,16c#.7,8a6,8f#6,8c#6,8f#,8g#,8a,8b,32p,8c#.6,8e6,32p,8f#6,32p,8a.6,8b6,32p,32c7,16c#.7,8b6,8a.6,8f#.6,8a.6,8g#6,16p,8c#6,32p,8f.6,8g#6,32p,8b6,32p,8c#.7,8f7,32p,16c#6,16c#6,16b,16c#6,16p,16b,16p,16c#6,16p,16b,16p,16c#6,16c#6,16p,16b,16p,16c#6,16c#6,16b,16c#6,16p,16b,16p,16c#6,16p,16b,16p,16c#6,16c#6,16p,16b,16p,16a,16f#,16g#,16a,16b,16g#,16a,16b,16c#6,16a,16b,16c#6,16e6,16d6,16c#6,16b,16g#6,16f#6,16c#6,16g#6,16f#6,16c#6,16g#6,16f#6,16c#6,16g#6,16f#6,16c#6,16g#6,16f#6,16f6,16c#6,8p,8b,8c#6,8b,8e6,8p,8d#6,8p,8b,8e6,8p,8d#6,8p,8c#6,8p,8b,8p,8b,8c#6,8b,8e6,8p,8d#6,8p,8b,8e6,8p,8d#6,8p,8c#6,8e6,g#.6,8f#6,8e6,8p,8c#6,8e6,g#.6,8f#6,8e6,8p,8d#6,8p,e6,8d#6,8c#6,8p,8c#6,8p,8b,8p,8b,8c#6,8p,2c#6,p,8c#6,8e6,8c#6,8b6,8c#6,8a6,8c#6,8g#6,8c#6,8f#6,8c#6,8e6,8f#6,8p,g#6,8e6,8c#6,8b,8c#6,8e6,8p,8g#6,8e6,8c#6,8b,8c#6,8p,8c#6,8p,8c#6,8p,8c#6,8e6,8c#6,8b6,8c#6,8a6,8c#6,8g#6,8c#6,8f#6,8c#6,8e6,f#6,8p,8g#6,8g#6,8f#6,g#6,8g#6,8f#6,8g#6,8c#7,8c#7,8b6,8c#7,8p,8b6,8c#7,p,8b,8c#6,8b,8e6,8p,8d#6,8p,8b,8e6,8p,8d#6,8p,8c#6,8p,8b,8p,8b,8c#6,8b,8e6,8p,8d#6,8p,8b,8e6,8p,8d#6,8p,8c#6,8e6,g#.6,8f#6,8e6,8p,8c#6,8e6,g#.6,8f#6,8e6,8p,8d#6,8p,e6,8d#6,8c#6,8p,8c#6,8p,8b,8p,8b,8c#6,8p,2c#6,p,8c#6,8e6,8c#6,8b6,8c#6,8a6,8c#6,8g#6,8c#6,8f#6,8c#6,8e6,8f#6,8p,g#6,8e6,8c#6,8b,8c#6,8e6,8p,8g#6,8e6,8c#6,8b,8c#6,8p,8c#6,8p,8c#6,8p,8c#6,8e6,8c#6,8b6,8c#6,8a6,8c#6,8g#6,8c#6,8f#6,8c#6,8e6,f#6,8p,8g#6,8g#6,8f#6,g#6,8g#6,8f#6,8g#6,8c#7,8c#7,8b6,8c#7,8p,8b6,8c#7,p,8b,8c#6,8b,8e6,8p,8d#6,8p,8b,8e6,8p,8d#6,8p,8c#6,8p,8b,8p,8b,8c#6,8b,8e6,8p,8d#6,8p,8b,8e6,8p,8d#6,8p,8c#6,8e6,g#.6,8f#6,8e6,8p,8c#6,8e6,g#.6,8f#6,8e6,8p,8d#6,8p,e6,8d#6,8c#6,8p,8c#6,8p,8b,8p,8b,8c#6,8p,2c#6";
char *song = "nyancat:d=4,o=5,b=90:16d#6,16e6,8f#6,8b6,16d#6,16e6,16f#6,16b6,16c#7,16d#7,16c#7,16a#6,8b6,8f#6,16d#6,16e6,8f#6,8b6,16c#7,16a#6,16b6,16c#7,16e7,16d#7,16e7,16c#7,8f#6,8g#6,16d#6,16d#6,16p,16b,16d6,16c#6,16b,16p,8b,8c#6,8d6,16d6,16c#6,16b,16c#6,16d#6,16f#6,16g#6,16d#6,16f#6,16c#6,16d#6,16b,16c#6,16b,8d#6,8f#6,16g#6,16d#6,16f#6,16c#6,16d#6,16b,16d6,16d#6,16d6,16c#6,16b,16c#6,8d6,16b,16c#6,16d#6,16f#6,16c#6,16d#6,16c#6,16b,8c#6,8b,8c#6,8f#6,8g#6,16d#6,16d#6,16p,16b,16d6,16c#6,16b,16p,8b,8c#6,8d6,16d6,16c#6,16b,16c#6,16d#6,16f#6,16g#6,16d#6,16f#6,16c#6,16d#6,16b,16c#6,16b,8d#6,8f#6,16g#6,16d#6,16f#6,16c#6,16d#6,16b,16d6,16d#6,16d6,16c#6,16b,16c#6,8d6,16b,16c#6,16d#6,16f#6,16c#6,16d#6,16c#6,16b,8c#6,8b,8c#6,8b,16f#,16g#,8b,16f#,16g#,16b,16c#6,16d#6,16b,16e6,16d#6,16e6,16f#6,8b,8b,16f#,16g#,16b,16f#,16e6,16d#6,16c#6,16b,16f#,16d#,16e,16f#,8b,16f#,16g#,8b,16f#,16g#,16b,16b,16c#6,16d#6,16b,16f#,16g#,16f#,8b,16b,16a#,16b,16f#,16g#,16b,16e6,16d#6,16e6,16f#6,8b,8a#,8b,16f#,16g#,8b,16f#,16g#,16b,16c#6,16d#6,16b,16e6,16d#6,16e6,16f#6,8b,8b,16f#,16g#,16b,16f#,16e6,16d#6,16c#6,16b,16f#,16d#,16e,16f#,8b,16f#,16g#,8b,16f#,16g#,16b,16b,16c#6,16d#6,16b,16f#,16g#,16f#,8b,16b,16a#,16b,16f#,16g#,16b,16e6,16d#6,16e6,16f#6,8b,8c#6";
//char *song = "crystalfairsong:d=4,o=5,b=112:1p,1p,1p,1p,1p,1p,1p,1p,1p,1p,16c6,16e4,16c6,16p,8c6,16g.,32p,16d6,16e4,8e6,8c6,16p,32e6,32p,16e6,16c4,16e6,16p,16e6,16p,16g6,16p,16g.6,32p,8e6,16d6,16c6,16g.4,32p,16e6,16e4,16e6,16p,16e.6,32p,16d6,16g6,16b3,16e6,8g4,16d6,16p,16e6,16p,16e6,16c4,16c6,16d.6,32p,8e.6,16d6,8c6,16p,16b3,16e4,8b,16c.6,32p,16g,8c6,8d.6,8c6,8p,8e6,8d6,16d.6,32p,16c6,16d6,16b3,8e6,16p,e6,16c6,16p,16c.6,32p,16f6,16p,16f.6,32p,16g6,16p,16g.6,32p,16d.6,32p,16c6,16p,16c6,16p,16g.,32p,8d6,8c6,8e6,8d6,8d4,p,8p,8c3,16g,16g3,16g,16e3,16e,16e3,8g,16c4,16g3,16a,16e3,16g3,32e3,32p,16d,16p,16c,16a.3,32p,16e3,16g,16a,16c6,16p,16a,16a3,16g,16e,16d,16b4,8c,16g,16g3,16g,16e3,16e,16e3,16g.,32p,16e,16g3,16g,16e3,16a,32e3,32p,8a2,16g,32c6,32p,16c6,16e3,32b,32p,32b,32p,16b.,32p,32a,32p,32a,32p,16a,16g,16d,32e3,32p,8e,16g,16g3,16g,16e3,16e,16e3,8g,16c4,16g3,16a,16e3,16g3,32e3,32p,8d,16c,16a.3,32p,16e3,16a3,32e3,32p,16c4,16p,16e3,16a3,16b2,16e3,16g3,32e3,32p,8c3,16g,16g3,16g,16e3,16g,16e3,16g,16p,16g,16g3,16g,16e3,16e,32e3,32p,8a,16c4,16a.3,32p,16e3,16g,32e3,32p,16c4,16p,16e3,16a3,16g.,32p,16b.,32p,16c.6,32p,16a,16c.6,32p,16d6,16f4,16c4,16c.6,32p,16c4,16e4,16c6,16c4,16g,16c4,16d.6,32p,16c6,16d6,16b2,16e6,16b3,16d4,8e6,16c4,16e4,16c6,16c4,16c6,16c4,16f6,16p,16e6,16d4,16f6,16a3,16g6,16a3,16d6,16p,16c6,16f4,16c6,16c4,16g,16c4,16d6,16p,16c6,16g4,16e6,16d4,16d6,16d4,8d3,16d4,16g4,16g3,16d4,16f4,16e4,8c4,16e,16p,16e,16p,16e,16p,16f,16p,16e,16p,16f.,32p,8g,8e4,8g,8g3,8c4,8c3,8c4,8g3,8c4,8f4,16f,16p,16f,16p,16f.,32p,16e.,32p,16d.,32p,16c,16p,8e,8d4,8d,8d3,16b.3,32p,8g2,8b3,8d3,8b3,8a3,8c4,16c,16p,16c,16p,16d.,32p,16c,16p,16d,16p,16e,16p,16e.,32p,8c,8g3,8c4,8c3,8c4,16e,16p,16e.,32p,16f.,32p,8e,8e3,8f,8f3,8e,8f,8e,8g4,8g,8d3,8d4,8g3,8d4,16g.,32p,16b.,32p,16c.6,32p,16a,16c6,16c3,16d6,16f4,16c4,16c.6,32p,16c4,16e4,16c6,16c4,16g,16c4,16d.6,32p,16c6,16d6,16b2,16e6,16b3,16d4,8e6,16c4,16e4,16c6,16c4,16c6,16c4,f6,8e3,8e6,g6,8a3,8g6,8d6,8c6,c3,f3,8c6,8d6,e6,d4,d6,8b3,16c.6,32p,c6,c3,g,g3,e,b2,c3,e3,d,8f3,8c,c3,16p,d,16p,2f,16p,8e,16p,8e,16p,8d,16p,e,2c";

//char *song = "";
//char *song = "";


#define isdigit(n) (n >= '0' && n <= '9')

void play_rtttl(char *p)
{
	// Absolutely no error checking in here

	printf("%s","8000 ");

	uint8_t default_dur = 4;
	uint8_t default_oct = 6;
	int bpm = 63;
	int num;
	uint32_t wholenote;
	uint32_t duration;
	uint8_t note;
	uint8_t scale;

	// format: d=N,o=N,b=NNN:
	// find the start (skip name,etc)

	while(*p != ':') p++;    // ignore name
	p++;                     // skip ':'

	// get default duration
	if(*p == 'd')
	{
		p++; p++;              // skip "d="
		num = 0;
		while(isdigit(*p))
		{
			num = (num * 10) + (*p++ - '0');
		}
		if(num > 0) default_dur = num;
		p++;                   // skip comma
	}

	//printf("ddur: "); printfln(default_dur,10);

	// get default octave
	if(*p == 'o')
	{
		p++; p++;              // skip "o="
		num = *p++ - '0';
		if(num >= 3 && num <=7) default_oct = num;
		p++;                   // skip comma
	}

	//printf("doct: "); printfln(default_oct,10);

	// get BPM
	if(*p == 'b')
	{
		p++; p++;              // skip "b="
		num = 0;
		while(isdigit(*p))
		{
			num = (num * 10) + (*p++ - '0');
		}
		bpm = num;
		p++;                   // skip colon
	}

	//printf("bpm: "); printfln(bpm,10);

	// BPM usually expresses the number of quarter notes per minute
	wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

	//printf("wn: "); printfln(wholenote,10);


	// now begin note loop
	while(*p)
	{
		// first,get note duration,if available
		num = 0;
		while(isdigit(*p))
		{
			num = (num * 10) + (*p++ - '0');
		}
		
		if(num) duration = wholenote / num;
		else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

		// now get the note
		note = 0;

		switch(*p)
		{
			case 'c':
				note = 1;
				break;
			case 'd':
				note = 3;
				break;
			case 'e':
				note = 5;
				break;
			case 'f':
				note = 6;
				break;
			case 'g':
				note = 8;
				break;
			case 'a':
				note = 10;
				break;
			case 'b':
				note = 12;
				break;
			case 'p':
			default:
				note = 0;
		}
		p++;

		// now,get optional '#' sharp
		if(*p == '#')
		{
			note++;
			p++;
		}

		// now,get optional '.' dotted note
		if(*p == '.')
		{
			duration += duration/2;
			p++;
		}
	
		// now,get scale
		if(isdigit(*p))
		{
			scale = *p - '0';
			p++;
		}
		else
		{
			scale = default_oct;
		}

		scale += OCTAVE_OFFSET;

		if(*p == ',')
			p++;       // skip comma for next note (or we may be at the end)

		// now play the note

		if(note)
		{
			printf("%d",(int) notes[(scale - 4) * 12 + note]);
			
			printf("%s"," ");

			printf("%i",(int)duration / 10);

			printf("%s"," ");

			//system("./play.sh 480 440 4");

			//tone(tonePin,notes[(scale - 4) * 12 + note]);
			//delay(duration);
			//noTone(tonePin);
		}
		else
		{
			//printf("Pausing: ");
			//printfln(duration,10);
			//delay(duration);
		}
	}
}

int main(int argc,char const *argv[])
{
	play_rtttl(song);
	return 0;
}