% format long
% IMAGE = imread("test/original.pgm");
% IMAGEMULT = IMAGE.*0.33;
% IMGNOSSA = imread("bri.pgm");
% 
% imwrite(IMAGE,"briMATLAB.pgm");
% 
% IMAGE2 = imread("test/bri.pgm");
% comp = sum(sum(IMAGE2==IMAGEMULT))
% compNOSSA = sum(sum(IMAGE2==IMGNOSSA))

smallMatrix = load("filecrop.txt");

bigMatrix = load("fileorig.txt"); % mudar isto



[bigRows, bigCols] = size(bigMatrix);
[smallRows, smallCols] = size(smallMatrix);


isSubmatrix = false;


rowIndex = 0;
colIndex = 0;
for i = 1 : bigRows - smallRows + 1
    for j = 1 : bigCols - smallCols + 1
        
        submatrix = bigMatrix(i:i+smallRows-1, j:j+smallCols-1);


        if isequaln(submatrix, smallMatrix)
            isSubmatrix = true;
            rowIndex = i;
            colIndex = j;
            break;
        end
    end
    if isSubmatrix
        break;
    end
end


if isSubmatrix
    disp('A matriz pequena está contida dentro da matriz maior.');
    disp(['A posição onde as matrizes são iguais é (' num2str(rowIndex-1) ', ' num2str(colIndex-1) ').']); % -1 PQ MATLAB
                                                                                                           % NAO E 0-INDEXED
else
    disp('A matriz pequena NÃO está contida dentro da matriz maior.');
end