clear, clc, close all

% prepare the data
[X, Y, Z] = peaks(100);

% plot the data
figure(1)
surf(X, Y, Z)
shading interp
colormap jet
set(gca, 'FontName', 'Times New Roman', 'FontSize', 14)
xlabel('X')
ylabel('Y')
zlabel('Z')
title('A plot with 3D grid lines')
alpha(0.75)

% form a 3D grid
grid3(floor(min(X(:))):ceil(max(X(:))), ...
      floor(min(Y(:))):ceil(max(Y(:))), ...
      floor(min(Z(:))):ceil(max(Z(:))))

% Note: rotate the figure in order to 
% get a full notion of the 3D grid.