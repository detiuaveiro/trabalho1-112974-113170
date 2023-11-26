
locate = readtable("tables/tableLocateSemLixo.csv");

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

plot(locate.numPixelsSub,locate.comparisons, '.', "Color" ,[.5 0 .5], MarkerSize=20)
xlabel("\bfNumero de pixeis da sub-imagem", "FontSize", 15)
ylabel("\bfNumero de Comparaçoes", "FontSize", 15)
title("\bf Numero de Comparaçoes efetuadas em funcao do numero de pixeis da sub-imagem", "FontSize", 18)
% xlim([min(locate.numPixelsSub) max(locate.numPixelsSub)])
grid on

% xticklabels(linspace(min(locate.numPixelsSub),max(locate.numPixelsSub),11))
% xscale(gca,"log")
% xlim max(locate.numPixelsSub) + 100000000000000])
% hold off000 

%%

locate = readtable("tables/tableLocateSemLixo.csv");

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
xlabel('\bfh_2 - altura da sub-imagem', "FontSize", 15);
ylabel('\bfw_2 - comprimento da sub-imagem', "FontSize", 15);
zlabel('\bfnumero de comparaçoes', "FontSize", 15);
title('\bfGrafico do numero de comparaçoes maximas em funcao das dimensoes da sub-imagem', "FontSize", 18);
subtitle('\bf Pior Caso')
colorbar
% setPlotColor([1 1 1], 'k', 'k', 'k', [0.9 0.9 0.9], 'b',R 'My Plot Title', {});

% exportgraphics(gcf,"worstCase.png","ContentType","vector")
figure
surf(h_2,w_2, h_2.*w_2+1)
xlabel('\bfh_2 - altura da sub-imagem', "FontSize", 15);
ylabel('\bfw_2 - comprimento da sub-imagem', "FontSize", 15);
zlabel('\bfnumero de comparaçoes', "FontSize", 15);
title('\bfGrafico do numero de comparaçoes minimas em funcao das dimensoes da sub-imagem', "FontSize", 18);
subtitle('\bf Melhor Caso')
colorbar


%%

blurBad = readtable("tables/BlurTableBADStor.csv");

% plot(blurBad.numPixelsOrig,blurBad.addsOrSubs, 'go' )
clf
% figure(1)
% x = 0:100:1000;   
% y = (0:0.2:2)*1e6;
% z = logspace(0,10,10);   
% [X, Y, Z] = meshgrid(x, y, z); 
% grid on
% 
% plot3(X(:), Y(:), Z(:),'.')
% zscale(gca,"log")
% colormap jet
% % set(gca, 'FontName', 'Times New Roman', 'FontSize', 14)
% xlabel('X')
% ylabel('Y')
% zlabel('Z')
% % title('A plot with 3D grid lines')
% % form a 3D grid
% grid3(X, Y, Z)


p1 = plot3(blurBad.dx(1:7).* blurBad.dy(1:7), blurBad.numPixelsOrig(1:7),blurBad.addsOrSubs(1:7),'r.-', 'MarkerSize', 25); % 
hold on
plot3(blurBad.dx(8:14).* blurBad.dy(8:14), blurBad.numPixelsOrig(8:14),blurBad.addsOrSubs(8:14),'r.-', 'MarkerSize', 25);


plot3(blurBad.dx(15:21).* blurBad.dy(15:21), blurBad.numPixelsOrig(15:21),blurBad.addsOrSubs(15:21),'r.-', 'MarkerSize', 25);


plot3(blurBad.dx(22:28).* blurBad.dy(22:28), blurBad.numPixelsOrig(22:28),blurBad.addsOrSubs(22:28),'r.-', 'MarkerSize', 25);




blurPerfect = readtable("tables/BlurTableStorPerfect.csv");
% plot3(blurPerfect.dx.*blurPerfect.dy,blurPerfect.numPixelsOrig, blurPerfect.addsOrSubs,".",Color=[0.5 0 0.5] ,MarkerSize=25)


p2 = plot3(blurPerfect.dx(1:7).* blurPerfect.dy(1:7), blurPerfect.numPixelsOrig(1:7),blurPerfect.addsOrSubs(1:7),'.-', 'Color', [0.5 0 0.5], 'MarkerSize', 25);

plot3(blurPerfect.dx(8:14).* blurPerfect.dy(8:14), blurPerfect.numPixelsOrig(8:14),blurPerfect.addsOrSubs(8:14),'.-', 'Color', [0.5 0 0.5], 'MarkerSize', 25);


plot3(blurPerfect.dx(15:21).* blurPerfect.dy(15:21), blurPerfect.numPixelsOrig(15:21),blurPerfect.addsOrSubs(15:21),'.-', 'Color', [0.5 0 0.5], 'MarkerSize', 25);


plot3(blurPerfect.dx(22:28).* blurPerfect.dy(22:28), blurPerfect.numPixelsOrig(22:28),blurPerfect.addsOrSubs(22:28),'.-', 'Color', [0.5 0 0.5], 'MarkerSize', 25);

grid on

xlabel("\Deltax*\Deltay", "FontSize", 15)
ylabel("Numero de pixeis da Imagem", "FontSize", 15)
zlabel("Numero de Somas/Subtraçoes", "FontSize", 15)
title("Comparaçao entre algoritmos de Blur", "FontSize", 18)
legend([p1(1), p2(1)], 'Algoritmo Lento', 'Algoritmo Rapido')
zscale(gca,"log")
% xscale(gca,"log")
% yscale(gca,"log")


% axis("manual")

hold off

%%
clf
clear
figure(1)
% fazer dos resultados teoricos
%blur good
% 7 .* h  .* w - 2 .* h - 2  .* w + 3

h = linspace(0,2000,100);
w = linspace(0,2000,100);
[h, w] = meshgrid(h,w);
z = 7 .* h  .* w - 2 .* h - 2  .* w + 3;
surf(h,w,z);
colorbar


%blur bad
% 8 .*  h.* w .*d_x.* d_y + 4.* h.* w.* d_x + 4 .*h .*w .*d_y + 3.* h
figure(2)
h = 0:20:1980;
w = 0:20:1980;
d_x = 1:2:200;
d_y = 1:2:200;
z = 8 .*  h.* w .*d_x.* d_y + 4.* h.* w.* d_x + 4 .*h .*w .*d_y + 3.* h;

plot3(h.*w, d_y.*d_x, 8 .*  h.* w .*d_x.* d_y + 4.* h.* w.* d_x + 4 .*h .*w .*d_y + 3.* h)
[hw,dxy] = meshgrid(h.*w, d_y.*d_x);
hold on
z1 = repmat(z',1,100);
surf(hw,dxy,z1)
% [X,Y,Z] = meshgrid(h.*w,d_x.*d_y, 8 .*  h.* w .*d_x.* d_y + 4.* h.* w.* d_x + 4 .*h .*w .*d_y + 3.* h);

% [d_x,d_y] = meshgrid(d_x,d_y);



% surf(h.*w,d_x.*d_y,z);
% surf(X,Y,Z)

