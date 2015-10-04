function [ p ] = digit_nn_predict( X )
%#codegen

%DIGIT_NN_PREDICT makes a prediction on what digit X represents
%   Loads Thetas that have been precomputed from training
%   and uses them to make a prediction on X.

Thetas = coder.load('digit_nn_thetas.mat');
Theta1 = Thetas.Theta1;
Theta2 = Thetas.Theta2;
p = predict(Theta1, Theta2, X);
end