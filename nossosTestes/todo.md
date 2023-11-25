# TODO

> TESTAR FUNCOES COMO ROTATE PARA RETANGULOS

- rodei a imagem pgm/medium/airfield... guardei como apenas `ROTATE` com gwenview e O `IMAGETOOL` GUARDEI COMO ROTATEDbyFUNCTION **FEITO** e perfeito

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

> **NOTA MUITO IMPORTANTE** PARA COMPARAR OS RESULTADOS COM O TAMANHO DAS IMAGENS BASTA CALCULAR W\*H PARA SABER O NUMERO TOTAL DE PIXEIS ISSO E QUE INTERESSA---> PYTHOOOON

> Decidir se uso os que começam no topo esquerdo ou no bottom right ou ambos? (acho que ambos) assim da o average case
> continuo com problemas na imglocate pq nao sei como analisar que imagens devo usar
> teoricamente eu sei que aquilo tem complexidade O(n^2) mas nao sei como fazer o teste
> **BLUR ESTA PERFEITO** ESTA LINEAR COMO SE QUERIA FALTA FAZER A ANALISE DE COMPLEXIDADE FORMAL
> **BLUR ANTIGO** VOU FAZER AGORA

| dx\*dy | small | large | medium |
| :----: | :---- | :---: | -----: |
|   3    | x     |   x   |      x |
|   7    | x     |   x   |      x |
|   9    | z     |   x   |      x |
|   11   | x     |   x   |      x |

Sum[Sum[1+Sum[Sum[1,{l,0,Subscript[h,2]-1}],{k,0,Subscript[w,2]-1}],{j,0,h-Subscript[h,2]}],{i,0,w-Subscript[w,2]}]

## **Relatorio**

### **Introdução**

### **Desenvolvimento**

- falar de analise formal de todas as 3 solucoes

- ImageLocateSubImage
  -> Colocar os somatorios

  **Notas**
  Originalmente temos isto

$$ (h-h_2+1)(w-w_2+1)(h_2 w_2 + 1) $$

- No melhor caso significa que a subimagem é encontrada logo na primeira posição da imagem original, ou seja, a complexidade é $ h_2 w_2 $ ou seja com $h_2 = w_2$ temos $O(n^2)$
- No pior caso, temos de verificar em todas as posicoes, ou seja $ (h-h_2+1)(w-w_2+1) $ e para alem disso tambem teriamos de verificar todas as subimagens $ h_2 w_2 $ com $h_2=w_2$ temos quase $O(n^4)$

$$ expansao: h_2^2 w (-w_2) + h h_2 w w_2 + h_2 w w_2 + h_2^2 (w_2)^2 - h_2^2 w_2 - h h_2 (w_2)^2 - h_2 (w_2)^2 + h h_2 w_2 + h_2 w_2$$

- Para $h_2 \text{ e } w_2$ muito proximos de metade de $h \text{ e } w$ a complexidade maximiza-se ou seja $O(n^4)$

$$
\sum_{i=0}^{w - w_2}  \sum_{j=0}^{h - h_2} \left( 1 + \sum_{k=0}^{w_2 - 1}  \sum_{l=0}^{h_2 - 1} 1  \right)


$$

$$
\sum_{i=0}^{w - w_2}  \sum_{j=0}^{h - h_2} \left( 1 + \sum_{k=0}^{w_2 - 1}  \sum_{l=0}^{h_2 - 1} 1  \right) = (h-h_2+1)(w-w_2+1)(h_2w_2+1)
$$
