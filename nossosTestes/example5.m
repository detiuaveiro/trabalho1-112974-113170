clear, clc, close all

% prepare the data
z = -10:0.01:10;
x = exp(-z./10).*sin(5*z);
y = exp(-z./10).*cos(5*z);
plot3(x, y, z)

% plot the data
figure(1)
plot3(x, y, z, 'k', 'LineWidth', 2)
set(gca, 'FontName', 'Times New Roman', 'FontSize', 14)
xlabel('X')
ylabel('Y')
zlabel('Z')
title('A plot with 3D grid lines')

% form a 3D grid
grid3(floor(min(x)):ceil(max(x)), ...
      floor(min(y)):ceil(max(y)), ...
      floor(min(z)):ceil(max(z)))

% Note: rotate the figure in order to 
% get a full notion of the 3D grid.