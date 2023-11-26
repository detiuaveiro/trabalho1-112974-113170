clear, clc, close all

% prepare the data
[X, Y, Z, data] = flow(10);

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
grid3(X, Y, Z)

% Note: rotate the figure in order to 
% get a full notion of the 3D grid.