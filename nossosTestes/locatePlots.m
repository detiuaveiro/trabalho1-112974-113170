locate = readtable("tables/LocateTable.csv");

% blurPerfect = readtable("tables/BlurTablePERFECT.csv");

% blurBad = readtable("tables/BlurTableBAD.csv");

% addsBad = blurBad.addsOrSubs;
% numPixelsBad = blurBad.numPixelsOrig;
% figure(1)
% % plot(numPixelsBad,addsBad, 'o')
% 
% 
% addsPerfect = blurPerfect.addsOrSubs;
% numPixelsPerfect = blurPerfect.numPixelsOrig;
% figure(2)
% plot(numPixelsPerfect,addsPerfect, 'ro')



h=10000;
w=10000;
xx = logspace(0,7,500);
w2 = sqrt(xx);
h2 = w2;
%pior caso 
test = 2.*(h-h2).*1.*(w-w2).*1;

clf
% no pior caso o numero abaixo
% 2.*(h-h2).*h2.*(w-w2).*w2
%    -----
%2*(h-h2)*(w-w2)*h2*w2


figure(1)
% plot(w2.^2,test,'r');

% hold on
% plot(w2.^2,2.*1.*h2.*1.*w2)

plot(locate.numPixelsSub,locate.comparisons, 'g.', MarkerSize=20)
xlabel("Numero de pixeis da sub-imagem")
ylabel("Numero de Comparaçoes")

% hold off


%%

locate = readtable("tables/LocateTable.csv");

h = 10000;
w = 10000;
% 2*(h-h2)*(w-w2)*h2*w2
%calc all vals
Vtrue = zeros(1,300);
Va= Vtrue;
h2=linspace(1,max(locate.width2),300);
w2=linspace(1,max(locate.height2),300);
    
%V = 2.*(h-h2).*(w-w2).*h2.*w2;

Vtrue = (h-h2+1).*(w-w2+1).*(h2.*w2+1);

Va = (h-h2).*(w-w2).*h2.*w2; % supostamente da o numero de comps


figure(1)
plot(h2.*w2,Va, 'g')  
hold on

plot(locate.numPixelsSub, locate.comparisons, 'ro')

hold off
figure(2)

plot3(w2,h2,Va, 'g')
xlabel("w2")
ylabel("h2")
zlabel("va")


%%
% Define the range of values for h_2 and w_2
h_2 = linspace(0, 10000, 100);  % Adjust the number of points as needed
w_2 = linspace(0, 10000, 100);  % Adjust the number of points as needed
h = 10000;
w = 10000;
% Create a grid of values for h_2 and w_2
[h_2, w_2] = meshgrid(h_2, w_2);

% Evaluate the function for each combination of h_2 and w_2
z1= (h-h_2+1).*(w-w_2+1).*(h_2.*w_2+1);
z2 = (10000 - h_2) .* (10000 - w_2) .* h_2 .* w_2;

% Plot the function using plot3
% figure;
% plot3(h_2(:), w_2(:), z(:), 'o');
% xlabel('h_2');
% ylabel('w_2');
% zlabel('(10000 - h_2) * (10000 - w_2) * h_2 * w_2');
% title('Plot of the Function');

% Optionally, you can also add a mesh plot for better visualization
% figure;
% mesh(h_2, w_2, z2);
% xlabel('h_2');
% ylabel('w_2');
% zlabel('(10000 - h_2) * (10000 - w_2) * h_2 * w_2');
% title('Mesh Plot of the Function');
% colorbar

% acho que vou usar esta
figure;
surf(h_2, w_2, z1);
xlabel('h_2 - altura da sub-imagem');
ylabel('w_2 - comprimento da sub-imagem');
zlabel('nº de comparaçoes');
title('Grafico do numero de comparacoes em funcao das dimensoes da sub-imagem');
colorbar
% setPlotColor([1 1 1], 'k', 'k', 'k', [0.9 0.9 0.9], 'b',R 'My Plot Title', {});

