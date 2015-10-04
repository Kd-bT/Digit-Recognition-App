% Train neural network for MNIST dataset and write thetas to file

% Initialise
clear ; close all; clc

% Load training and test data
% Load training and test data
images = [loadMNISTImages('train-images.idx3-ubyte')'; ...
          loadMNISTImages('t10k-images.idx3-ubyte')'];
labels = [loadMNISTLabels('train-labels.idx1-ubyte'); ...
          loadMNISTLabels('t10k-labels.idx1-ubyte')];

% Map 0 to 10 in label data
labels(labels == 0) = labels(labels == 0) + 10;

% Divide data into training, cross-validation and test sets
X_train = images(1:60000, :);
X_test  = images(60001:70000, :);
y_train = labels(1:60000, :);
y_test  = labels(60001:70000, :);

% Setup dimensions for Thetas
input_layer_size  = 784;  % 20x20 Input Images of Digits
hidden_layer_size = 49;   % 25 hidden units
num_labels = 10;          % 10 labels, from 1 to 10   
                          % ("0" mapped to label 10)    
               
% Initialise Thetas with random values
Theta1 = randInitializeWeights(input_layer_size, hidden_layer_size);
Theta2 = randInitializeWeights(hidden_layer_size, num_labels);

% Train neural network
initial_nn_params = [Theta1(:); Theta2(:)];

options = optimset('MaxIter', 50);
lambda = 1;
costFunction = @(p) nnCostFunction(p, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, X_train, y_train, lambda);

fprintf('Setup complete. Press enter to begin training.\n');
pause;
                               
[nn_params, cost] = fmincg(costFunction, initial_nn_params, options);

Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Display training and test set accuracy
pred = predict(Theta1, Theta2, X_train);
fprintf('\nTraining Set Accuracy: %f\n', mean(double(pred == y_train)) * 100);

pred = predict(Theta1, Theta2, X_test);
fprintf('\nTest Set Accuracy: %f\n', mean(double(pred == y_test)) * 100);
             