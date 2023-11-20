locate = readtable("tables/LocateTable.csv");

blurPerfect = readtable("tables/BlurTablePERFECT.csv");

blurBad = readtable("tables/BlurTableBAD.csv");

addsBad = blurBad.addsOrSubs;
numPixelsBad = blurBad.numPixelsOrig;
figure(1)
plot(numPixelsBad,addsBad, 'o')


addsPerfect = blurPerfect.addsOrSubs;
numPixelsPerfect = blurPerfect.numPixelsOrig;
figure(2)
plot(numPixelsPerfect,addsPerfect, 'ro')