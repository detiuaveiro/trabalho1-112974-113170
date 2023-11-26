clear, clc, close all

% prepare the data
x = -2:0.5:2;   
y = -2:0.5:2;   
z = -2:0.5:2; 
[X, Y, Z] = meshgrid(x, y, z);
data = X.*exp(-X.^2 - Y.^2 - Z.^2);

% plot the data
figure(1)
scatter3(X(:), Y(:), Z(:), 75, data(:), 'filled')
colormap jet
set(gca, 'FontName', 'Times New Roman', 'FontSize', 14)
xlabel('X')
ylabel('Y')
zlabel('Z')
title('A plot with 3D grid lines')

% form a 3D grid
grid3(x, y, z)

% Note: rotate the figure in order to 
% get a full notion of the 3D grid.