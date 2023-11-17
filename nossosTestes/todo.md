# TODO

> TESTAR FUNCOES COMO ROTATE PARA RETANGULOS

- rodei a imagem pgm/medium/airfield... guardei como apenas `ROTATE` com gwenview e O `IMAGETOOL`   GUARDEI COMO ROTATEDbyFUNCTION **FEITO** e perfeito

```bash
./imageTool pgm/medium/airfield-05_640x480.pgm rotate save  ./nossosTestes/airfieldROTATEDbyFUNCTION.pgm
cmp nossosTestes/airfield-05_640x480_ROTATED.pgm nossosTestes/airfieldROTATEDbyFUNCTION.pgm
```

> TESTAR IMAGE LOCATESUBIMAGE
- CODIGO MATLAB PARA TESTAR SE A FUNCAO ESTA CORRETA, DE NOTAR QUE AMBAS AS FUNCOES DAO O MESMO VALOR, POR ISSO ESTA TUDO CORRETO

```MATLAB
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
    disp(['A posição onde as matrizes são iguais é (' num2str(rowIndex-1) ', ' num2str(colIndex-1) ').']); % -1 PQ MATLAB NAO E 0-INDEXED

else
    disp('A matriz pequena NÃO está contida dentro da matriz maior.');
end
```

- FIZ ISTO EM BASH, o CROPPED FIZ ATOA NO GWENVIEW

```bash
./imageTool nossosTestes/airfield-05_640x480_CROPPED.pgm pgm/medium/airfield-05_640x480.pgm locate
```
